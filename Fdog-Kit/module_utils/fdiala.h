#ifndef FDIALA_H
#define FDIALA_H

#include <QObject>
#include <QWidget>
#include <QPainter>
class FDialA : public QWidget
{
    Q_OBJECT
public:
    FDialA(QWidget *parent = nullptr);
    ~FDialA();
    void FDialA::drawBg(QPainter *painter);
    void FDialA::drawDial(QPainter *painter);
    void FDialA::drawScaleNum(QPainter *painter);
    void FDialA::drawIndicator(QPainter *painter);
    void FDialA::drawText(QPainter *painter);
    void FDialA::paintEvent(QPaintEvent *);
    int radius = 80;
    int percent = 10;
    qreal Angle = 10;
};


#endif // FDIALA_H
