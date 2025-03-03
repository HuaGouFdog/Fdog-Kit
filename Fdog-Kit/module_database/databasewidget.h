#ifndef DATABASEWIDGET_H
#define DATABASEWIDGET_H

#include <QWidget>
#include<QTreeWidgetItem>
#include <QSqlDatabase>
#include <QPropertyAnimation>
#include "module_utils/utils.h"

namespace Ui {
class databasewidget;
}

class databasewidget : public QWidget
{
    Q_OBJECT

public:
    QSqlDatabase database;
    QPropertyAnimation * m_pos_animation;

    explicit databasewidget(QWidget *parent = nullptr);
    explicit databasewidget(connnectInfoStruct& cInfoStruct, QWidget *parent = nullptr);
    ~databasewidget();

    //初始化数据库信息
    void initDBInfo();
    //新建连接
    void newDBWidget(connnectInfoStruct& cInfoStruct);

private slots:
    void on_treeWidget_db_itemClicked(QTreeWidgetItem *item, int column);

    void on_treeWidget_db_itemDoubleClicked(QTreeWidgetItem *item, int column);

    void on_toolButton_clicked();

    void on_treeWidget_db_customContextMenuRequested(const QPoint &pos);

    void rece_deleteDatabase();

    void rece_closeConnect();
    void rece_deleteConnect();

    void rece_showCraeteTable();
    void rece_showTableData();
    void rece_deleteTable();

    void rece_showField();
    void rece_deleteField();


private:
    Ui::databasewidget *ui;
};

#endif // DATABASEWIDGET_H
