#ifndef QSS_H
#define QSS_H

#include <QWidget>
#include <QMenu>
namespace Ui {
class qss;
}

class qss : public QWidget
{
    Q_OBJECT

public:
    explicit qss(QWidget *parent = 0);
    QMenu * menu_test;
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

    void on_listWidget_currentRowChanged(int currentRow);

    void on_listWidget_qss_currentRowChanged(int currentRow);

    void on_listWidget_status_2_currentRowChanged(int currentRow);

    void on_toolButton_table_pre1_clicked();

    void on_pushButton_save_2_clicked();

    void on_toolButton_table_pre2_clicked();

    void on_toolButton_table_pre3_clicked();

    void on_toolButton_table_pre4_clicked();

    void on_toolButton_slider_pre1_clicked();

    void on_toolButton_slider_pre2_clicked();

    void on_toolButton_slider_pre3_clicked();

    void on_toolButton_slider_pre4_clicked();

    void on_pushButton_save_3_clicked();

    void on_toolButton_customContextMenuRequested(const QPoint &pos);

    void on_toolButton_menu_pre1_clicked();

    void on_toolButton_menu_pre2_clicked();

    void on_toolButton_menu_pre3_clicked();

    void on_toolButton_menu_pre4_clicked();

    void on_pushButton_save_4_clicked();

    void on_listWidget_status_3_currentRowChanged(int currentRow);

    void on_listWidget_module_3_currentRowChanged(int currentRow);

private:
    Ui::qss *ui;
};

#endif // QSS_H
