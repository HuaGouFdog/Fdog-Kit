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
    void setFindText(QString data);
    ~findwidget();

    QString gitSearchText();

signals:
    void send_toolButton_file_sgin();
    void send_searchTextChanged(const QString &arg1);
private slots:

    void on_toolButton_close_clicked();

    void on_lineEdit_search_textChanged(const QString &arg1);

    void rece_searchTextNumbers(int sn, int sum);



private:
    Ui::findwidget *ui;
};

#endif // FINDWIDGET_H
