#ifndef ACTIVATE_H
#define ACTIVATE_H

#include <QWidget>
#include "module_mainwindow/mainwindow.h"
#include<QTimer>


namespace Ui {
class Activate;
}

extern bool signalReceived;
extern bool signalReceived2;
class Activate : public QWidget
{
    Q_OBJECT

public:
    explicit Activate(config * confInfo, QWidget *parent = 0);
    ~Activate();

private slots:
    void updateBarValue();

    void on_toolButton_close_clicked();

    void on_toolButton_run_clicked();

private:
    Ui::Activate *ui;
    QTimer *m_timer;
    config * confInfo;
    int m_value;
};

#endif // ACTIVATE_H
