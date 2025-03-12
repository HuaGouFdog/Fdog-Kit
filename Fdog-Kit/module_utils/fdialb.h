#ifndef FDIALB_H
#define FDIALB_H

#include <QObject>
#include <QWidget>
#include <QPainter>
class FDialB : public QWidget
{
    Q_OBJECT
public:
    FDialB(QWidget *parent = nullptr);
    ~FDialB();
    void FDialB::drawBg(QPainter *painter);
    void FDialB::drawDial(QPainter *painter);
    void FDialB::drawScaleNum(QPainter *painter);
    void FDialB::drawIndicator(QPainter *painter);
    void FDialB::drawIndicator2(QPainter *painter);
    void FDialB::drawText(QPainter *painter);
    void FDialB::paintEvent(QPaintEvent *);
    void FDialB::valueChanged(int value);
    int radius = 100;  //120
    int percent = 0;
    qreal Angle = 10;
    int du = (2.1*(100)) + 1;
};


#endif // FDIALB_H
