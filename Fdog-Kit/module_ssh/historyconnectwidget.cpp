#pragma execution_character_set("utf-8")
#include "historyconnectwidget.h"
#include "ui_historyconnectwidget.h"
#include <QDebug>
#include <QToolButton>
#include <QCompleter>
#include <QIcon>
#include "module_utils/utils.h"
#include "module_ssh/sshwidgetmanagewidget.h"
historyconnectwidget::historyconnectwidget(int8_t connectType, QVector<connnectInfoStruct> cInfoStructList, config * confInfo, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::historyconnectwidget)
{
    ui->setupUi(this);
    parent_ = parent;
    this->confInfo = confInfo;
    //设置初始表格行列都为0
    ui->tableWidget_history->setColumnCount(7); //设置列数为5
    //ui->tableWidget_history->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    //ui->tableWidget_history->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents); //列自动缩放
    ui->tableWidget_history->setHorizontalHeaderLabels(QStringList() << "                              名称                              "
                                                        << "                              主机                              "
                                                        << "                              端口                              "
                                                        << "                             用户名                             "
                                                        << "                              备注                              " 
                                                        << "         分组           "
                                                        << "         最近连接           ");
                                                        //<< "         操作           " );
    ui->tableWidget_history->horizontalHeader()->setDefaultAlignment(Qt::AlignHCenter | Qt::AlignVCenter);

    // 设置第三列的宽度为 150 像素
    ui->tableWidget_history->setColumnWidth(0, 220);
    ui->tableWidget_history->setColumnWidth(1, 220);
    // 设置第三列的宽度为 150 像素
    ui->tableWidget_history->setColumnWidth(2, 150);
    ui->tableWidget_history->setColumnWidth(3, 150);
    ui->tableWidget_history->setColumnWidth(4, 150);

    //解决鼠标滑过，样式表不是整行的问题
    auto delegate = new HoveredRowItemDelegate(ui->tableWidget_history);
    ui->tableWidget_history->setItemDelegate(delegate);

    loadSSHinfoList(cInfoStructList);

    setSupportStretch(this, true);

    TreeWidgetFilter *filter = new TreeWidgetFilter(this);
    connect(filter,SIGNAL(send_updateMouseStyle()),this,SLOT(rece_updateMouseStyle()));
    ui->tableWidget_history->installEventFilter(filter);
}

historyconnectwidget::~historyconnectwidget()
{
    delete ui;
}

//默认这个接口只在初始化调用
void historyconnectwidget::loadSSHinfoList(QVector<connnectInfoStruct> cInfoStructList)
{
    //设置行数
    ui->tableWidget_history->setRowCount(cInfoStructList.length()); //设置行数为20
    //暂时使用这种  复杂场景用QAbstractItemModel
    for (int row = 0; row < cInfoStructList.length(); ++row) {
        dataSource.append(cInfoStructList.at(row).name);
        for (int col = 0; col < 7; ++col) {
            QString headerData;
            if (col == 0) {
                headerData = cInfoStructList.at(row).name;
                QLabel * label = new QLabel();
                label->setFixedSize(15,15);
                //QString path;
                if (cInfoStructList.at(row).sshType == "1") {
                    //path = ":/lib/password.svg";
                    label->setObjectName("password");
                    //label->setStyleSheet("border-image: url(:/lib/password.svg); background-color: rgba(0, 214, 103, 0);");
                } else if (cInfoStructList.at(row).sshType == "2") {
                    //path = ":/lib/key.svg";
                    label->setObjectName("publicKey");
                    //label->setStyleSheet("border-image: url(:/lib/key.svg); background-color: rgba(0, 214, 103, 0);");
                }
                ui->tableWidget_history->setCellWidget(row, 0, label);
            } else if (col == 1) {
                headerData = cInfoStructList.at(row).host;
            } else if (col == 2) {
                headerData = cInfoStructList.at(row).port;
            } else if (col == 3) {
                headerData = cInfoStructList.at(row).userName;
            } else if (col == 4) {
                headerData = cInfoStructList.at(row).remark;
            } else if (col == 5) {
                headerData = cInfoStructList.at(row).group;
            } else if (col == 6) {
                
                headerData = cInfoStructList.at(row).nearest_connection;
            } else if (col == 7) {
                QWidget *widget;
                QHBoxLayout *hLayout;
                hLayout = new QHBoxLayout();  
                widget = new QWidget(ui->tableWidget_history);  
                QSpacerItem * sparcer_item = new QSpacerItem(0,160,QSizePolicy::Expanding,QSizePolicy::Minimum);
                hLayout->addItem(sparcer_item);
                QToolButton* button_edit = new QToolButton();
                button_edit->setText("修改");
                button_edit->setFixedSize(50,20);
                hLayout->addWidget(button_edit);
                hLayout->setAlignment(button_edit, Qt::AlignCenter);

                QToolButton* button_delete = new QToolButton();
                button_delete->setText("删除");
                button_delete->setFixedSize(50,20);
                hLayout->addWidget(button_delete);
                hLayout->setAlignment(button_delete, Qt::AlignCenter);

                QSpacerItem * sparcer_item2 = new QSpacerItem(0,160,QSizePolicy::Expanding,QSizePolicy::Minimum);
                hLayout->addItem(sparcer_item2);

                hLayout->setMargin(0);

                widget->setLayout(hLayout);  
                //widget->setFixedSize(120,30);
                ui->tableWidget_history->setCellWidget(row, 6, widget);
            }
            QTableWidgetItem *item = new QTableWidgetItem(headerData);
            ui->tableWidget_history->setItem(row, col, item);
            item->setTextAlignment(Qt::AlignCenter); // 设置对齐方式为居中
            if (col == 0) {
                if (cInfoStructList.at(row).sshType == "1") {
                    QSize iconSize(30, 30);
                    item->setIcon(QIcon(":/lib/shell.png").pixmap(iconSize));
                } else if (cInfoStructList.at(row).sshType == "2") {
                    QSize iconSize(30, 30);
                    item->setIcon(QIcon(":/lib/shell.png").pixmap(iconSize));
                }
            }
        }
    }

    QCompleter *completer = new QCompleter(dataSource, this);

    QAbstractItemView* view = completer->popup();
    view->setItemDelegate(new ComboBoxDelegate());//设置行高

    completer->setCaseSensitivity(Qt::CaseInsensitive); //大小写不敏感
    completer->setFilterMode(Qt::MatchContains); //内容匹配
    connect(completer,SIGNAL(activated(const QString)),this,SLOT(rece_activated(const QString)));
    connect(completer,SIGNAL(highlighted(const QString)),this,SLOT(rece_highlighted(const QString)));
    ui->lineEdit_find->setCompleter(completer);
}

