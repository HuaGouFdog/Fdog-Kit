#ifndef SETTINGWIDGET_H
#define SETTINGWIDGET_H

#include <QWidget>

namespace Ui {
class settingwidget;
}

class settingwidget : public QWidget
{
    Q_OBJECT

public:
    explicit settingwidget(QWidget *parent = 0);
    ~settingwidget();

private:
    Ui::settingwidget *ui;
};

#endif // SETTINGWIDGET_H
