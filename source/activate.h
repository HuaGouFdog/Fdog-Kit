#ifndef ACTIVATE_H
#define ACTIVATE_H

#include <QWidget>
#include "mainwindow.h"
#include<QTimer>


namespace Ui {
class Activate;
}

extern bool signalReceived;

class Activate : public QWidget
{
    Q_OBJECT

public:
    explicit Activate(QWidget *parent = 0);
    ~Activate();

private slots:
    void updateBarValue();

private:
    Ui::Activate *ui;
    QTimer *m_timer;
    int m_value;
};

#endif // ACTIVATE_H
