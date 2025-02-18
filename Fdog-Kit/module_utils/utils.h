#ifndef UTILS_H
#define UTILS_H
#define UNUSED(x) (void)(x)
#include <QObject>
#include <QCheckBox>
#include <QLabel>
#include <QGraphicsDropShadowEffect>
#include <QTextEdit>
#include <QItemDelegate>
#include <QMouseEvent>
#include <QHBoxLayout>
#include <QStyledItemDelegate>
#include <QTableWidget>
#include <QSpacerItem>
#include <QEvent>
#include <QDebug>
#define LIGHT_THEME 0  //浅色主题
#define DARK_THEME  1   //暗黑主题
#define BLUE_THEME  2   //蓝色主题

struct SSHINFO {
    QString name;
    QString ip;
    QString password;
    QString ssh_group;
    QString remark;
    QString nearest_connection;
};

struct sshKeyStruct {
    QString name;
    QString path;
    QString password;
};

struct connnectInfoStruct {
    int8_t connectType;
    QString name;
    QString group;
    QString host;
    QString port;
    QString userName;
    QString password; //可能是密码，也可能是私钥密码
    QString remark;
    QString nearest_connection;
    //登录方式 1密码 2公钥
    QString sshType;
    QString publicKeyName;
    QString publickey; //公钥地址
    bool isSavePassword;
    int8_t buttonSid;
    int timeout;
};

struct zkInfoStruct {
    QString name;
    QString host;
    QString port;
};

//解决鼠标滑过QTableWidget，样式表不是整行的问题
class HoveredRowItemDelegate : public QStyledItemDelegate
{
public:
    explicit HoveredRowItemDelegate(QTableWidget *parent = nullptr);

protected:
    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const override;

private:
    const QTableWidget *tableWidget{};
};

class ComboBoxDelegate : public QItemDelegate
{
public:
    explicit ComboBoxDelegate(QObject * parent = nullptr) : QItemDelegate(parent) {}
    ~ComboBoxDelegate() = default;

    QSize sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const override
    {
        QSize size = QItemDelegate::sizeHint(option, index);
        size.setHeight(22);
        return size;
    }
};

//这个是为了跟踪鼠标，及时切换样式
class TreeWidgetFilter :public QObject {
    Q_OBJECT
public:
    explicit TreeWidgetFilter(QObject *parent = nullptr) : QObject(parent) {}

signals:
void send_updateMouseStyle();

protected:
    bool eventFilter(QObject *watched, QEvent *event) override
    {
        // 处理 QTreeWidget 的鼠标移动事件
        //qDebug() << "eventFilter = " << event->type();
        if (event->type() == QEvent::HoverMove) {
            //更新样式
            emit send_updateMouseStyle();
            // QMouseEvent *mouseEvent = static_cast<QMouseEvent *>(event);
            // QPoint pos = mouseEvent->pos();
            // qDebug() << "Mouse moved at:" << pos;
            // 返回 false，表示继续传递事件
            return false;  // 返回 true 会阻止事件传递，false 继续传递
        }
        // 对于其他事件，正常处理
        return QObject::eventFilter(watched, event);
    }
};



//开关组件
class AnimatedCheckBox : public QCheckBox
{
public:
    AnimatedCheckBox(bool isChecked = false, QWidget *parent = nullptr);
protected:
    void paintEvent(QPaintEvent *event) override;
    void resizeEvent(QResizeEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;

private:
    /* AnimatedCheckBox 是否选中的指示器
        checked 为 false 时 indicator 在最左边，为 true 时 indicator 在最右边 */
    QLabel *indicator;
};

//json格式化，调用utils_parsingJsonInfo即可
void utils_parsingJsonInfo(QTextEdit * textEdit, QString &jsonString, bool isSuper = false);
void utils_parsingJsonObject(QTextEdit * textEdit, QJsonObject &object, const int numberOfLayers, bool isSuper = false);
void utils_parsingJsonArray(QTextEdit * textEdit, QJsonArray &array,const int numberOfLayers, bool isSuper = false);


//通用设置阴影
//根据自身背景值设置阴影颜色
void getGraphicsEffectUtils(QWidget * widget, int x, int y, int radius);
//根据入参设置阴影颜色
void getGraphicsEffectUtils(QWidget * widget, int x, int y, int radius, QColor &color);


//判断有没有非零数
bool containsNonZeroDigit(const QString &str);

//打印字符串字符编码
void CoutCharacterEncoding(QString str);

//获取非空字符串起点和结尾
void getNonnullString(QString text, int & start, int & end);

//遍历控件添加鼠标事件
void setSupportStretch(QWidget * this_, bool isSupportStretch);

//void setSupportStretch(void * this_, bool isSupportStretch);

//获取样式表
QString getStyleFile(QString path);

//通知框，保存，新增，删除等提示
class QFMessageBox : public QWidget
{
    Q_OBJECT
public:
    explicit QFMessageBox(QWidget *parent = nullptr, QString message = "", int showType = 0, bool isSuccess = 1);
    ~QFMessageBox();
signals:

public slots:

private:
    QLabel * ql_icon;
    QLabel * ql_test;
    QHBoxLayout * hl;
    QHBoxLayout * hlw;
    QSpacerItem * hs1;
    QSpacerItem * hs2;
    QWidget * w;
};




class utils : public QWidget
{
    Q_OBJECT
public:
    explicit utils(QWidget *parent = nullptr);

signals:

public slots:
};

class parsingJsonTextEdit : public QTextEdit
{
    Q_OBJECT
public:
    parsingJsonTextEdit(QWidget * parent = nullptr);
    void parsingJsonInfo(QString &jsonString);
    void parsingJsonObject(QJsonObject &object, const int numberOfLayers);
    void parsingJsonArray(QJsonArray &array,const int numberOfLayers);
protected:
    void insertFromMimeData( const QMimeData *source)override;
    void keyPressEvent(QKeyEvent * e)override;
};

class WidgetMouseFilter : public QObject
{
   Q_OBJECT
public:
   WidgetMouseFilter(QObject *parent = nullptr) : QObject(parent) {}

protected:
    bool eventFilter(QObject *object, QEvent *event) {
        if (object->isWidgetType()) {
            QWidget *widget = static_cast<QWidget*>(object);
            if (event->type() == QEvent::Enter) {
                // 当鼠标进入widget时增加宽度
                widget->resize(widget->width() + 10, widget->height());
                widget->resize(widget->width(), widget->height() + 10);
            } else if (event->type() == QEvent::Leave) {
                // 当鼠标离开widget时还原宽度
                widget->resize(widget->width() - 10, widget->height());
                widget->resize(widget->width(), widget->height() - 10);
            }
        }
        // 继续传递事件
        return false;
    }
};

#endif // UTILS_H


