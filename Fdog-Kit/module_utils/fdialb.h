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
    void FDialB::drawText(QPainter *painter);
    void FDialB::paintEvent(QPaintEvent *);
    int radius = 100;  //120
    int percent = 10;
    qreal Angle = 10;
};


#endif // FDIALB_H
