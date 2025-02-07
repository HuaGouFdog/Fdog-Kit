#pragma execution_character_set("utf-8")
#include "utils.h"
#include <QStyle>
#include <QLabel>
#include <QMouseEvent>
#include <QApplication>
#include <QPropertyAnimation>
#include <QGraphicsDropShadowEffect>
#include <QDebug>

#include <QMimeData>
#include <QJsonDocument>
#include <QJsonParseError>
#include <QKeyEvent>
#include <QJsonObject>
#include <QJsonArray>
#include <QHBoxLayout>
#include <QSpacerItem>

#include <QPainter>

bool signalReceived = false;
bool signalReceived2 = false;

HoveredRowItemDelegate::HoveredRowItemDelegate(QTableWidget *parent)
    : QStyledItemDelegate{parent}
{
    tableWidget = parent;
}

void HoveredRowItemDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    //选中状态或是在鼠标下方的状态
    if(option.state.testFlag(QStyle::State_Selected) || option.state.testFlag(QStyle::State_MouseOver))
    {
        QTableWidgetItem *hoveredItem = tableWidget->item(index.row(), index.column());
        if(hoveredItem)
        {
            const int row = hoveredItem->row();
            //遍历列，绘制此行的所有列
            for(int column = 0; column < tableWidget->columnCount(); column++)
            {
                QTableWidgetItem *item = tableWidget->item(row, column);
                if(item)
                {
                    QModelIndex index = tableWidget->model()->index(row, column);
                    QStyleOptionViewItem itemOption = option;
                    itemOption.index = index;
                    itemOption.rect = tableWidget->visualItemRect(item);
                    QStyledItemDelegate::paint(painter, itemOption, index);
                }
            }
        }
    }
    else
    {
        return QStyledItemDelegate::paint(painter, option, index);
    }
}


AnimatedCheckBox::AnimatedCheckBox(bool isChecked, QWidget *parent) : QCheckBox (parent)
{
    indicator = new QLabel(this);
    /* 设置样式 */
    this->setMinimumHeight(22);
    this->setAttribute(Qt::WA_StyledBackground, true);
    this->setProperty("class", "AnimatedCheckBox");
    indicator->setProperty("class", "AnimatedCheckBoxIndicator");

    // this->setStyleSheet(QString(".AnimatedCheckBox[checked=true ]\
    // {\
    //     background: #1e2d36;\
    //     border-radius: %1px;\
    // }\
    // .AnimatedCheckBox[checked=false ]\
    // {\
    //      background: #c5c8ce;\
    //      border-radius: %1px;\
    // }\
    // .AnimatedCheckBoxIndicator\
    // {\
    //     background: white;\
    //     border-radius: %2px;\
    // }").arg(this->height() / 2).arg(indicator->height() / 2));
    this->setContentsMargins(3, 2, 3, 2);
//    QPropertyAnimation *animation = new QPropertyAnimation(indicator, "pos", this);
//    int b = this->contentsMargins().left();
//    int x = this->isChecked() ? this->width() - indicator->width() - b : b;
//    int y = b;
//    animation->stop();
//    animation->setDuration(200);
//    animation->setEndValue(QPoint(x + 22, y));
//    animation->setEasingCurve(QEasingCurve::InOutCubic);
//    animation->start();

//    this->style()->polish(this);


    QPropertyAnimation *animation = new QPropertyAnimation(indicator, "pos", this);
    connect(this, &QCheckBox::toggled, [=] {
        int b = this->contentsMargins().left();
        int x = this->isChecked() ? this->width() - indicator->width() - b : b;
        int y = b;
        animation->stop();
        animation->setDuration(200);
        animation->setEndValue(QPoint(x, y));
        animation->setEasingCurve(QEasingCurve::InOutCubic);
        animation->start();

        this->style()->polish(this);
    });
    if (isChecked) {
        this->setChecked(isChecked);
            //QPropertyAnimation *animation = new QPropertyAnimation(indicator, "pos", this);
            int b = this->contentsMargins().left();
            int x = this->isChecked() ? this->width() - indicator->width() - b : b;
            int y = b;
            animation->stop();
            animation->setDuration(10);
            animation->setEndValue(QPoint(x + 28, y));
            animation->setEasingCurve(QEasingCurve::InOutCubic);
            animation->start();

            this->style()->polish(this);
    }

}

