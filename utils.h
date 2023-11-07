#ifndef UTILS_H
#define UTILS_H

#include <QObject>
#include <QCheckBox>
#include <QLabel>
class AnimatedCheckBox : public QCheckBox
{
public:
    AnimatedCheckBox(QWidget *parent = nullptr);

protected:
    void paintEvent(QPaintEvent *event) override;
    void resizeEvent(QResizeEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;

private:
    /* AnimatedCheckBox 是否选中的指示器
        checked 为 false 时 indicator 在最左边，为 true 时 indicator 在最右边 */
    QLabel *indicator;
};

class utils : public QWidget
{
    Q_OBJECT
public:
    explicit utils(QWidget *parent = nullptr);

signals:

public slots:
};

#endif // UTILS_H
