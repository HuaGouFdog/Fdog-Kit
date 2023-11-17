#include "settingwidget.h"
#include "ui_settingwidget.h"
#include "utils.h"
#include "colormatch.h"
#include <QPropertyAnimation>
#include <QFontDatabase>
#include <QListWidget>
QStringList campbell = {"#0C0C0C","#767676",
                        "#C50F1F","#E74856",
                        "#13A10E","#16C60C",
                        "#C19C00","#F9F1A5",
                        "#0037DA","#3B78FF",
                        "#881798","#B4009E",
                        "#3A96DD","#61D6D6",
                        "#CCCCCC","#F2F2F2",
                        "#0C0C0C"};

QStringList campbellPowershell = {"#0C0C0C","#767676",
                                  "#C50F1F","#E74856",
                                  "#13A10E","#16C60C",
                                  "#C19C00","#F9F1A5",
                                  "#0037DA","#3B78FF",
                                  "#881798","#B4009E",
                                  "#3A96DD","#61D6D6",
                                  "#CCCCCC","#F2F2F2",
                                  "#012456"};

QStringList oneHalfDark = {"#282C34","#5A6374",
                           "#E06C75","#E06C75",
                           "#98C379","#98C379",
                           "#E5C07B","#E5C07B",
                           "#61AFEF","#61AFEF",
                           "#C678DD","#C678DD",
                           "#56B6C2","#56B6C2",
                           "#DCDFE4","#DCDFE4",
                           "#282C34"};

QStringList oneHalfLight = {"#383A42","#4F525D",
                            "#E45649","#DF6C75",
                            "#50A14F","#98C379",
                            "#C18301","#E4C07A",
                            "#0184BC","#61AFEF",
                            "#A626A4","#C577DD",
                            "#0997B3","#56B5C1",
                            "#FAFAFA","#FFFFFF",
                            "#FAFAFA"};

QStringList solarizedDark = {"#383A42","#4F525D",
                            "#E45649","#DF6C75",
                            "#50A14F","#98C379",
                            "#C18301","#E4C07A",
                            "#0184BC","#61AFEF",
                            "#A626A4","#C577DD",
                            "#0997B3","#56B5C1",
                            "#FAFAFA","#FFFFFF",
                            "#002B36"};

QStringList solarizedLight = {"#002B36","#073642",
                            "#DC322F","#CB4B16",
                            "#859900","#586E75",
                            "#B58900","#657B83",
                            "#268BD2","#839496",
                            "#D33682","#6C71C4",
                            "#2AA198","#93A1A1",
                            "#EEE8D5","#FDF6E3",
                            "#FDF6E3"};

QStringList tangoDark = {"#000000","#555753",
                            "#CC0000","#EF2929",
                            "#4E9A06","#8AE234",
                            "#C4A000","#FCE94F",
                            "#3465A4","#729FCF",
                            "#75507B","#AD7FA8",
                            "#06989A","#34E2E2",
                            "#D3D7CF","#EEEEEC",
                            "#000000"};

QStringList tangoLight = {"#000000","#555753",
                            "#CC0000","#EF2929",
                            "#4E9A06","#8AE234",
                            "#C4A000","#FCE94F",
                            "#3465A4","#729FCF",
                            "#75507B","#AD7FA8",
                            "#06989A","#34E2E2",
                            "#D3D7CF","#EEEEEC",
                            "#FFFFFF"};

QStringList ubuntu1804 = {"#171421","#767676",
                          "#C21A23","#C01C28",
                          "#26A269","#26A269",
                          "#A2734C","#A2734C",
                          "#0037DA","#08458F",
                          "#881798","#A347BA",
                          "#3A96DD","#2C9FB3",
                          "#CCCCCC","#F2F2F2",
                          "#300A24"};

QStringList vintage = {"#000000","#808080",
                       "#800000","#FF0000",
                       "#008000","#00FF00",
                       "#808000","#FFFF00",
                       "#000080","#0000FF",
                       "#800080","#FF00FF",
                       "#008080","#00FFFF",
                       "#C0C0C0","#FFFFFF",
                       "#000000"};

