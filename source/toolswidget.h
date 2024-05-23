#ifndef TOOLSWIDGET_H
#define TOOLSWIDGET_H

#include <QWidget>

namespace Ui {
class toolswidget;
}

class toolswidget : public QWidget
{
    Q_OBJECT

public:
    explicit toolswidget(QWidget *parent = 0);
    explicit toolswidget(int8_t connectType, QWidget *parent = 0);
    ~toolswidget();

public slots:

private slots:

    void on_textEdit_xml_source_textChanged();

    void on_plainTextEdit_json_source_textChanged();

    void on_toolButton_25_clicked();

    void on_textEdit_textChanged();

    void on_toolButton_encipher_clicked();

    void on_toolButton_clear_clicked();

    void on_toolButton_32Lower_10_clicked();

    void on_toolButton_32_10_clicked();

    void on_toolButton_16Lower_10_clicked();

    void on_toolButton_16_10_clicked();

private:
    Ui::toolswidget *ui;
};

#endif // TOOLSWIDGET_H
