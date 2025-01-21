#ifndef SSHWIDGETMANAGEWIDGET_H
#define SSHWIDGETMANAGEWIDGET_H

#include <QWidget>
#include "historycommondwidget.h"
#include "module_utils/utils.h"
#include "module_sql/sqlhandle.h"
#include "module_historyconnect/historyconnectwidget.h"
#include "module_config/config.h"
#include <QDateTime>
#include "sshwidget.h"
#include "sshsql.h"
#include <QSize>
namespace Ui {
class sshwidgetmanagewidget;
}

class sshwidgetmanagewidget : public QWidget
{
    Q_OBJECT

public:
    explicit sshwidgetmanagewidget(config * confInfo, QWidget *parent = nullptr);
    void newSSHWidget(connnectInfoStruct& cInfoStruct, config * confInfo);
    ~sshwidgetmanagewidget();


    //操作数据库
    sqlhandle * db_;
    sshsql * db;
    historyconnectwidget * hcwidget = nullptr;  //快速连接
    QVector<sshwidget*> sshWidgetList;
    bool isShowToolKit = false; //是否显示工具栏
    config * confInfo; //这个应该同步更新
private slots:
    void rece_widget_welcome_body_widget2_newCreate_newTool_clicked();

    void rece_toolButton_fullScreen_sign();

    void rece_connection_success(sshwidget * sw);

    void rece_connection_fail(sshwidget * sw);

    void rece_windowsSetting();

    void on_tabWidget_customContextMenuRequested(const QPoint &pos);

    void rece_reconnection_sgin();

    void rece_copyTag_sgin();

    void rece_close_sgin();

    void rece_closeOther_sgin();

    void rece_closeAll_sgin();

    void on_tabWidget_tabCloseRequested(int index);

    void rece_fastConnection(connnectInfoStruct& cInfoStruct);

    void rece_findConnection(QString text, int type = 0);

    //暂时放在这里
    void on_comboBox_tool_currentIndexChanged(int index);

    void on_lineEdit_hex_textChanged(const QString &arg1);

    void on_lineEdit_dec_textChanged(const QString &arg1);

    void on_lineEdit_oct_textChanged(const QString &arg1);

    void on_lineEdit_bin_textChanged(const QString &arg1);

    void on_toolButton_decode_clicked();

    void on_toolButton_encode_clicked();

    void rece_showtimestamp();
    void on_toolButton_time2date_clicked();

    void on_toolButton_date2time_clicked();

    void on_toolButton_timestamp_copy_clicked();

    void on_toolButton_closetool_clicked();

private:
    Ui::sshwidgetmanagewidget *ui;
};

#endif // SSHWIDGETMANAGEWIDGET_H
