#ifndef ADDCOMMONDWIDGET_H
#define ADDCOMMONDWIDGET_H

#include <QWidget>

namespace Ui {
class addcommondwidget;
}

class addcommondwidget : public QWidget
{
    Q_OBJECT

public:
    explicit addcommondwidget(QWidget *parent = 0);
    ~addcommondwidget();

private:
    Ui::addcommondwidget *ui;
};

#endif // ADDCOMMONDWIDGET_H
