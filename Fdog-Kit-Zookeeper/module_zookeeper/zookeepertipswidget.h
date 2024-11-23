#ifndef ZOOKEEPERTIPSWIDGET_H
#define ZOOKEEPERTIPSWIDGET_H

#include <QWidget>

namespace Ui {
class zookeepertipswidget;
}

class zookeepertipswidget : public QWidget
{
    Q_OBJECT

public:
    explicit zookeepertipswidget(QWidget *parent = 0, QString message = "", bool isSuccess = true);
    ~zookeepertipswidget();

private:
    Ui::zookeepertipswidget *ui;
};

#endif // ZOOKEEPERTIPSWIDGET_H
