#ifndef HISTORYCONNECTWIDGET_H
#define HISTORYCONNECTWIDGET_H

#include <QWidget>
#include <QTableWidgetItem>
namespace Ui {
class historyconnectwidget;
}

class historyconnectwidget : public QWidget
{
    Q_OBJECT

public:
    explicit historyconnectwidget(int8_t connectType, QWidget *parent = 0);
    ~historyconnectwidget();

private slots:
    void on_tableWidget_history_itemDoubleClicked(QTableWidgetItem *item);

private:
    Ui::historyconnectwidget *ui;
};

#endif // HISTORYCONNECTWIDGET_H
