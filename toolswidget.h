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
    ~toolswidget();

public slots:
    void rece_showtimestamp();

private slots:
    void on_toolButton_clicked();

    void on_toolButton_2_clicked();

    void on_lineEdit_hex_textChanged(const QString &arg1);

    void on_lineEdit_dec_textChanged(const QString &arg1);

    void on_lineEdit_oct_textChanged(const QString &arg1);

    void on_lineEdit_bin_textChanged(const QString &arg1);

    void on_toolButton_decode_clicked();

    void on_toolButton_encode_clicked();

private:
    Ui::toolswidget *ui;
};

#endif // TOOLSWIDGET_H
