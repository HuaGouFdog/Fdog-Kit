﻿#pragma execution_character_set("utf-8")
#include "createconnect.h"
#include "ui_createconnect.h"
#include "secretkeywidget.h"
#include <QMovie>
#include <QDateTime>
#include <QDebug>
#include <QTextCodec>
#include <QListView>
createconnect::createconnect(int8_t connectType, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::createconnect)
{
    ui->setupUi(this);
    ui->comboBox->setView(new QListView());

    //只显示关闭按钮
    setWindowFlags(Qt::WindowCloseButtonHint);
    //选择显示的连接类型
    this->connectType = connectType;
    //setWindowTitle("新建终端");
    if (connectType == SSH_CONNECT_TYPE) {
        ui->tabWidget->setCurrentIndex(connectType - 1);
        setWindowTitle("新建ssh连接");
    } else if (connectType == ZK_CONNECT_TYPE) {
        ui->tabWidget->setCurrentIndex(connectType - 1);
        setWindowTitle("新建zookeeper连接");
    } else if (connectType == DB_CONNECT_TYPE) {
        ui->tabWidget->setCurrentIndex(connectType - 1);
        setWindowTitle("新建database连接");
    } else if (connectType == REDIS_CONNECT_TYPE) {
        ui->tabWidget->setCurrentIndex(connectType - 1);
        setWindowTitle("新建redis连接");
    } else if (connectType == KAFKA_CONNECT_TYPE) {
        ui->tabWidget->setCurrentIndex(connectType - 1);
        setWindowTitle("新建kafka连接");
    }
}

createconnect::~createconnect()
{
    if (db != nullptr) {
        delete db;
    }
    delete ui;
}

void createconnect::closeEvent(QCloseEvent *event)
{
    emit newClose();
    this->close();
}

