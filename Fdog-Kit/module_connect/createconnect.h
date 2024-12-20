#ifndef CREATECONNECT_H
#define CREATECONNECT_H

#include <QWidget>
#include "createconnect.h"
#include "secretkeywidget.h"
#include "module_utils/utils.h"
#include "module_sql/sqlhandle.h"
#define SSH_CONNECT_TYPE 1
#define WINDOWS_CONNECT_TYPE 2
#define ZK_CONNECT_TYPE 3
#define REDIS_CONNECT_TYPE 4
#define KAFKA_CONNECT_TYPE 5
#define DB_CONNECT_TYPE 6

#define SSH_PASSWORD  "1"
#define SSH_PUBLICKEY  "2"




namespace Ui {
class createconnect;
}

class createconnect : public QWidget
{
    Q_OBJECT

public:
    explicit createconnect(int8_t connectType, QWidget *parent = 0);
    ~createconnect();

signals:
    void newCreate(connnectInfoStruct &);
    void newClose();

private slots:
    void closeEvent(QCloseEvent *event);

    void on_widget_bottom_toolButton_connect_clicked();

    void on_widget_bottom_toolButton_close_clicked();

    void on_tab_passowrd_toolButton_show_clicked();

    void on_toolButton_browse_clicked();

    void on_lineEdit_host_ssh_data_textChanged(const QString &arg1);

    void on_widget_name_lineEdit_name_data_textEdited(const QString &arg1);

    void on_tabWidget_currentChanged(int index);

    void rece_selectPublicKey(QString text);

private:
    Ui::createconnect *ui;
    int8_t connectType = 0;
    bool isShowPassword = false;  //是否显示密码
    secretkeywidget * skwidget = NULL;  //密钥
    bool isEditName = false;
    //操作数据库
    sqlhandle * db_;
};

#endif // CREATECONNECT_H
