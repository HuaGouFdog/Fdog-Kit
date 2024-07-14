#ifndef SECRETKEYWIDGET_H
#define SECRETKEYWIDGET_H
#include "keywidget.h"
#include <QWidget>

namespace Ui {
class secretkeywidget;
}

class secretkeywidget : public QWidget
{
    Q_OBJECT

public:
    explicit secretkeywidget(QWidget *parent = 0);
    ~secretkeywidget();

private slots:
    void on_toolButton_input_clicked();
    void rece_addsshKey(sshKeyStruct & skeyStruct);

private:
    Ui::secretkeywidget *ui;
    keywidget * kwidget;
};

#endif // SECRETKEYWIDGET_H
