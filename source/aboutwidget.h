#ifndef ABOUTWIDGET_H
#define ABOUTWIDGET_H

#include <QWidget>

namespace Ui {
class aboutwidget;
}

class aboutwidget : public QWidget
{
    Q_OBJECT

public:
    explicit aboutwidget(QWidget *parent = 0);
    ~aboutwidget();

private:
    Ui::aboutwidget *ui;
};

#endif // ABOUTWIDGET_H
