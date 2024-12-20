#ifndef SECRETKEYWIDGET_H
#define SECRETKEYWIDGET_H
#include "keywidget.h"
#include <QWidget>
#include "module_sql/sqlhandle.h"
#include <QTableWidgetItem>
namespace Ui {
class secretkeywidget;
}

class secretkeywidget : public QWidget
{
    Q_OBJECT

public:
    explicit secretkeywidget(QWidget *parent = 0);
    ~secretkeywidget();

signals:
    void send_selectPublicKey(QString text);

private slots:
    void on_toolButton_input_clicked();
    void rece_addsshKey(const sshKeyStruct & skeyStruct);

    void on_toolButton_cancel_clicked();
    
    void on_toolButton_ok_clicked();
    
    void on_tableWidget_itemSelectionChanged();

    void on_tableWidget_itemChanged(QTableWidgetItem *item);

private:
    Ui::secretkeywidget *ui;
    keywidget * kwidget;
    //操作数据库
    sqlhandle * db_;
    QString currentItem;
};

#endif // SECRETKEYWIDGET_H
