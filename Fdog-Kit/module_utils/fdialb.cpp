#include "fdialb.h"

#include <QPainter>
#include <QDebug>
FDialB::FDialB(QWidget *parent) {

}

FDialB::~FDialB() {
    
}

void FDialB::drawBg(QPainter *painter) {
   int r = radius;
   painter->save();
   /*
   painter->setPen(Qt::NoPen);
   painter->setBrush(QColor(76, 166, 74));
   //painter->drawEllipse(-r, -r, r * 2, r * 2);
   //painter->drawPie(-r, -r, r * 2, r * 2, -40 * 16, 220 * 16);


   QPainterPath path;
   path.addEllipse(-r, -r, r * 2, r * 2);
   // 创建一个底部裁剪区域
   QPainterPath cutPath;
   cutPath.addRect(-r, r * 0.6, r * 2, r * 0.8); // 底部缺口区域
   // 计算最终路径（用圆减去底部）
   path -= cutPath;
   // 绘制最终形状
   painter->drawPath(path);

   r =  radius * 0.9;
   painter->setBrush(QColor(40, 40, 40));
   painter->setPen(Qt::NoPen);
   QPainterPath path2;
   path2.addEllipse(-r, -r, r * 2, r * 2);
   // 创建一个底部裁剪区域
   QPainterPath cutPath2;
   cutPath2.addRect(-r, r * 0.6, r * 2, r * 0.8); // 底部缺口区域
   // 计算最终路径（用圆减去底部）
   path2 -= cutPath2;
   // 绘制最终形状
   painter->drawPath(path2);
   */
    painter->translate(0, r * 0.3);

    painter->setPen(QPen(QColor(230, 53, 42), 10)); // 设置弧线的宽度
    painter->setBrush(Qt::NoBrush); // 让弧线中间透明

    // 画出不完整的圆弧
    QRectF rect(-r, -r, r * 2, r * 2);
    int startAngle = -14 * 16;  // 从大约 40° 开始
    int spanAngle = 44 * 16;  // 画 280°，留下底部开口   200 - 40
    painter->drawArc(rect, startAngle, spanAngle);

    painter->setPen(QPen(QColor(220, 119, 47), 10)); // 设置弧线的宽度 
    painter->setBrush(Qt::NoBrush); // 让弧线中间透明

    // 画出不完整的圆弧
    QRectF rect2(-r, -r, r * 2, r * 2);
    startAngle = 31 * 16;  // 从大约 40° 开始
    spanAngle = 60 * 16;  // 画 280°，留下底部开口  220 - 40 - 60
    painter->drawArc(rect2, startAngle, spanAngle);

    painter->setPen(QPen(QColor(76, 166, 74), 10)); // 设置弧线的宽度
    painter->setBrush(Qt::NoBrush); // 让弧线中间透明

    // 画出不完整的圆弧
    QRectF rect3(-r, -r, r * 2, r * 2);
    startAngle = 91 * 16;  // 从大约 40° 开始
    spanAngle = 104 * 16;  // 画 280°，留下底部开口  220 - 40 - 60
    painter->drawArc(rect3, startAngle, spanAngle);

    //painter->translate(0, r * 0.4);
    r =  radius * 0.8;  // 120 * 0.8 = 96
    painter->setPen(QPen(QColor(35, 39, 46), 30)); // 设置弧线的宽度
    QRectF rect4(-r, -r, r * 2, r * 2);
    startAngle = -10 * 16;  // 从大约 40° 开始
    spanAngle = 200 * 16;  // 画 280°，留下底部开口  220 - 40 - 60
    painter->drawArc(rect4, startAngle, spanAngle);

    r =  radius * 0.78;  // 120 * 0.8 = 96
    painter->setPen(QPen(QColor(255,255,255), 30)); // 设置弧线的宽度
    QRectF rect5(-r, -r, r * 2, r * 2);
    startAngle = -10 * 16;  // 从大约 40° 开始
    spanAngle = 200 * 16;  // 画 280°，留下底部开口  220 - 40 - 60
    painter->drawArc(rect5, startAngle, spanAngle);


//    
//    painter->drawEllipse(-r, -r, r * 2, r * 2);
   painter->restore();
}

