#ifndef CREATECONNECT_H
#define CREATECONNECT_H

#include <QWidget>
#include "createconnect.h"
#define SSH_CONNECT_TYPE 1
#define ZK_CONNECT_TYPE 2
#define REDIS_CONNECT_TYPE 3
#define KAFKA_CONNECT_TYPE 4
#define DB_CONNECT_TYPE 5
struct connnectInfoStruct
{
    int8_t connectType;
    QString name;
    QString group;
    QString host;
    QString port;
    QString password;
    bool isSavePassword;
};

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

    void on_toolButton_zk_connect_clicked();

    void on_toolButton_zk_close_clicked();

    void on_toolButton_ssh_connect_clicked();

    void on_toolButton_ssh_close_clicked();

    void on_widget_bottom_toolButton_connect_clicked();

    void on_widget_bottom_toolButton_close_clicked();

    void on_tab_passowrd_toolButton_show_clicked();

private:
    Ui::createconnect *ui;
    int8_t connectType = 0;
    bool isShowPassword = false;  //是否显示密码
};

#endif // CREATECONNECT_H
