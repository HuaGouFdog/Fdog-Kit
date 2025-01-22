#ifndef KEYWIDGET_H
#define KEYWIDGET_H

#include <QWidget>
//#include "createconnect.h"
//#include "module_sql/sqlhandle.h"
#include "module_ssh/sshsql.h"
namespace Ui {
class keywidget;
}

class keywidget : public QWidget
{
    Q_OBJECT

public:
    explicit keywidget(QWidget *parent = 0);
    ~keywidget();

signals:
    void send_addsshKey(sshKeyStruct &);

private slots:
    void on_toolButton_browse_clicked();

    void on_toolButton_cancel_clicked();

    void on_toolButton_ok_clicked();

private:
    Ui::keywidget *ui;
    QString path;

    //操作数据库
    sshsql * db;
};

#endif // KEYWIDGET_H