/* 重写 paintEvent 方法，清除 QCheckBox 的默认样式 */
void AnimatedCheckBox::paintEvent(QPaintEvent *) {
}

/* AnimatedCheckBox 的大小改变时调整 indicator 的位置 */
void AnimatedCheckBox::resizeEvent(QResizeEvent *)
{
    /* 设置 AnimatedCheckBox 的最小宽度，避免太窄的时候效果不好 */
    this->setMinimumWidth(height() * 2);

    this->setContentsMargins(3, 2, 3, 2);
    int b = this->contentsMargins().left();
    int x = this->isChecked() ? this->width() - indicator->width() - b : b;
    int y = b;
    int w = height() - b - b;
    int h = w;
    //qDebug() << "x = " << x;

    indicator->setGeometry(x,y,w,h);

    this->setStyleSheet(QString(".AnimatedCheckBox[checked=true ]\
    {\
        background: #1e2d36;\
        border-radius: %1px;\
    }\
    .AnimatedCheckBox[checked=false ]\
    {\
         background: #c5c8ce;\
         border-radius: %1px;\
    }\
    .AnimatedCheckBoxIndicator\
    {\
        background: white;\
        border-radius: %2px;\
    }").arg(this->height() / 2).arg(indicator->height() / 2));
    QGraphicsDropShadowEffect *effect = new QGraphicsDropShadowEffect(this);
    effect->setBlurRadius(10);
    effect->setOffset(0, 1);
    indicator->setGraphicsEffect(effect);
}

/* 点击 AnimatedCheckBox 上的任何地方都切换选中状态，QCheckBox 默认只有点击它的 indicator 或者文字时才进行切换 */
void AnimatedCheckBox::mousePressEvent(QMouseEvent *event)
{
    //event->accept();
    setChecked(!isChecked());
}

utils::utils(QWidget *parent) : QWidget(parent)
{

}

QString getStyleFile(QString path)
{
    //qDebug() << "getStyleFile";
    QFile file(path);
    QString styleSheet;
    /* 判断文件是否存在 */
    if (file.exists() ) {
        /* 以只读的方式打开 */
        file.open(QFile::ReadOnly);
        /* 以字符串的方式保存读出的结果 */
        styleSheet = QLatin1String(file.readAll());
        /* 关闭文件 */
        file.close();
    }
    //qDebug() << styleSheet;
    return styleSheet;
}


parsingJsonTextEdit::parsingJsonTextEdit(QWidget *parent)
    : QTextEdit(parent)
{
//    setReadOnly(true);
    // QFont font;
    // font.setPixelSize(28);
    // this->setFont(font);
}
 
void parsingJsonTextEdit::parsingJsonInfo(QString & jsonString)
{
    //clear();
    QJsonParseError err;
 
    QJsonDocument jsonDocument = QJsonDocument::fromJson(jsonString.toUtf8(),&err);
    if(jsonDocument.isNull())
    {
        //append(err.errorString());
        //qDebug() << "错误提示" << err.errorString();
        return;
    }
 
    if(jsonDocument.isObject())
    {
        QJsonObject jsonObject = jsonDocument.object();
        parsingJsonObject(jsonObject,1);
    }
    else if(jsonDocument.isArray())
    {
        QJsonArray array = jsonDocument.array();
        parsingJsonArray(array,1);
    }
}
 
void parsingJsonTextEdit::insertFromMimeData(const QMimeData *source)
{
    if (source->hasText())
    {
        QString str = source->text().trimmed();
        parsingJsonInfo(str);
    }
    else
    {
        QTextEdit::insertFromMimeData(source);
    }
}
 