void createconnect::on_widget_bottom_toolButton_connect_clicked()
{
    //创建选择的连接信息
    connnectInfoStruct cInfo;
    if (ui->tabWidget->currentIndex() == 0) {
        if (db == nullptr) {
            db = new sshsql();
        }
        cInfo.connectType = 1;//this->connectType;
        cInfo.name = ui->widget_name_lineEdit_name_data->text();
        if (ui->widget_name_lineEdit_name_data->text() == "") {
            cInfo.name = ui->widget_name_lineEdit_name_data->placeholderText();
        }
//        cInfo.group = ui->widget_group_lineEdit_group_data->text();
//        if (ui->widget_group_lineEdit_group_data->text() == "") {
//            cInfo.group = ui->widget_group_lineEdit_group_data->placeholderText();
//        }
        cInfo.host = ui->lineEdit_host_ssh_data->text();
        cInfo.port = ui->lineEdit_port_ssh_data->text();

        cInfo.userName = ui->lineEdit_user_ssh_data->text();
        if (ui->lineEdit_user_ssh_data->text() == "") {
            cInfo.userName = ui->lineEdit_user_ssh_data->placeholderText();
        }
        cInfo.password = ui->tab_passowrd_lineEdit_password_data->text();
        cInfo.isSavePassword = ui->tab_passowrd_checkBox_remember_password->isChecked();
        //备注
        cInfo.remark = ui->widget_remark_lineEdit_remark_data->text();

        //最近连接时间
        QDateTime currentDateTime = QDateTime::currentDateTime();
        cInfo.nearest_connection = currentDateTime.toString("yyyy-MM-dd hh:mm:ss");

        //判断登录类型 1密码 2公钥
        if (ui->tabWidget_password->currentIndex() == 0) {
            qDebug() << "密码登录";
            cInfo.sshType = SSH_PASSWORD;
        } else if (ui->tabWidget_password->currentIndex() == 1) {
            qDebug() << "公钥登录";
            cInfo.sshType = SSH_PUBLICKEY;
            //通过数据库查询文件路径和密码
            cInfo.userName = ui->lineEdit_publicKey->text();
            sshKeyStruct sshKeyInfo = db->sshKey_getSSHKeyInfoByName(ui->lineEdit_publicKey->text());
            cInfo.password = sshKeyInfo.password;
            cInfo.publickey = sshKeyInfo.path;
            qDebug() << "password = " << sshKeyInfo.password << " publickey = " << sshKeyInfo.path;
        }
    } else if (ui->tabWidget->currentIndex() == 2) {
        cInfo.connectType = 3;//this->connectType;
        cInfo.name = ui->widget_name_lineEdit_name_data->text();
        if (ui->widget_name_lineEdit_name_data->text() == "") {
            cInfo.name = ui->widget_name_lineEdit_name_data->placeholderText();
        }
//        cInfo.group = ui->widget_group_lineEdit_group_data->text();
//        if (ui->widget_group_lineEdit_group_data->text() == "") {
//            cInfo.group = ui->widget_group_lineEdit_group_data->placeholderText();
//        }
        cInfo.host = ui->lineEdit_host_zk_data->text();
        cInfo.port = ui->lineEdit_port_zk_data->text();
    } else if (ui->tabWidget->currentIndex() == 3) {
        cInfo.connectType = 4;
        cInfo.name = ui->widget_name_lineEdit_name_data->text();
        if (ui->widget_name_lineEdit_name_data->text() == "") {
            cInfo.name = ui->widget_name_lineEdit_name_data->placeholderText();
        }
//        cInfo.group = ui->widget_group_lineEdit_group_data->text();
//        if (ui->widget_group_lineEdit_group_data->text() == "") {
//            cInfo.group = ui->widget_group_lineEdit_group_data->placeholderText();
//        }
        cInfo.host = ui->lineEdit_host_db_data->text();
        cInfo.port = ui->lineEdit_port_db_data->text();

        cInfo.userName = ui->lineEdit_user_db_data->text();
        if (ui->lineEdit_user_db_data->text() == "") {
            cInfo.userName = ui->lineEdit_user_db_data->placeholderText();
        }
        cInfo.password = ui->tab_passowrd_lineEdit_password_db_data->text();
        cInfo.isSavePassword = ui->tab_passowrd_checkBox_remember_password_db->isChecked();
    }

    emit newCreate(cInfo);
    this->hide();
    return;
}

void createconnect::on_widget_bottom_toolButton_close_clicked()
{
    emit newClose();
    this->close();
}

void createconnect::on_tab_passowrd_toolButton_show_clicked()
{
    if (isShowPassword) {
       isShowPassword = false;
       //隐藏密码
       ui->tab_passowrd_toolButton_show->setIcon(QIcon(":lib/eye2.png"));
       ui->tab_passowrd_lineEdit_password_data->setEchoMode(QLineEdit::Password);//设置密码隐藏
    } else {
       isShowPassword = true;
       //显示密码
       ui->tab_passowrd_toolButton_show->setIcon(QIcon(":lib/eye1.png"));
       ui->tab_passowrd_lineEdit_password_data->setEchoMode(QLineEdit::Normal);//设置密码显示

    }
}

void createconnect::on_toolButton_browse_clicked()
{
    if (skwidget != NULL) {
        delete(skwidget);
    }
    skwidget = new secretkeywidget();
    connect(skwidget,SIGNAL(send_selectPublicKey(QString)),this,SLOT(rece_selectPublicKey(QString)));
    skwidget->show();
}

void createconnect::on_lineEdit_host_ssh_data_textChanged(const QString &arg1)
{
    //host被修改，同步到名称(如果没有被设置的话)
    if (!isEditName) {
        ui->widget_name_lineEdit_name_data->setText(arg1);
    }
}

void createconnect::on_widget_name_lineEdit_name_data_textEdited(const QString &arg1)
{
    //使用者修改了名称文本框
    if (arg1 == "") {
        isEditName = false;
    } else {
        isEditName = true;
    }
}

