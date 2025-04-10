#ifndef HISTORYCOMMONDWIDGET_H
#define HISTORYCOMMONDWIDGET_H

#include <QWidget>
#include <QListWidgetItem>
#include "QEvent"
namespace Ui {
class historycommondwidget;
}

class historycommondwidget : public QWidget
{
    Q_OBJECT

public:
    explicit historycommondwidget(QWidget *parent = 0);
    ~historycommondwidget();

    void addCommand(QString command);

    void leaveEvent(QEvent *event);

signals:
    void send_commond(QString command);

private slots:
    void on_listWidget_itemDoubleClicked(QListWidgetItem *item);

private:
    Ui::historycommondwidget *ui;
};

#endif // HISTORYCOMMONDWIDGET_H
