#ifndef MKDIRFOLDERWIDGET_H
#define MKDIRFOLDERWIDGET_H

#include <QWidget>

namespace Ui {
class mkdirfolderwidget;
}

class mkdirfolderwidget : public QWidget
{
    Q_OBJECT

public:
    explicit mkdirfolderwidget(QWidget *parent = 0);
    ~mkdirfolderwidget();

private:
    Ui::mkdirfolderwidget *ui;
};

#endif // MKDIRFOLDERWIDGET_H