void FDialB::drawDial(QPainter *painter) {
    int r = radius*0.85;
    double lineWidth = 1;
    painter->save();

    painter->rotate(Angle);
    /*
    为什么旋转？
    如果不旋转画笔的坐标轴，那么每次画的时候需要按照角度来重新计算，x=r*cos,y=r*sin. 计算复杂
    但是如果旋转坐标轴，那么首次旋转angle角度，则y轴和第一条斜线重合，x=0，只需要计算y。
    画100条线，就是分100份来表示进度。每次旋转的角度=360-(起始角度*2--分左右)/100
    */
    double rotate = (double)(360 - (Angle * 2)) / 100;

    for (int i = 0; i <= 100; i++) {
        QColor color = QColor(84, 84, 84);
        if(i>80) color = QColor(250, 0, 0);
        if((i % 10) == 0)
        {
            painter->setPen(QPen(color, 1.3*lineWidth));
            painter->drawLine(0, r, 0, r / 1.2);
        }
        else if((i % 2) == 0)
        {
            painter->setPen(QPen(color, 1*lineWidth));
            painter->drawLine(0, r, 0, r / 1.1);
        }
        painter->rotate(rotate);
    }

    painter->restore();
}

void FDialB::drawScaleNum(QPainter *painter) {
    painter->save();

    qDebug()<< "drawText";
    int r = (int)(radius*0.6);

    painter->setFont(QFont("Arial", 10));
    painter->setPen(QPen(QColor(255,255,255)));
    QFontMetricsF fm = QFontMetricsF(painter->font());

    int gap = (360-Angle*2) / 10;
    for(int i=0; i<=10; i+=1)
    {
        int angle = 90+Angle+gap*i;  //角度,10格子画一个刻度值

        float angleArc =( angle % 360) * 3.14 / 180; //转换为弧度
        int x = (r)*cos(angleArc);
        int y = (r)*sin(angleArc);

        QString value = QString::number(i*100);
        int w = (int)fm.width(value);
        int h = (int)fm.height();
        x = x - w/2;
        y = y + h/4;

        qDebug()<< "x:"<<x<<" y:"<<y;
        //painter->drawPoint(QPointF(x, y));
        painter->drawText(QPointF(x, y),value);
    }
    painter->restore();
}

void FDialB::drawIndicator(QPainter *painter) {
    painter->save();
    QPolygon pts;
    int r = radius*0.6;
    pts.setPoints(3, -2, 0, 2, 0, 0, r);
    double degRotate =Angle +  (360.0 - Angle - Angle) / 100 * percent;

    //画指针
    painter->rotate(degRotate);
    QRadialGradient haloGradient(0, 0, 60, 0, 0);  //辐射渐变，内部填充颜色
    haloGradient.setColorAt(0, QColor(100, 100, 100));
    haloGradient.setColorAt(1, QColor(250, 50, 50)); //red
    painter->setPen(QColor(250, 150, 150)); // 边框颜色
    painter->setBrush(haloGradient);
    painter->drawConvexPolygon(pts);
    painter->restore();

    // 画中心圆圈
    QRadialGradient radial(0, 0, 14);  //渐变
    radial.setColorAt(0.0, QColor(100, 100, 100));
    radial.setColorAt(1.0, QColor(250, 50, 50));
    painter->setPen(Qt::NoPen);  //填满没有边界
    painter->setBrush(radial);
    painter->drawEllipse(-7, -7, 14, 14);

    painter->restore();
}

void FDialB::drawText(QPainter *painter) {
    painter->save();

    painter->setFont(QFont("Arial", 10));
    painter->setPen(QPen(QColor(255,255,255)));
    QFontMetricsF fm = QFontMetricsF(painter->font());
    QString speed = QString::number(percent) + " km/h";
    int w = (int)fm.width(speed);
    int h = (int)fm.height();
    painter->drawText(QPointF(-w/2, (int)(0.5*radius)),speed);
    painter->restore();
}

void FDialB::paintEvent(QPaintEvent *) {
    int width = this->width();
    int height = this->height();

    //绘制准备工作,启用反锯齿,平移坐标轴中心,等比例缩放
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.translate(width / 2, height / 2);

    int side = qMin(width, height);
    painter.scale(side / 200.0, side / 200.0);

    //绘制最外框圆形背景
    drawBg(&painter);
    // //绘制刻度
    // drawDial(&painter);
    // //绘制刻度数值
    // drawScaleNum(&painter);
    // //绘制指针
    // drawIndicator(&painter);
    // //绘制表盘上文本当前值
    // drawText(&painter);
}