void historyconnectwidget::loadSSHinfo(connnectInfoStruct cInfoStruct)
{
    int currentRowCount = ui->tableWidget_history->rowCount();
    //设置行数
    ui->tableWidget_history->setRowCount(currentRowCount + 1); //设置行数为20
    //暂时使用这种  复杂场景用QAbstractItemModel
        dataSource.append(cInfoStruct.name);
        for (int col = 0; col < 7; ++col) {
            QString headerData;
            if (col == 0) {
                headerData = cInfoStruct.name;
                QLabel * label = new QLabel();
                label->setFixedSize(15,15);
                //QString path;
                if (cInfoStruct.sshType == "1") {
                    //path = ":/lib/password.svg";
                    label->setObjectName("password");
                    //label->setStyleSheet("border-image: url(:/lib/password.svg); background-color: rgba(0, 214, 103, 0);");
                } else if (cInfoStruct.sshType == "2") {
                    //path = ":/lib/key.svg";
                    label->setObjectName("publicKey");
                    //label->setStyleSheet("border-image: url(:/lib/key.svg); background-color: rgba(0, 214, 103, 0);");
                }
                ui->tableWidget_history->setCellWidget(currentRowCount, 0, label);
            } else if (col == 1) {
                headerData = cInfoStruct.host;
            } else if (col == 2) {
                headerData = cInfoStruct.port;
            } else if (col == 3) {
                headerData = cInfoStruct.userName;
            } else if (col == 4) {
                headerData = cInfoStruct.remark;
            } else if (col == 5) {
                headerData = cInfoStruct.group;
            } else if (col == 6) {
                
                headerData = cInfoStruct.nearest_connection;
            } else if (col == 7) {
                QWidget *widget;
                QHBoxLayout *hLayout;
                hLayout = new QHBoxLayout();  
                widget = new QWidget(ui->tableWidget_history);  
                QSpacerItem * sparcer_item = new QSpacerItem(0,160,QSizePolicy::Expanding,QSizePolicy::Minimum);
                hLayout->addItem(sparcer_item);
                QToolButton* button_edit = new QToolButton();
                button_edit->setText("修改");
                button_edit->setFixedSize(50,20);
                hLayout->addWidget(button_edit);
                hLayout->setAlignment(button_edit, Qt::AlignCenter);

                QToolButton* button_delete = new QToolButton();
                button_delete->setText("删除");
                button_delete->setFixedSize(50,20);
                hLayout->addWidget(button_delete);
                hLayout->setAlignment(button_delete, Qt::AlignCenter);

                QSpacerItem * sparcer_item2 = new QSpacerItem(0,160,QSizePolicy::Expanding,QSizePolicy::Minimum);
                hLayout->addItem(sparcer_item2);

                hLayout->setMargin(0);

                widget->setLayout(hLayout);  
                //widget->setFixedSize(120,30);
                ui->tableWidget_history->setCellWidget(currentRowCount, 6, widget);
            }
            QTableWidgetItem *item = new QTableWidgetItem(headerData);
            ui->tableWidget_history->setItem(currentRowCount, col, item);
            item->setTextAlignment(Qt::AlignCenter); // 设置对齐方式为居中
            if (col == 0) {
                if (cInfoStruct.sshType == "1") {
                    QSize iconSize(30, 30);
                    item->setIcon(QIcon(":/lib/shell.png").pixmap(iconSize));
                } else if (cInfoStruct.sshType == "2") {
                    QSize iconSize(30, 30);
                    item->setIcon(QIcon(":/lib/shell.png").pixmap(iconSize));
                }
            }
        }

    QCompleter *completer = new QCompleter(dataSource, this);

    QAbstractItemView* view = completer->popup();
    view->setItemDelegate(new ComboBoxDelegate());//设置行高

    completer->setCaseSensitivity(Qt::CaseInsensitive); //大小写不敏感
    completer->setFilterMode(Qt::MatchContains); //内容匹配
    connect(completer,SIGNAL(activated(const QString)),this,SLOT(rece_activated(const QString)));
    connect(completer,SIGNAL(highlighted(const QString)),this,SLOT(rece_highlighted(const QString)));
    ui->lineEdit_find->setCompleter(completer);
}

