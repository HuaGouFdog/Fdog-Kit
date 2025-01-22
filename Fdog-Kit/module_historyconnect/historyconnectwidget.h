#ifndef HISTORYCONNECTWIDGET_H
#define HISTORYCONNECTWIDGET_H

#include <QWidget>
#include <QTableWidgetItem>
#include "module_connect/createconnect.h"
#include "module_config/config.h"
namespace Ui {
class historyconnectwidget;
}

class historyconnectwidget : public QWidget
{
    Q_OBJECT

public:
    explicit historyconnectwidget(int8_t connectType, QVector<connnectInfoStruct> cInfoStructList, config * confInfo, QWidget *parent = 0);
    ~historyconnectwidget();

    void loadSSHinfoList(QVector<connnectInfoStruct> cInfoStructList);
    void loadSSHinfo(connnectInfoStruct cInfoStruct);

    createconnect *ccwidget =nullptr;           //创建连接窗口
    config * confInfo; //这个应该同步更新
    QWidget *parent_;
    QStringList dataSource;
signals:
void send_fastConnection(connnectInfoStruct &);
void send_findConnection(QString text, int type = 0); //默认就是名称匹配

private slots:
    void on_tableWidget_history_itemDoubleClicked(QTableWidgetItem *item);

    void on_tableWidget_history_currentItemChanged(QTableWidgetItem *current, QTableWidgetItem *previous);

    void rece_activated(const QString & text);

    void rece_highlighted(const QString & text);

    void on_toolButton_create_clicked();

    void rece_newConnnect(connnectInfoStruct& cInfoStruct);

    void rece_newSave(connnectInfoStruct& cInfoStruct);

private:
    Ui::historyconnectwidget *ui;
};

#endif // HISTORYCONNECTWIDGET_H