void parsingJsonTextEdit::parsingJsonObject(QJsonObject &object,const int numberOfLayers)//参数2：层数
{
    int nextLayers = numberOfLayers + 1;
 
    QString spacing;
    for (int i = 0; i < numberOfLayers; ++i)
    {
        spacing.append("    ");
    }
    QString spacingBeforeBrackets;
    int spacingBeforeBracketsCount = numberOfLayers - 1;
    for (int i = 0; i < spacingBeforeBracketsCount; ++i)
    {
        spacingBeforeBrackets.append("    ");
    }
    spacingBeforeBrackets.append("{");
 
    append(spacingBeforeBrackets);
    int index = 1;
    QString endingSymbol;
    int objectLent = object.length();
    for (QJsonObject::const_iterator it = object.constBegin(); it != object.constEnd(); ++it)
    {
        if(index < objectLent)
            endingSymbol = QStringLiteral(",");
        else
            endingSymbol = QStringLiteral("");
 
        const QJsonValue & value = it.value();
        if(value.isString())
        {
            QString str = value.toString();
            QJsonDocument jsonDocument = QJsonDocument::fromJson(str.toUtf8());
            if(jsonDocument.isNull())
            {
                append(QString("<span style='white-space:pre;color:#9C278F;'>%1\"%2\"</span>:<span style='color:#54B54A;'>\"%3\"</span>%4").arg(spacing).arg(it.key()).arg(str).arg(endingSymbol));
            }
            else if(jsonDocument.isObject())
            {
                append(QString("<span style='white-space:pre;color:#9C278F;'>%1\"%2\"</span>:").arg(spacing).arg(it.key()));
                QJsonObject obj = jsonDocument.object();
                parsingJsonObject(obj,nextLayers);
            }
            else if(jsonDocument.isArray())
            {
                append(QString("<span style='white-space:pre;color:#9C278F;'>%1\"%2\"</span>:").arg(spacing).arg(it.key()));
                QJsonArray arr = jsonDocument.array();
                parsingJsonArray(arr,nextLayers);
            }
        }
        else if(value.isDouble())
        {
            append(QString("<span style='white-space:pre;color:#9C278F;'>%1\"%2\"</span>:<span style='color:#128BF1;'>%3</span>%4").arg(spacing).arg(it.key()).arg(value.toDouble()).arg(endingSymbol));
        }
        else if(value.isBool())
        {
            if(value.toBool())
            {
                append(QString("<span style='white-space:pre;color:#9C278F;'>%1\"%2\"</span>:true%3").arg(spacing).arg(it.key()).arg(endingSymbol));
            }
            else
            {
                append(QString("<span style='white-space:pre;color:#9C278F;'>%1\"%2\"</span>:false%3").arg(spacing).arg(it.key()).arg(endingSymbol));
            }
        }
        else if(value.isObject())
        {
            append(QString("<span style='white-space:pre;color:#9C278F;'>%1\"%2\"</span>:").arg(spacing).arg(it.key()));
            QJsonObject obj = value.toObject();
            parsingJsonObject(obj,nextLayers);
        }
        else if(value.isArray())
        {
            append(QString("<span style='white-space:pre;color:#9C278F;'>%1\"%2\"</span>:").arg(spacing).arg(it.key()));
            QJsonArray arr = value.toArray();
            parsingJsonArray(arr,nextLayers);
        }
        else
        {
            append(QString("<span style='white-space:pre;color:#9C278F;'>%1\"%2\"</span>:<span style='color:#128BF1;'>%3</span>%4").arg(spacing).arg(it.key()).arg(value.toInt()).arg(endingSymbol));
        }
        ++index;
    }
    spacingBeforeBrackets.replace("{","}");
    append(spacingBeforeBrackets);
}
 
