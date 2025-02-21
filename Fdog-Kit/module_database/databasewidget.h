#ifndef DATABASEWIDGET_H
#define DATABASEWIDGET_H

#include <QWidget>

namespace Ui {
class databasewidget;
}

class databasewidget : public QWidget
{
    Q_OBJECT

public:
    explicit databasewidget(QWidget *parent = nullptr);
    ~databasewidget();

private:
    Ui::databasewidget *ui;
};

#endif // DATABASEWIDGET_H
