#pragma execution_character_set("utf-8")
#include "utils.h"
#include <QStyle>
#include <QLabel>
#include <QMouseEvent>
#include <QApplication>
#include <QPropertyAnimation>
#include <QGraphicsDropShadowEffect>
#include <QDebug>
AnimatedCheckBox::AnimatedCheckBox(bool isChecked, QWidget *parent) : QCheckBox (parent)
{
    indicator = new QLabel(this);

    /* 设置样式 */
    this->setMinimumHeight(22);
    this->setAttribute(Qt::WA_StyledBackground, true);
    this->setProperty("class", "AnimatedCheckBox");
    indicator->setProperty("class", "AnimatedCheckBoxIndicator");

    this->setStyleSheet(".AnimatedCheckBox[checked=true ]\
    {\
        background: #1e2d36;\
    }\
    .AnimatedCheckBox[checked=false]\
    {\
         background: #c5c8ce;\
    }\
    .AnimatedCheckBoxIndicator\
    {\
        background: white;\
    }");

    this->setContentsMargins(3, 2, 3, 2);
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
}

/* 重写 paintEvent 方法，清除 QCheckBox 的默认样式 */
void AnimatedCheckBox::paintEvent(QPaintEvent *) {}

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
    qDebug() << "点击";
    event->accept();
    setChecked(!isChecked());
}

utils::utils(QWidget *parent) : QWidget(parent)
{

}