void parsingJsonTextEdit::parsingJsonArray(QJsonArray &array,const int numberOfLayers)
{
    int nextLayers = numberOfLayers + 1;
 
    QString spacing;
    for (int i = 0; i < numberOfLayers; ++i)
    {
        spacing.append("    ");
    }
    QString spacingBeforeBrackets;
    int spacingBeforeBracketsCount = numberOfLayers - 1;
    for (int i = 0; i < spacingBeforeBracketsCount; ++i)
    {
        spacingBeforeBrackets.append("    ");
    }
    spacingBeforeBrackets.append("[");
 
    append(spacingBeforeBrackets);
 
    int index = 1;
    QString endingSymbol;
    int arrayLent = array.size();
 
    for(int i = 0;i < array.size();++i)
    {
        if(index < arrayLent)
            endingSymbol = QStringLiteral(",");
        else
            endingSymbol = QStringLiteral("");
 
        QJsonValueRef ref = array[i];
        QJsonValue::Type jsonValueType = ref.type();
        if(jsonValueType == QJsonValue::String)
        {
            QString str = ref.toString();
            QJsonDocument jsonDocument = QJsonDocument::fromJson(str.toUtf8());
            if(jsonDocument.isNull())
            {
                append(QString("<span style='white-space:pre;color:#54B54A;'>%1\"%2\"</span>%3").arg(spacing).arg(str).arg(endingSymbol));
            }
            else if(jsonDocument.isObject())
            {
                QJsonObject obj = jsonDocument.object();
                parsingJsonObject(obj,nextLayers);
            }
            else if(jsonDocument.isArray())
            {
                QJsonArray arr = jsonDocument.array();
                parsingJsonArray(arr,nextLayers);
            }
        }
        else if(jsonValueType == QJsonValue::Bool)
        {
            if(ref.toBool())
            {
                append(QString("%1true%2").arg(spacing).arg(endingSymbol));
            }
            else
            {
                append(QString("%1false%2").arg(spacing).arg(endingSymbol));
            }
        }
        else if(jsonValueType == QJsonValue::Double)
        {
            append(QString("<span style='white-space:pre;color:#128BF1;'>%1%2</span>%3").arg(spacing).arg(ref.toDouble()).arg(endingSymbol));
        }
        else if(jsonValueType == QJsonValue::Array)
        {
            QJsonArray arr = ref.toArray();
            parsingJsonArray(arr,nextLayers);
        }
        else if(jsonValueType == QJsonValue::Object)
        {
            QJsonObject obj = ref.toObject();
            parsingJsonObject(obj,nextLayers);
        }
        else
        {
            append(QString("<span style='white-space:pre;color:#128BF1;'>%1%2</span>%3").arg(spacing).arg(ref.toInt()).arg(endingSymbol));
        }
    }
    spacingBeforeBrackets.replace("[","]");
    append(spacingBeforeBrackets);
}
 
void parsingJsonTextEdit::keyPressEvent(QKeyEvent * e)
{
    int keyNumber = e->key();
    // if(keyNumber != Qt::Key_Delete && keyNumber != Qt::Key_Backspace)
    // {
    //     return;
    // }
    QTextEdit::keyPressEvent(e);
    QString str = this->toPlainText().trimmed();
    parsingJsonInfo(str);
}

void getGraphicsEffectUtils(QWidget * widget, int x, int y, int radius)
{
    //根据widget自身背景颜色获取color
    QPalette palette = widget->palette();
    QColor backgroundColor = palette.color(QPalette::Background);
    QGraphicsDropShadowEffect *effect = new QGraphicsDropShadowEffect();
    effect->setOffset(x, y);            //设置向哪个方向产生阴影效果(dx,dy)，(0,0)代表向四周发散
    effect->setColor(backgroundColor);            //设置阴影颜色
    effect->setBlurRadius(radius);      //设定阴影的模糊半径，数值越大越模糊
    widget->setGraphicsEffect(effect);
}

