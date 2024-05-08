#ifndef ADDCOMMONDWIDGET_H
#define ADDCOMMONDWIDGET_H

#include <QWidget>

namespace Ui {
class addcommondwidget;
}

class addcommondwidget : public QWidget
{
    Q_OBJECT

public:
    explicit addcommondwidget(QWidget *parent = 0);
    ~addcommondwidget();

signals:
    void send_addCommond(QString, QString);

private slots:
    void on_toolButton_param1_clicked();

    void on_toolButton_param2_clicked();

    void on_toolButton_param3_clicked();

    void on_toolButton_param4_clicked();

    void on_toolButton_param5_clicked();

    void on_toolButton_param6_clicked();

    void on_toolButton_cancel_clicked();

    void on_toolButton_ok_clicked();

private:
    Ui::addcommondwidget *ui;
};

#endif // ADDCOMMONDWIDGET_H
