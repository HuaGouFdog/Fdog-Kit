#pragma execution_character_set("utf-8")
#include "toolswidget.h"
#include "ui_toolswidget.h"
#include <QTimer>
#include <QDateTime>
#include <QDebug>
#include <QUrl>
#include <QJsonParseError>
#include <QXmlStreamReader>
#include <QGraphicsDropShadowEffect>
#include <QCryptographicHash>
#include <QThread>
#include <QClipboard>
#include <QElapsedTimer>
#include "module_utils/utils.h"
#include <QAction>
toolswidget::toolswidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::toolswidget)
{
    ui->setupUi(this);
    setSupportStretch(this, true);
    ui->textEdit->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    // QGraphicsDropShadowEffect *effect = new QGraphicsDropShadowEffect(this);
    // effect->setOffset(2, 0);          //设置向哪个方向产生阴影效果(dx,dy)，特别地，(0,0)代表向四周发散
    // effect->setColor(QColor(25, 51, 81));       //设置阴影颜色，也可以setColor(QColor(220,220,220))
    // effect->setBlurRadius(20);        //设定阴影的模糊半径，数值越大越模糊

    // ui->widget_left->setGraphicsEffect(effect);
    //QAction *action = new QAction(this);
    //action->setIcon(QIcon(":/lib/soucuo.png").pixmap(QSize(50, 50)));
    //ui->lineEdit_find->addAction(action,QLineEdit::LeadingPosition);
}

toolswidget::toolswidget(int8_t connectType, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::toolswidget)
{
    ui->setupUi(this);
    setSupportStretch(this, true);
    ui->textEdit->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->stackedWidget->setCurrentIndex(connectType - 1);
    QAction *action = new QAction(this);
    action->setIcon(QIcon(":/lib/soucuo.png"));
    ui->lineEdit_find->addAction(action,QLineEdit::LeadingPosition);

    QGraphicsDropShadowEffect *effect = new QGraphicsDropShadowEffect(this);
    effect->setOffset(2, 0);          //设置向哪个方向产生阴影效果(dx,dy)，特别地，(0,0)代表向四周发散
    effect->setColor(QColor(25, 51, 81));       //设置阴影颜色，也可以setColor(QColor(220,220,220))
    effect->setBlurRadius(20);        //设定阴影的模糊半径，数值越大越模糊

    ui->widget_left->setGraphicsEffect(effect);
}

toolswidget::~toolswidget()
{
    delete ui;
}

// void toolswidget::on_textEdit_json_source_textChanged()
// {
//     ui->textEdit_json_target->clear();
//     utils_parsingJsonInfo(ui->textEdit_json_target, ui->plainTextEdit_json_source->toPlainText());
// }

void formatXml(const QString& xmlData) {
    QXmlStreamReader xmlReader(xmlData);
    QString result;
    int indentLevel = 0;

    while (!xmlReader.atEnd() && !xmlReader.hasError()) {
        QXmlStreamReader::TokenType token = xmlReader.readNext();
        if (token == QXmlStreamReader::StartElement) {
            result.append(QString(indentLevel * 4, ' ') + "<" + xmlReader.name().toString());

            QXmlStreamAttributes attributes = xmlReader.attributes();
            for (const QXmlStreamAttribute& attribute : attributes) {
                result.append(" " + attribute.name().toString() + "=\"" + attribute.value().toString() + "\"");
            }

            if (xmlReader.isEndElement() && xmlReader.isWhitespace()) {
                result.append("/>\n");
            } else {
                result.append(">\n");
                indentLevel++;
            }
        } else if (token == QXmlStreamReader::Characters && !xmlReader.isWhitespace()) {
            result.append(QString((indentLevel + 1) * 4, ' ') + xmlReader.text().toString().trimmed() + "\n");
        } else if (token == QXmlStreamReader::EndElement) {
            indentLevel--;
            result.append(QString(indentLevel * 4, ' ') + "</" + xmlReader.name().toString() + ">\n");
        }
    }

    if (xmlReader.hasError()) {
        // 解析XML时发生错误处理
        result.append("XML parsing error: " + xmlReader.errorString() + "\n");
    }

    qDebug().noquote() << result;
}


void toolswidget::on_textEdit_xml_source_textChanged()
{
    //QString xmlData = "<sites><site><name>RUNOOB</name><url>www.runoob.com</url></site></sites>";

    //QXmlStreamReader xmlReader(ui->textEdit_xml_source->toPlainText());
    formatXml(ui->textEdit_xml_source->toPlainText());

}

void toolswidget::on_plainTextEdit_json_source_textChanged()
{
    ui->textEdit_json_target->clear();
    utils_parsingJsonInfo(ui->textEdit_json_target, ui->plainTextEdit_json_source->toPlainText());
}

