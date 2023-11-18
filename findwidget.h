#ifndef FINDWIDGET_H
#define FINDWIDGET_H

#include <QWidget>

namespace Ui {
class findwidget;
}

class findwidget : public QWidget
{
    Q_OBJECT

public:
    explicit findwidget(QWidget *parent = 0);
    ~findwidget();

signals:
    void send_toolButton_file_sgin();

private slots:
    void on_toolButton_file_clicked();

    void on_toolButton_close_clicked();

private:
    Ui::findwidget *ui;
};

#endif // FINDWIDGET_H
