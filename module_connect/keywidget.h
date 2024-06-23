#ifndef KEYWIDGET_H
#define KEYWIDGET_H

#include <QWidget>

namespace Ui {
class keywidget;
}

class keywidget : public QWidget
{
    Q_OBJECT

public:
    explicit keywidget(QWidget *parent = 0);
    ~keywidget();

private slots:
    void on_toolButton_browse_clicked();

    void on_toolButton_cancel_clicked();

    void on_toolButton_ok_clicked();

private:
    Ui::keywidget *ui;
};

#endif // KEYWIDGET_H
