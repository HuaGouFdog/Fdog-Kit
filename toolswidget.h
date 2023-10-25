#ifndef TOOLSWIDGET_H
#define TOOLSWIDGET_H

#include <QWidget>

namespace Ui {
class toolswidget;
}

class toolswidget : public QWidget
{
    Q_OBJECT

public:
    explicit toolswidget(QWidget *parent = 0);
    ~toolswidget();

public slots:

private slots:


private:
    Ui::toolswidget *ui;
};

#endif // TOOLSWIDGET_H
