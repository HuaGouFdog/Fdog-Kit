#ifndef FINDWIDGET_H
#define FINDWIDGET_H

#include <QWidget>

namespace Ui {
class findwidget;
}

class findwidget : public QWidget
{
    Q_OBJECT

public:
    explicit findwidget(QWidget *parent = 0);
    ~findwidget();

private:
    Ui::findwidget *ui;
};

#endif // FINDWIDGET_H
