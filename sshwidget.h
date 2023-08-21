#ifndef SSHWIDGET_H
#define SSHWIDGET_H

#include <QWidget>
#include "createconnect.h"
#include "sshhandle.h"
#include "datahandle.h"
#include <QKeyEvent>
#include <QObject>
#include <QThread>

class KeyFilter : public QObject
{
    Q_OBJECT
public:
    KeyFilter(QObject *parent = nullptr) : QObject(parent) {}

signals:
    void send_enter_sign();


protected:
    bool eventFilter(QObject *obj, QEvent *event) override
    {
        if (event->type() == QEvent::KeyPress)
        {
            QKeyEvent *keyEvent = static_cast<QKeyEvent *>(event);
            if (keyEvent->key() == Qt::Key_Up || keyEvent->key() == Qt::Key_Down) {
                return true;  // 拦截方向键按下事件，不传递给 QTextEdit
            }
            if (keyEvent->key() == Qt::Key_Enter || keyEvent->key() == Qt::Key_Return) {
                qDebug() << "回车";
                emit send_enter_sign();
                return true;
            }
        }

        return QObject::eventFilter(obj, event);
    }
};

namespace Ui {
class sshwidget;
}

class sshwidget : public QWidget
{
    Q_OBJECT

public:
    explicit sshwidget(connnectInfoStruct& cInfoStruct, QWidget *parent = 0);
    ~sshwidget();

    //发送命令
    void sendCommandData(QString data);

private slots:
    void on_textEdit_cursorPositionChanged();

    void rece_init();
    //接收命令
    void rece_channel_read(QString data);

    void rece_enter_sign();

    void on_pushButton_clicked();

private:
    Ui::sshwidget *ui;
    int lineNumber;         //记录行号
    int columnNumber;       //记录列数
    QThread * thread;
    sshhandle * m_sshhandle;
    QThread * thread2;
    sshhandle * m_sshhandle2;
    KeyFilter *keyFilter;
};

#endif // SSHWIDGET_H