void getGraphicsEffectUtils(QWidget * widget, int x, int y, int radius, QColor &color)
{
    QGraphicsDropShadowEffect *effect = new QGraphicsDropShadowEffect();
    effect->setOffset(x, y);            //设置向哪个方向产生阴影效果(dx,dy)，(0,0)代表向四周发散
    effect->setColor(color);            //设置阴影颜色
    effect->setBlurRadius(radius);      //设定阴影的模糊半径，数值越大越模糊
    widget->setGraphicsEffect(effect);
}


void utils_parsingJsonInfo(QTextEdit * textEdit, QString &jsonString, bool isSuper) {
    //clear();
    QJsonParseError err;
    qDebug() << "utils_parsingJsonInfo isSuper = " << isSuper;
    QJsonDocument jsonDocument = QJsonDocument::fromJson(jsonString.toUtf8(),&err);
    if(jsonDocument.isNull())
    {
        textEdit->append(err.errorString());
        //qDebug() << "错误提示" << err.errorString();
        return;
    }
 
    if(jsonDocument.isObject())
    {
        QJsonObject jsonObject = jsonDocument.object();
        utils_parsingJsonObject(textEdit, jsonObject, 1, isSuper);
    }
    else if(jsonDocument.isArray())
    {
        QJsonArray array = jsonDocument.array();
        utils_parsingJsonArray(textEdit, array,1, isSuper);
    }
}

