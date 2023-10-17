#ifndef SECRETKEYWIDGET_H
#define SECRETKEYWIDGET_H

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

private:
    Ui::secretkeywidget *ui;
};

#endif // SECRETKEYWIDGET_H
