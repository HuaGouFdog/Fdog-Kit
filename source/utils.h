#ifndef UTILS_H
#define UTILS_H

#include <QObject>
#include <QCheckBox>
#include <QLabel>
#include <QGraphicsDropShadowEffect>
#include <QTextEdit>

#define UNUSED(x) (void)(x)

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

//通用设置阴影

//根据自身背景值设置阴影颜色
void getGraphicsEffectUtils(QWidget * widget, int x, int y, int radius);
//根据入参设置阴影颜色
void getGraphicsEffectUtils(QWidget * widget, int x, int y, int radius, QColor &color);




class utils : public QWidget
{
    Q_OBJECT
public:
    explicit utils(QWidget *parent = nullptr);

signals:

public slots:
};

    QString getStyleFile(QString path);

#endif // UTILS_H
