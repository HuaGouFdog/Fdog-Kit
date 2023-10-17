#ifndef SMALLTOOLWIDGET_H
#define SMALLTOOLWIDGET_H

#include <QWidget>

namespace Ui {
class smalltoolwidget;
}

class smalltoolwidget : public QWidget
{
    Q_OBJECT

public:
    explicit smalltoolwidget(QWidget *parent = 0);
    ~smalltoolwidget();

private:
    Ui::smalltoolwidget *ui;
};

#endif // SMALLTOOLWIDGET_H
