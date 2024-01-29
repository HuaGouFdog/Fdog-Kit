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

settingwidget::settingwidget(config * confInfo_, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::settingwidget)
{
    ui->setupUi(this);

    confInfo = confInfo_;
    selfStart = new AnimatedCheckBox(confInfo_->selfStart, this);
    ui->verticalLayout_selfStart->addWidget(selfStart);
    
    trayDisplay = new AnimatedCheckBox(confInfo_->trayDisplay, this);
    ui->verticalLayout_trayDisplay->addWidget(trayDisplay);

    startCenter = new AnimatedCheckBox(confInfo_->startCenter, this);
    ui->verticalLayout_startCenter->addWidget(startCenter);

    topDisplay = new AnimatedCheckBox(confInfo_->topDisplay, this);
    ui->verticalLayout_topDisplay->addWidget(topDisplay);

    infoDisplay = new AnimatedCheckBox(confInfo_->infoDisplay, this);
    ui->verticalLayout_infoDisplay->addWidget(infoDisplay);

    historyDisplay = new AnimatedCheckBox(confInfo_->historyDisplay, this);
    ui->verticalLayout_historyDisplay->addWidget(historyDisplay);

    commandDisplay = new AnimatedCheckBox(confInfo_->commandDisplay, this);
    ui->verticalLayout_commandDisplay->addWidget(commandDisplay);

    conectStatsDisplay = new AnimatedCheckBox(confInfo_->conectStatsDisplay, this);
    ui->verticalLayout_conectStatsDisplay->addWidget(conectStatsDisplay);






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
    m_buttonGroup->addButton(ui->toolButton_colorSchemes, 3);
    m_buttonGroup->addButton(ui->toolButton_theme, 4);
    m_buttonGroup->addButton(ui->toolButton_terminal, 5);
    m_buttonGroup->addButton(ui->toolButton_shortcutKey, 6);
    m_buttonGroup->button(0)->setChecked(true); //设置按钮组第一个按钮高亮显示
    m_buttonGroup->setExclusive(true);
    ui->stackedWidget->setCurrentIndex(0);
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


void settingwidget::on_toolButton_save_clicked()
{
    //保存写入confInfo
    //启动选项
    if (selfStart->isChecked()) {
        confInfo->selfStart = 1;
    } else {
        confInfo->selfStart = 0;
    }

    if (trayDisplay->isChecked()) {
        confInfo->trayDisplay = 1;
    } else {
        confInfo->trayDisplay = 0;
    }

    if (ui->comboBox_startMode->currentIndex() == 0) {
        confInfo->startMode = 0;
    } else if (ui->comboBox_startMode->currentIndex() == 1) {
        confInfo->startMode = 1;
    } else if (ui->comboBox_startMode->currentIndex() == 2) {
        confInfo->startMode = 2;
    }

    confInfo->startPositionX = ui->spinBox_startPositionX->value();
    confInfo->startPositionY = ui->spinBox_startPositionY->value();

    if (startCenter->isChecked()) {
        confInfo->startCenter = 1;
    } else {
        confInfo->startCenter = 0;
    }

    //外观选项
    if (ui->comboBox_language->currentIndex() == 0) {
        confInfo->language = "cn";
    } else if (ui->comboBox_language->currentIndex() == 1) {
        confInfo->language = "zn";
    }

    if (topDisplay->isChecked()) {
        confInfo->topDisplay = 1;
    } else {
        confInfo->topDisplay = 0;
    }

    if (ui->comboBox_newLabelLocation->currentIndex() == 0) {
        confInfo->newLabelLocation = 0;
    } else if (ui->comboBox_newLabelLocation->currentIndex() == 1) {
        confInfo->newLabelLocation = 1;
    }

    if (ui->comboBox_labelWidth->currentIndex() == 0) {
        confInfo->labelWidth = 0;
    } else if (ui->comboBox_labelWidth->currentIndex() == 1) {
        confInfo->labelWidth = 1;
    } else if (ui->comboBox_labelWidth->currentIndex() == 2) {
        confInfo->labelWidth = 2;
    }

    //字体选项
    confInfo->fontSize = ui->spinBox_fontSize->value();
    confInfo->fontEnglish = ui->label_fontEnglish->text();
    confInfo->fontChinese = ui->label_fontChinese->text();
    //配色选项
    //目前只支持选择
    //终端
    if (infoDisplay->isChecked()) {
        confInfo->infoDisplay = 1;
    } else {
        confInfo->infoDisplay = 0;
    }

    if (historyDisplay->isChecked()) {
        confInfo->historyDisplay = 1;
    } else {
        confInfo->historyDisplay = 0;
    }

    if (commandDisplay->isChecked()) {
        confInfo->commandDisplay = 1;
    } else {
        confInfo->commandDisplay = 0;
    }

    if (conectStatsDisplay->isChecked()) {
        confInfo->conectStatsDisplay = 1;
    } else {
        confInfo->conectStatsDisplay = 0;
    }

    if (ui->comboBox_mouseRightClick->currentIndex() == 0) {
        confInfo->mouseRightClick = 0;
    } else if (ui->comboBox_mouseRightClick->currentIndex() == 1) {
        confInfo->mouseRightClick = 1;
    }

    if (ui->comboBox_mouseWheelClick->currentIndex() == 0) {
        confInfo->mouseWheelClick = 0;
    } else if (ui->comboBox_mouseWheelClick->currentIndex() == 1) {
        confInfo->mouseWheelClick = 1;
    }

    if (ui->comboBox_background->currentIndex() == 0) {
        confInfo->background = 0;
    } else if (ui->comboBox_background->currentIndex() == 1) {
        confInfo->background = 1;
    } else if (ui->comboBox_background->currentIndex() == 2) {
        confInfo->background = 2;
    }

    confInfo->currentBackground = ui->lineEdit_currentBackground->text();
    // confInfo.currentColor
    // confInfo.backgroundTransparency
    // confInfo.pictureList
    confInfo->writeSettingConf();
}

void settingwidget::on_toolButton_recover_clicked()
{
    //恢复读取confInfo
    //启动选项
    if (confInfo->selfStart == 1) {
        selfStart->setChecked(true);
    } else {
        selfStart->setChecked(false);
    }
    
    if (confInfo->trayDisplay == 1) {
        trayDisplay->setChecked(true);
    } else {
        trayDisplay->setChecked(false);
    }

    if (confInfo->startMode == 0) {
        ui->comboBox_startMode->setCurrentIndex(0);
    } else if (confInfo->startMode == 1) {
        ui->comboBox_startMode->setCurrentIndex(1);
    } else if (confInfo->startMode == 2) {
        ui->comboBox_startMode->setCurrentIndex(2);
    }

    ui->spinBox_startPositionX->setValue(confInfo->startPositionX);
    ui->spinBox_startPositionY->setValue(confInfo->startPositionY);

    if (confInfo->startCenter == 1) {
        startCenter->setChecked(true);
    } else {
        startCenter->setChecked(false);
    }

    //外观选项
    if (confInfo->language == "cn") {
        ui->comboBox_language->setCurrentIndex(0);
    } else if (confInfo->language == "zn") {
        ui->comboBox_language->setCurrentIndex(1);
    }

    if (confInfo->topDisplay == 1) {
        topDisplay->setChecked(true);
    } else {
        topDisplay->setChecked(false);
    }

    if (confInfo->newLabelLocation == 0) {
        ui->comboBox_newLabelLocation->setCurrentIndex(0);
    } else {
        ui->comboBox_newLabelLocation->setCurrentIndex(1);
    }

    if (confInfo->labelWidth == 0) {
        ui->comboBox_labelWidth->setCurrentIndex(0);
    } else if (confInfo->labelWidth == 1) {
        ui->comboBox_labelWidth->setCurrentIndex(1);
    } else if (confInfo->labelWidth == 2) {
        ui->comboBox_labelWidth->setCurrentIndex(2);
    }

    //字体选项
    ui->spinBox_fontSize->setValue(confInfo->fontSize);
    ui->label_fontEnglish->setText(confInfo->fontEnglish);
    ui->label_fontChinese->setText(confInfo->fontChinese);

    //配色选项 只支持选择

    //终端选项
    if (confInfo->infoDisplay == 1) {
        infoDisplay->setChecked(true);
    } else {
        infoDisplay->setChecked(false);
    }

    if (confInfo->historyDisplay == 1) {
        historyDisplay->setChecked(true);
    } else {
        historyDisplay->setChecked(false);
    }

    if (confInfo->commandDisplay == 1) {
        commandDisplay->setChecked(true);
    } else {
        commandDisplay->setChecked(false);
    }

    if (confInfo->conectStatsDisplay == 1) {
        conectStatsDisplay->setChecked(true);
    } else {
        conectStatsDisplay->setChecked(false);
    }

    if (confInfo->mouseRightClick == 0) {
        ui->comboBox_mouseRightClick->setCurrentIndex(0);
    } else if (confInfo->mouseRightClick == 1) {
        ui->comboBox_mouseRightClick->setCurrentIndex(1);
    }

    if (confInfo->mouseWheelClick == 0) {
        ui->comboBox_mouseWheelClick->setCurrentIndex(0);
    } else if (confInfo->mouseWheelClick == 1) {
        ui->comboBox_mouseWheelClick->setCurrentIndex(1);
    }

    if (confInfo->background == 0) {
        ui->comboBox_background->setCurrentIndex(0);
    } else if (confInfo->background == 1) {
        ui->comboBox_background->setCurrentIndex(1);
    } else if (confInfo->background == 2) {
        ui->comboBox_background->setCurrentIndex(2);
    }

    ui->lineEdit_currentBackground->setText(confInfo->currentBackground);

}