void utils_parsingJsonObject(QTextEdit * textEdit, QJsonObject &object, const int numberOfLayers, bool isSuper) {
    int nextLayers = numberOfLayers + 1;
 
    QString spacing;
    for (int i = 0; i < numberOfLayers; ++i)
    {
        spacing.append("    ");
    }
    QString spacingBeforeBrackets;
    int spacingBeforeBracketsCount = numberOfLayers - 1;
    for (int i = 0; i < spacingBeforeBracketsCount; ++i)
    {
        spacingBeforeBrackets.append("    ");
    }
    spacingBeforeBrackets.append("{");
 
    textEdit->append(spacingBeforeBrackets);
    int index = 1;
    QString endingSymbol;
    int objectLent = object.length();
    for (QJsonObject::const_iterator it = object.constBegin(); it != object.constEnd(); ++it)
    {
        //qDebug() << "it.key() = " << it.key() << " objectLent = " << objectLent << " index = " << index;
        if(index < objectLent)
            endingSymbol = QStringLiteral(",");
        else
            endingSymbol = QStringLiteral("");
 
        const QJsonValue & value = it.value();
        if(value.isString())
        {
            QString str = value.toString();
            qDebug() << "isSuper = " << isSuper;
            if (isSuper) {
                QJsonDocument jsonDocument = QJsonDocument::fromJson(str.toUtf8());
                if(jsonDocument.isNull())
                {
                    textEdit->append(QString("<span style='white-space:pre;color:#9C278F;'>%1\"%2\"</span>:<span style='color:#54B54A;'>\"%3\"</span>%4").arg(spacing).arg(it.key()).arg(str).arg(endingSymbol));
                }
                else if(jsonDocument.isObject())
                {
                    textEdit->append(QString("<span style='white-space:pre;color:#9C278F;'>%1\"%2\"</span>:").arg(spacing).arg(it.key()));
                    QJsonObject obj = jsonDocument.object();
                    utils_parsingJsonObject(textEdit,obj,nextLayers);
                }
                else if(jsonDocument.isArray())
                {
                    textEdit->append(QString("<span style='white-space:pre;color:#9C278F;'>%1\"%2\"</span>:").arg(spacing).arg(it.key()));
                    QJsonArray arr = jsonDocument.array();
                    utils_parsingJsonArray(textEdit,arr,nextLayers);
                }
            } else {
                str = str.replace("\"","\\\"");
                textEdit->append(QString("<span style='white-space:pre;color:#9C278F;'>%1\"%2\"</span>:<span style='color:#54B54A;'>\"%3\"</span>%4").arg(spacing).arg(it.key()).arg(str).arg(endingSymbol));
            }
            

        }
        else if(value.isDouble())
        {
            qDebug() << "value = " << value;
            QString obj = QString("%1").arg(value.toDouble(), 0, 'f', 9);
            qDebug() << "obj = " << obj;
            qDebug() << "强制转换" << static_cast<int64_t>(value.toDouble()) << "  string = " << value.toString();;

            //QString obj = value.toString();
            //qDebug() << "obj = " << obj;
            //判断倒数9位有没有非零，如果都是零，显示整数
            if (!containsNonZeroDigit(obj.mid(obj.length() - 10))) {
                //全是0
                obj = obj.mid(0,obj.length()- 10);
            }
            qDebug() << "obj2 = " << obj;
            textEdit->append(QString("<span style='white-space:pre;color:#9C278F;'>%1\"%2\"</span>:<span style='color:#128BF1;'>%3</span>%4").arg(spacing).arg(it.key()).arg(obj).arg(endingSymbol));
        }
        else if(value.isBool())
        {
            if(value.toBool())
            {
                textEdit->append(QString("<span style='white-space:pre;color:#9C278F;'>%1\"%2\"</span>:true%3").arg(spacing).arg(it.key()).arg(endingSymbol));
            }
            else
            {
                textEdit->append(QString("<span style='white-space:pre;color:#9C278F;'>%1\"%2\"</span>:false%3").arg(spacing).arg(it.key()).arg(endingSymbol));
            }
        }
        else if(value.isObject())
        {
            textEdit->append(QString("<span style='white-space:pre;color:#9C278F;'>%1\"%2\"</span>:").arg(spacing).arg(it.key()));
            QJsonObject obj = value.toObject();
            utils_parsingJsonObject(textEdit,obj,nextLayers, isSuper);
            if(index < objectLent) {
                endingSymbol = QStringLiteral(",");
                textEdit->insertPlainText(endingSymbol);
            }
        } else if(value.isArray())
        {
            textEdit->append(QString("<span style='white-space:pre;color:#9C278F;'>%1\"%2\"</span>:").arg(spacing).arg(it.key()));
            QJsonArray arr = value.toArray();
            utils_parsingJsonArray(textEdit,arr,nextLayers, isSuper);
            if(index < objectLent) {
                endingSymbol = QStringLiteral(",");
                textEdit->insertPlainText(endingSymbol);
            }
        }
        else
        {
            textEdit->append(QString("<span style='white-space:pre;color:#9C278F;'>%1\"%2\"</span>:<span style='color:#128BF1;'>%3</span>%4").arg(spacing).arg(it.key()).arg(value.toInt()).arg(endingSymbol));
        }
        ++index;
    }
    spacingBeforeBrackets.replace("{","}");
    textEdit->append(spacingBeforeBrackets);
}

