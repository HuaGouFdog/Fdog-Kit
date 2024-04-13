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
    explicit toolswidget(int8_t connectType, QWidget *parent = 0);
    ~toolswidget();

public slots:

private slots:


    void on_textEdit_json_source_textChanged();

    void on_textEdit_xml_source_textChanged();

private:
    Ui::toolswidget *ui;
};

#endif // TOOLSWIDGET_H
