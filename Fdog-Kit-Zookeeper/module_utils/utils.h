#ifndef UTILS_H
#define UTILS_H
#define UNUSED(x) (void)(x)
#include <QObject>
#include <QCheckBox>
#include <QLabel>
#include <QGraphicsDropShadowEffect>
#include <QTextEdit>
#include <QItemDelegate>

#include <QHBoxLayout>
#include <QStyledItemDelegate>
#include <QTableWidget>
#include <QSpacerItem>

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

void setSupportStretch(QWidget * this_, bool isSupportStretch);

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

#endif // UTILS_H