void utils_parsingJsonArray(QTextEdit * textEdit, QJsonArray &array,const int numberOfLayers, bool isSuper) {
    int nextLayers = numberOfLayers + 1;
 
    QString spacing;
    for (int i = 0; i < numberOfLayers; ++i)
    {
        spacing.append("    ");
    }
    QString spacingBeforeBrackets;
    int spacingBeforeBracketsCount = numberOfLayers - 1;
    for (int i = 0; i < spacingBeforeBracketsCount; ++i)
    {
        spacingBeforeBrackets.append("    ");
    }
    spacingBeforeBrackets.append("[");
 
    textEdit->append(spacingBeforeBrackets);
 
    int index = 1;
    QString endingSymbol;
    int arrayLent = array.size();
 
    for(int i = 0;i < array.size();++i)
    {
        if(index < arrayLent)
            endingSymbol = QStringLiteral(",");
        else
            endingSymbol = QStringLiteral("");
 
        QJsonValueRef ref = array[i];
        QJsonValue::Type jsonValueType = ref.type();
        if(jsonValueType == QJsonValue::String)
        {
            QString str = ref.toString();
            if (isSuper) {
                QJsonDocument jsonDocument = QJsonDocument::fromJson(str.toUtf8());
                if(jsonDocument.isNull()) {
                    textEdit->append(QString("<span style='white-space:pre;color:#54B54A;'>%1\"%2\"</span>%3").arg(spacing).arg(str).arg(endingSymbol));
                } else if(jsonDocument.isObject()) {
                    QJsonObject obj = jsonDocument.object();
                    utils_parsingJsonObject(textEdit,obj,nextLayers, isSuper);
                } else if(jsonDocument.isArray()) {
                    QJsonArray arr = jsonDocument.array();
                    utils_parsingJsonArray(textEdit,arr,nextLayers, isSuper);
                }
            } else {
                str = str.replace("\"","\\\"");
                textEdit->append(QString("<span style='white-space:pre;color:#54B54A;'>%1\"%2\"</span>%3").arg(spacing).arg(str).arg(endingSymbol));
            }
        }
        else if(jsonValueType == QJsonValue::Bool)
        {
            if(ref.toBool())
            {
                textEdit->append(QString("%1true%2").arg(spacing).arg(endingSymbol));
            }
            else
            {
                textEdit->append(QString("%1false%2").arg(spacing).arg(endingSymbol));
            }
        }
        else if(jsonValueType == QJsonValue::Double)
        {
            QString obj = QString("%1").arg(ref.toDouble(), 0, 'f', 9);
            //QString obj = ref.toString();
            //qDebug() << "obj = " << obj;
            //判断倒数9位有没有非零，如果都是零，显示整数
            if (!containsNonZeroDigit(obj.mid(obj.length()-10))) {
                //全是0
                obj = obj.mid(0, obj.length()- 10);
            }
            //qDebug() << "obj2 = " << obj;
            textEdit->append(QString("<span style='white-space:pre;color:#128BF1;'>%1%2</span>%3").arg(spacing).arg(obj).arg(endingSymbol));
        }
        else if(jsonValueType == QJsonValue::Array)
        {
            QJsonArray arr = ref.toArray();
            utils_parsingJsonArray(textEdit,arr,nextLayers, isSuper);
            if(index < arrayLent) {
                endingSymbol = QStringLiteral(",");
                textEdit->insertPlainText(endingSymbol);
            }
        }
        else if(jsonValueType == QJsonValue::Object)
        {
            QJsonObject obj = ref.toObject();
            utils_parsingJsonObject(textEdit,obj,nextLayers, isSuper);
            if(index < arrayLent) {
                endingSymbol = QStringLiteral(",");
                textEdit->insertPlainText(endingSymbol);
            }
        }
        else
        {
            textEdit->append(QString("<span style='white-space:pre;color:#128BF1;'>%1%2</span>%3").arg(spacing).arg(ref.toInt()).arg(endingSymbol));
        }
        ++index;
    }
    spacingBeforeBrackets.replace("[","]");
    textEdit->append(spacingBeforeBrackets);
}

bool containsNonZeroDigit(const QString &str) {
    int sum =0;
    for (const QChar &ch : str) {
        if (ch.isDigit() && ch != '0') {
            qDebug() << "char = " << ch;
            return true; // 如果找到非零数字，返回true
        }
    }
    return false; // 如果字符串中没有非零数字，返回false
}

void CoutCharacterEncoding(QString str) {
    for (int i = 0; i < str.length(); ++i) {
        ushort unicode = str.at(i).unicode();
        qDebug() << "Character: " << str.at(i) << " Unicode: " << unicode;
    }    
}

