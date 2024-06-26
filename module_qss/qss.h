#ifndef QSS_H
#define QSS_H

#include <QWidget>

namespace Ui {
class qss;
}

class qss : public QWidget
{
    Q_OBJECT

public:
    explicit qss(QWidget *parent = 0);
    ~qss();

private slots:
    void on_listWidget_status_currentRowChanged(int currentRow);

    void on_listWidget_module_currentRowChanged(int currentRow);

    void on_toolButton_button_pre1_clicked();

    void on_toolButton_button_pre2_clicked();

    void on_toolButton_button_pre3_clicked();

    void on_toolButton_button_pre4_clicked();

    void on_pushButton_save_clicked();

    void on_listWidget_moduleList_currentRowChanged(int currentRow);

private:
    Ui::qss *ui;
};

#endif // QSS_H
