#ifndef MKDIRFOLDERWIDGET_H
#define MKDIRFOLDERWIDGET_H

#include <QWidget>

namespace Ui {
class mkdirfolderwidget;
}

class mkdirfolderwidget : public QWidget
{
    Q_OBJECT

public:
    explicit mkdirfolderwidget(QWidget *parent = 0);
    ~mkdirfolderwidget();

signals:
    void send_mkdirFolder(QString data);
private slots:
    void on_toolButton_cancel_clicked();

    void on_toolButton_ok_clicked();

private:
    Ui::mkdirfolderwidget *ui;
};

#endif // MKDIRFOLDERWIDGET_H