void historyconnectwidget::on_tableWidget_history_itemDoubleClicked(QTableWidgetItem *item)
{
    int currentRow = ui->tableWidget_history->currentIndex().row();
    //qDebug() << "双击1";
    connnectInfoStruct cInfo;
    cInfo.name = ui->tableWidget_history->item(currentRow, 0)->text();
    cInfo.host = ui->tableWidget_history->item(currentRow, 1)->text();
    cInfo.port = ui->tableWidget_history->item(currentRow, 2)->text();
    cInfo.userName = ui->tableWidget_history->item(currentRow, 3)->text();
    cInfo.connectType =SSH_CONNECT_TYPE;
    QLabel * lable_ = qobject_cast<QLabel*>(ui->tableWidget_history->cellWidget(currentRow, 0));
    if (lable_ != NULL) {
        if (lable_->objectName() == "password") {
            cInfo.sshType = SSH_PASSWORD;
            qDebug() << "密码连接";
        } else if (lable_->objectName() == "publicKey") {
            cInfo.sshType =SSH_PUBLICKEY;
            qDebug() << "公钥连接";
        } else {

        }
    }
    //上面这里完全没必要，后面会查数据库的
    emit send_fastConnection(cInfo);
}

void historyconnectwidget::on_tableWidget_history_currentItemChanged(QTableWidgetItem *current, QTableWidgetItem *previous)
{
    qDebug() << "单击";
}

void historyconnectwidget::rece_activated(const QString &text)
{
    //选中
    emit send_findConnection(text);
    qDebug() << "rece_activated = " << text;
}

void historyconnectwidget::rece_highlighted(const QString &text)
{
    //选择
    qDebug() << "rece_highlighted = " << text;
}



void historyconnectwidget::on_toolButton_create_clicked()
{
    //新建终端
    int8_t connectType = 1;
    ccwidget = new createconnect(connectType);
    connect(ccwidget,SIGNAL(newCreate(connnectInfoStruct&)),this,SLOT(rece_newConnnect(connnectInfoStruct&)));
    connect(ccwidget,SIGNAL(newSave(connnectInfoStruct&)),this,SLOT(rece_newSave(connnectInfoStruct&)));
    ccwidget->show();
}
void historyconnectwidget::rece_newConnnect(connnectInfoStruct& cInfoStruct) {
    //新建连接
    sshwidgetmanagewidget *smanagewidget = static_cast<sshwidgetmanagewidget*>(parent_);
    smanagewidget->newSSHWidget(cInfoStruct, confInfo);
    smanagewidget->db->ssh_insertSSHInfo(cInfoStruct);
    //更新到historyconnectwidget
    loadSSHinfo(cInfoStruct);
}

void historyconnectwidget::rece_newSave(connnectInfoStruct& cInfoStruct) {
    //保存
    sshwidgetmanagewidget *smanagewidget = static_cast<sshwidgetmanagewidget*>(parent_);
    smanagewidget->db->ssh_insertSSHInfo(cInfoStruct);
    //更新到historyconnectwidget
    loadSSHinfo(cInfoStruct);
}

void historyconnectwidget::rece_updateMouseStyle() {
    //设置为箭头
    setCursor(Qt::ArrowCursor);
}