void getNonnullString(QString text, int & start, int & end) {
    text.replace(QChar(0xA0), ' ');
    // 向前查找空格字符或行首
    for (start; 
         start >= 0 && text.mid(start, 1) != " " && text.mid(start, 1) != "\r\n" &&
         text.mid(start, 1) != "\n" && text.mid(start, 1).at(0).unicode() != 0x2028; 
         start--)
    {
    }
    // 向后查找空格字符或行尾
    for (end; 
         end < text.length() && text.mid(end, 1) != " " && text.mid(end, 1) != "\n" &&
         text.mid(end, 1).at(0).unicode() != 0x2028; 
         end++)
    {
    }

}
void setSupportStretch(QWidget * this_, bool isSupportStretch) {
    // 因为需要在鼠标未按下的情况下通过mouseMoveEvent事件捕捉鼠标位置，所以需要设置setMouseTracking为true（如果窗口支持拉伸）;
    this_->setMouseTracking(isSupportStretch);
    // 这里对子控件也进行了设置，是因为如果不对子控件设置，当鼠标移动到子控件上时，不会发送mouseMoveEvent事件，也就获取不到当前鼠标位置，无法判断鼠标状态及显示样式了。
    QList<QWidget*> widgetList = this_->findChildren<QWidget*>();
    for(int i = 0; i < widgetList.length(); i ++) {
        widgetList[i]->setMouseTracking(isSupportStretch);
    }   
}


QFMessageBox::QFMessageBox(QWidget *parent, QString message, int showType, bool isSuccess)
{
    setWindowFlags(Qt::FramelessWindowHint | Qt::NoDropShadowWindowHint);
    setAttribute(Qt::WA_TranslucentBackground, true);
    setFocusPolicy(Qt::NoFocus);
    this->setParent(parent);

    ql_icon = new QLabel();
    ql_test = new QLabel(message);
    ql_test->setAlignment(Qt::AlignCenter);
    //ql_icon->setStyleSheet("background-color: rgb(156, 0, 200);");
    //ql_test->setStyleSheet("background-color: rgb(55, 200, 55);");
    hl = new QHBoxLayout();
    hlw = new QHBoxLayout();
    hs1 = new QSpacerItem(15,20);
    hs2 = new QSpacerItem(15,20);
    hl->addSpacerItem(hs1);
    hl->addWidget(ql_icon);
    hl->addWidget(ql_test);
    hl->addSpacerItem(hs2);
    w = new QWidget(this);

    w->setLayout(hl);
    hl->setContentsMargins(0,0,0,0);
    hl->setSpacing(0);
    hlw->addWidget(w);

    this->setLayout(hlw);
    hlw->setContentsMargins(5,5,5,5);
    this->setMaximumHeight(50);
    this->setMaximumWidth(150);

    //this->resize(120, 40);

    w->setStyleSheet("background-color: rgb(27, 27, 27); border-radius: 10px;color: rgb(255, 255, 255);font: 10pt \"OPPOSans B\";");
    //this->setStyleSheet("background-color: rgba(0, 0, 0, 0);");

    if (isSuccess) {
        ql_icon->setStyleSheet("image: url(:/lib/green.svg);");
    } else {
        ql_icon->setStyleSheet("image: url(:/lib/grey.svg);");
    }
    setSupportStretch(this, true);
}

QFMessageBox::~QFMessageBox()
{
    delete ql_icon;
    delete ql_test;
    delete hl;
    delete w;
    delete hlw;
}

//void setSupportStretch(void *this_, bool isSupportStretch)
//{
//    // 因为需要在鼠标未按下的情况下通过mouseMoveEvent事件捕捉鼠标位置，所以需要设置setMouseTracking为true（如果窗口支持拉伸）;
//    QWidget * a = static_cast<QWidget *>(this_);
//    a->setMouseTracking(isSupportStretch);
//    // 这里对子控件也进行了设置，是因为如果不对子控件设置，当鼠标移动到子控件上时，不会发送mouseMoveEvent事件，也就获取不到当前鼠标位置，无法判断鼠标状态及显示样式了。
//    QList<QWidget*> widgetList = a->findChildren<QWidget*>();
//    for(int i = 0; i < widgetList.length(); i ++) {
//        widgetList[i]->setMouseTracking(isSupportStretch);
//    }
//}
