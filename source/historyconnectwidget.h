#ifndef HISTORYCONNECTWIDGET_H
#define HISTORYCONNECTWIDGET_H

#include <QWidget>
#include <QTableWidgetItem>
#include "createconnect.h"
namespace Ui {
class historyconnectwidget;
}

class historyconnectwidget : public QWidget
{
    Q_OBJECT

public:
    explicit historyconnectwidget(int8_t connectType, QVector<connnectInfoStruct> cInfoStructList, QWidget *parent = 0);
    ~historyconnectwidget();

signals:
void send_fastConnection(connnectInfoStruct &);

private slots:
    void on_tableWidget_history_itemDoubleClicked(QTableWidgetItem *item);

    void on_tableWidget_history_currentItemChanged(QTableWidgetItem *current, QTableWidgetItem *previous);

private:
    Ui::historyconnectwidget *ui;
};

#endif // HISTORYCONNECTWIDGET_H
