#ifndef HISTORYCOMMONDWIDGET_H
#define HISTORYCOMMONDWIDGET_H

#include <QWidget>

namespace Ui {
class historycommondwidget;
}

class historycommondwidget : public QWidget
{
    Q_OBJECT

public:
    explicit historycommondwidget(QWidget *parent = 0);
    ~historycommondwidget();

private:
    Ui::historycommondwidget *ui;
};

#endif // HISTORYCOMMONDWIDGET_H