void toolswidget::on_toolButton_25_clicked()
{
    //ui->textEdit->setLineWrapMode(QTextEdit::FixedPixelWidth);
    //ui->textEdit->setLineWrapColumnOrWidth(50);
    //ui->textEdit->setUndoRedoEnabled(false);
    //ui->textEdit->document ()->setMaximumBlockCount(50);
    int sum = ui->lineEdit_2->text().toInt();
    QString a = ui->lineEdit->text();
    int j = 0;
    QString aSum;

    QTextCursor cursor_s = ui->textEdit->textCursor();
    cursor_s.beginEditBlock();
    for(int i =0; i<sum; i++) {
        j++;
        cursor_s.insertText("05/11/24 22:16:06.825.398 [140703302276864] INFO  root  "\
                        "[/data/badword/badword/badword/badwordservicehandler.cpp:414]- getBadwordinfo=getBadword_end&size=0\n");
        //qDebug() << "打印" << a;
        //QThread::msleep(1000);
    }
    cursor_s.endEditBlock();
}

void toolswidget::on_textEdit_textChanged()
{
    // 获取文本编辑框的视口大小
    QSize viewportSize = ui->textEdit->viewport()->size();

    // 获取字体的行高和字符宽度
    QFontMetrics metrics(ui->textEdit->font());
    int lineHeight = metrics.lineSpacing();
    int charWidth = metrics.averageCharWidth();
    qDebug() << "字体 高 = " << lineHeight;
    qDebug() << "字体 宽 = " << charWidth;
    qDebug() << "视图 高 = " << viewportSize.height();
    qDebug() << "视图 宽 = " << viewportSize.width();

//    // 检查垂直滚动条的可见性
    //bool isScrollBarVisible = textEdit_s->verticalScrollBar()->isVisible();
    // 显示垂直滚动条的可见性状态
    //qDebug() << "Vertical Scrollbar Visible:" << isScrollBarVisible;

    // 计算可见行数和列数
    int visibleLines = viewportSize.height() / lineHeight - 1;
    int visibleColumns = viewportSize.width() / charWidth - 5;
    qDebug() << "可见行数 = " << visibleLines;
    qDebug() << "可见列数 = " << visibleColumns;
}


void toolswidget::on_toolButton_encipher_clicked()
{
    QString str = ui->plainTextEdit_data->toPlainText();
    QString md5Str = QCryptographicHash::hash(str.toLatin1(),QCryptographicHash::Md5).toHex();
    ui->plainTextEdit_32Lower->setPlainText(md5Str);
    ui->plainTextEdit_32->setPlainText(md5Str.toUpper());

    QString md5Str16 = md5Str.mid(8, 16);//md5Str.left(16);
    ui->plainTextEdit_16Lower->setPlainText(md5Str16);
    ui->plainTextEdit_16->setPlainText(md5Str16.toUpper());
}

void toolswidget::on_toolButton_clear_clicked()
{
    ui->plainTextEdit_data->clear();
    ui->plainTextEdit_32Lower->clear();
    ui->plainTextEdit_32->clear();
    ui->plainTextEdit_16Lower->clear();
    ui->plainTextEdit_16->clear();
}

void toolswidget::on_toolButton_32Lower_10_clicked()
{
    on_toolButton_encipher_clicked();
    QClipboard *clipboard = QApplication::clipboard();
    clipboard->setText(ui->plainTextEdit_32Lower->toPlainText().left(10));
}

void toolswidget::on_toolButton_32_10_clicked()
{
    on_toolButton_encipher_clicked();
    QClipboard *clipboard = QApplication::clipboard();
    clipboard->setText(ui->plainTextEdit_32->toPlainText().left(10));
}

void toolswidget::on_toolButton_16Lower_10_clicked()
{
    on_toolButton_encipher_clicked();

    QClipboard *clipboard = QApplication::clipboard();
    clipboard->setText(ui->plainTextEdit_16Lower->toPlainText().left(10));
}

void toolswidget::on_toolButton_16_10_clicked()
{
    on_toolButton_encipher_clicked();

    QClipboard *clipboard = QApplication::clipboard();
    clipboard->setText(ui->plainTextEdit_16->toPlainText().left(10));
}

void toolswidget::on_verticalScrollBar_valueChanged(int value)
{
    ui->textEdit->verticalScrollBar()->setValue(value);
}

void toolswidget::on_toolButton_2_clicked()
{
    QElapsedTimer timer;
    timer.start();
    QTextCursor cursor_s = ui->textEdit->textCursor();
    cursor_s.beginEditBlock();
    QString a = "05/11/24 22:16:06.825.398 [140703302276864] INFO  root  "\
                "[/data/badword/badword/badword/badwordservicehandler.cpp:414]- getBadwordinfo=getBadword_end&size=0\n";
    QString sum;
    int j =0;
    for(int i =0; i<500; i++) {
        if (j > 5) {
            cursor_s.insertText(sum);
            j=0;
            sum = "";
        } else {
            sum =sum + a;
            j++;
        }

        //ui->textEdit->insertHtml("05/11/24 22:16:06.825.398 [140703302276864] INFO  root  "\
        //                         "[/data/badword/badword/badword/badwordservicehandler.cpp:414]- getBadwordinfo=getBadword_end&size=0\n");
        qDebug() << i;
    }
    cursor_s.endEditBlock();
    //on_toolButton_clicked();
    qint64 elapsedMilliseconds = timer.elapsed();
    qDebug() << "响应时间：" + QString::number(elapsedMilliseconds) + "ms";
    ui->verticalScrollBar->setMaximum(ui->textEdit->verticalScrollBar()->maximum());
}
