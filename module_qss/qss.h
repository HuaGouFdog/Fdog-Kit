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

private:
    Ui::qss *ui;
};

#endif // QSS_H
