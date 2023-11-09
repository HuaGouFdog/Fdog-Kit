#ifndef COLORMATCH_H
#define COLORMATCH_H

#include <QWidget>

namespace Ui {
class colormatch;
}

class colormatch : public QWidget
{
    Q_OBJECT

public:
    explicit colormatch(QWidget *parent = 0);
    ~colormatch();

private:
    Ui::colormatch *ui;
};

#endif // COLORMATCH_H
