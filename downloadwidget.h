#ifndef DOWNLOADWIDGET_H
#define DOWNLOADWIDGET_H

#include <QWidget>

namespace Ui {
class downloadwidget;
}

class downloadwidget : public QWidget
{
    Q_OBJECT

public:
    explicit downloadwidget(QWidget *parent = 0);
    ~downloadwidget();

private:
    Ui::downloadwidget *ui;
};

#endif // DOWNLOADWIDGET_H