settingwidget::settingwidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::settingwidget)
{
    ui->setupUi(this);
    AnimatedCheckBox * cb = new AnimatedCheckBox(this);

    ui->verticalLayout_8->addWidget(cb);
    cb->show();

    AnimatedCheckBox * cb2 = new AnimatedCheckBox(this);

    ui->verticalLayout_9->addWidget(cb2);
    cb2->show();

    AnimatedCheckBox * cb3 = new AnimatedCheckBox(this);

    ui->verticalLayout_14->addWidget(cb3);
    cb3->show();

    AnimatedCheckBox * cb4 = new AnimatedCheckBox(this);

    ui->verticalLayout_29->addWidget(cb4);
    cb4->show();

    colormatch * cm_ = new colormatch("Campbell", campbell, this);
    ui->verticalWidget_15->layout()->addWidget(cm_);
    cm_->show();

    colormatch * cm = new colormatch("Campbell Powershell", campbellPowershell, this);
    ui->verticalWidget_16->layout()->addWidget(cm);
    cm->show();

    colormatch * cm2 = new colormatch("One Half Dark", oneHalfDark, this);
    ui->verticalWidget_17->layout()->addWidget(cm2);
    cm2->show();

    colormatch * cm3 = new colormatch("One Half Light", oneHalfLight, this);
    ui->verticalWidget_18->layout()->addWidget(cm3);
    cm3->show();

    colormatch * cm4 = new colormatch("Solarized Dark", solarizedDark, this);
    ui->verticalWidget_19->layout()->addWidget(cm4);
    cm4->show();

    colormatch * cm5 = new colormatch("Solarized Light", solarizedLight, this);
    ui->verticalWidget_20->layout()->addWidget(cm5);
    cm5->show();

    colormatch * cm6 = new colormatch("Tango Dark", tangoDark, this);
    ui->verticalWidget_21->layout()->addWidget(cm6);
    cm6->show();

    colormatch * cm7 = new colormatch("Tango Light", tangoLight, this);
    ui->verticalWidget_22->layout()->addWidget(cm7);
    cm7->show();

    colormatch * cm8 = new colormatch("Ubuntu-18.04-ColorScheme", ubuntu1804, this);
    ui->verticalWidget_23->layout()->addWidget(cm8);
    cm8->show();

    colormatch * cm9 = new colormatch("Vintage", vintage, this);
    ui->verticalWidget_24->layout()->addWidget(cm9);
    cm9->show();

    QButtonGroup * m_buttonGroup = new QButtonGroup(this);
    m_buttonGroup->addButton(ui->toolButton_activate, 0);
    m_buttonGroup->addButton(ui->toolButton_appearance, 1);
    m_buttonGroup->addButton(ui->toolButton_typeface, 2);
    m_buttonGroup->addButton(ui->toolButton_colorMatch, 3);
    m_buttonGroup->addButton(ui->toolButton_theme, 4);
    m_buttonGroup->addButton(ui->toolButton_terminal, 5);
    m_buttonGroup->addButton(ui->toolButton_shortcutKey, 6);
    m_buttonGroup->button(0)->setChecked(true); //设置按钮组第一个按钮高亮显示
    m_buttonGroup->setExclusive(true);

    connect(m_buttonGroup, SIGNAL(buttonClicked(int)), this, SLOT(on_Menu_clicked(int)));

    QFontDatabase fdb;
    QStringList fontList = fdb.families();
    ui->listWidget_en->addItems(fontList);
    ui->listWidget_cn->addItems(fontList);
}

settingwidget::~settingwidget()
{
    delete ui;
}

void settingwidget::on_Menu_clicked(int index)
{
    ui->stackedWidget->setCurrentIndex(index);
}

//void settingwidget::on_toolButton_clicked()
//{
////    QPropertyAnimation* animation = new QPropertyAnimation(ui->stackedWidget, "currentIndex");
////    animation->setDuration(100);
////    animation->setStartValue(ui->stackedWidget->currentIndex());
////    animation->setEndValue((ui->stackedWidget->currentIndex() + 1)%7);
////    animation->start(QAbstractAnimation::DeleteWhenStopped);
////    animation->setEasingCurve(QEasingCurve::InCubic); // 使用缓动效果
//    ui->stackedWidget->setCurrentIndex((ui->stackedWidget->currentIndex() + 1)%7);
//}