void createconnect::on_tabWidget_currentChanged(int index)
{
    qDebug() << "修改" << index;
    //只有ssh，左侧可以修改
//    if (index == 0) {
//        ui->widget_name_lineEdit_name_data->setEnabled(true);
//        ui->widget_group_lineEdit_group_data->setEnabled(true);
//        ui->widget_remark_lineEdit_remark_data->setEnabled(true);
//    } else {
//        ui->widget_name_lineEdit_name_data->setEnabled(false);
//        ui->widget_group_lineEdit_group_data->setEnabled(false);
//        ui->widget_remark_lineEdit_remark_data->setEnabled(false);
//    }
}

void createconnect::rece_selectPublicKey(QString text) {
    //显示数据
    ui->lineEdit_publicKey->setText(text);

}

void createconnect::on_widget_bottom_toolButton_save_clicked()
{
    //保存数据
    //创建选择的连接信息
    connnectInfoStruct cInfo;
    if (ui->tabWidget->currentIndex() == 0) {
        cInfo.connectType = 1;//this->connectType;
        cInfo.name = ui->widget_name_lineEdit_name_data->text();
        if (ui->widget_name_lineEdit_name_data->text() == "") {
            cInfo.name = ui->widget_name_lineEdit_name_data->placeholderText();
        }
//        cInfo.group = ui->widget_group_lineEdit_group_data->text();
//        if (ui->widget_group_lineEdit_group_data->text() == "") {
//            cInfo.group = ui->widget_group_lineEdit_group_data->placeholderText();
//        }
        cInfo.host = ui->lineEdit_host_ssh_data->text();
        cInfo.port = ui->lineEdit_port_ssh_data->text();

        cInfo.userName = ui->lineEdit_user_ssh_data->text();
        if (ui->lineEdit_user_ssh_data->text() == "") {
            cInfo.userName = ui->lineEdit_user_ssh_data->placeholderText();
        }
        cInfo.password = ui->tab_passowrd_lineEdit_password_data->text();
        cInfo.isSavePassword = ui->tab_passowrd_checkBox_remember_password->isChecked();
        //备注
        cInfo.remark = ui->widget_remark_lineEdit_remark_data->text();

        //最近连接时间
        QDateTime currentDateTime = QDateTime::currentDateTime();
        cInfo.nearest_connection = currentDateTime.toString("yyyy-MM-dd hh:mm:ss");

        //判断登录类型 1密码 2公钥
        if (ui->tabWidget_password->currentIndex() == 0) {
            qDebug() << "密码登录";
            cInfo.sshType = SSH_PASSWORD;
        } else if (ui->tabWidget_password->currentIndex() == 1) {
            qDebug() << "公钥登录";
            cInfo.sshType = SSH_PUBLICKEY;
            //通过数据库查询文件路径和密码
            cInfo.userName = ui->lineEdit_publicKey->text();
            sshKeyStruct sshKeyInfo = db->sshKey_getSSHKeyInfoByName(ui->lineEdit_publicKey->text());
            cInfo.password = sshKeyInfo.password;
            cInfo.publickey = sshKeyInfo.path;
            qDebug() << "password = " << sshKeyInfo.password << " publickey = " << sshKeyInfo.path;
        }
    } else if (ui->tabWidget->currentIndex() == 2) {
        cInfo.connectType = 3;//this->connectType;
        cInfo.name = ui->widget_name_lineEdit_name_data->text();
        if (ui->widget_name_lineEdit_name_data->text() == "") {
            cInfo.name = ui->widget_name_lineEdit_name_data->placeholderText();
        }
//        cInfo.group = ui->widget_group_lineEdit_group_data->text();
//        if (ui->widget_group_lineEdit_group_data->text() == "") {
//            cInfo.group = ui->widget_group_lineEdit_group_data->placeholderText();
//        }
        cInfo.host = ui->lineEdit_host_zk_data->text();
        cInfo.port = ui->lineEdit_port_zk_data->text();
    }

    emit newSave(cInfo);
    this->hide();
    return;
}

