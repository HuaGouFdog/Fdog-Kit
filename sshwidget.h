#ifndef SSHWIDGET_H
#define SSHWIDGET_H

#include <QWidget>
#include "createconnect.h"
#include "sshhandle.h"
#include "datahandle.h"
#include <QKeyEvent>
#include <QObject>
#include <QThread>
#include <QScrollBar>
#include <QTextEdit>
#include <QClipboard>
#include <QInputMethodEvent>
#include "findwidget.h"
#include "downloadwidget.h"
#include "mkdirfolderwidget.h"
#include "addcommondwidget.h"

class CustomTextEdit : public QTextEdit {
    Q_OBJECT
public:
    CustomTextEdit(QWidget *parent = nullptr) : QTextEdit(parent) {}

signals:
    void send_mousePress_sign();
    void send_paste_sgin();
    void send_resize_sign();

protected:
    void mousePressEvent(QMouseEvent *event) override
    {
        if (event->button() == Qt::LeftButton) {
            //qDebug() << "Mouse pressed inside QTextEdit!";
            emit send_mousePress_sign();
        } else if (event->button() == Qt::RightButton) {
            //如果有选中，则复制，无选中则粘贴
            QString copyData = this->textCursor().selectedText();
            if (copyData == "") {
                //粘贴
                emit send_paste_sgin();
            } else {
                //复制
                qDebug() << "Mouse RightButton QTextEdit! = " << this->textCursor().selectedText();
                QClipboard *clipboard = QApplication::clipboard();
                clipboard->setText(copyData);
                QTextCursor cursor = this->textCursor();
                cursor.clearSelection();
                this->setTextCursor(cursor);
                qDebug() << "Mouse RightButton QTextEdit! = " << this->textCursor().selectedText();
            }

            emit send_mousePress_sign();
        }

        // 将事件传递给父类的实现
        QTextEdit::mousePressEvent(event);
    }

    void resizeEvent(QResizeEvent *event) override
    {
        QTextEdit::resizeEvent(event);
        emit send_resize_sign();
        QTextEdit::resizeEvent(event);
    }

private:
    QPoint startPos;
    QPoint endPos;
};


class KeyFilter : public QObject
{
    Q_OBJECT
public:
    KeyFilter(QObject *parent = nullptr) : QObject(parent) {}

signals:
    void send_enter_sign();
    void send_tab_sign(int type);
    void send_backSpace_sign(int type);
    void send_key_sign(QString key);
protected:
    bool eventFilter(QObject *obj, QEvent *event) override
    {
        //KeyPress 处理键盘事件 InputMethod 处理输入法事件
        if (event->type() == QEvent::KeyPress)
        {
            QKeyEvent *keyEvent = static_cast<QKeyEvent *>(event);

            if (keyEvent->key() == Qt::Key_Up) {
                qDebug() << "Up key pressed";
                emit send_key_sign("\u001B[A");
                return true;
            } else if (keyEvent->key() == Qt::Key_Down) {
                qDebug() << "Down key pressed";
                emit send_key_sign("\u001B[B");
                return true;
            } else if (keyEvent->key() == Qt::Key_Left) {
                emit send_key_sign("\u001B[D");
                //qDebug() << "Left key pressed";
                return true;
            } else if (keyEvent->key() == Qt::Key_Right) {
                emit send_key_sign("\u001B[C");
                //qDebug() << "Right key pressed";
                return true;
            }

            QString key = keyEvent->text();
            qDebug() << "Pressed key:" << key;
            emit send_key_sign(key);
            return true;
        } else if (event->type() == QEvent::InputMethod) {
            QInputMethodEvent *keyEvent = dynamic_cast<QInputMethodEvent *>(event);
            QString strInput =  keyEvent->commitString();

            if (strInput.length() == 0) {
               return true;
            }
            qDebug() << "输入法事件:" << strInput;
            emit send_key_sign(strInput);
            return true;
        }
        return QObject::eventFilter(obj, event);
    }
};

class MouseFilter : public QObject
{
    Q_OBJECT
public:
    MouseFilter(QObject *parent = nullptr) : QObject(parent) {}

signals:
    void send_focus_sign();

protected:
    bool eventFilter(QObject *obj, QEvent *event) override
    {
        qDebug() << "Mouse clicked inside QTextEdit!" << event->type();
        if (event->type() == QEvent::MouseButtonPress) {
            QMouseEvent *mouseEvent = static_cast<QMouseEvent *>(event);
            qDebug("Mouse clicked inside QTextEdit! 1");
            if (mouseEvent->button() == Qt::LeftButton) {
                qDebug("Mouse clicked inside QTextEdit!");
                // 获取 QTextEdit 控件
                QTextEdit *textEdit = qobject_cast<QTextEdit *>(obj);

                // 获取 QTextEdit 控件的矩形区域
                QRect textEditRect = textEdit->rect();

                // 判断鼠标点击是否在 QTextEdit 控件的范围内
                if (textEditRect.contains(mouseEvent->pos())) {
                    qDebug("Mouse clicked inside QTextEdit!");
                }
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
    //发送上传命令
    void sendUploadCommandData(QString local_file_path, QString remote_file_path);
    //设置终端窗口大小
    void setTerminalSize(int height, int width);

    void sendData(QString data);

    void setData(QString data);

signals:
    void send_toolButton_toolkit_sign();
    void send_toolButton_fullScreen_sign();
private slots:
    void on_textEdit_cursorPositionChanged();

    void rece_init();
    //接收命令
    void rece_channel_read(QString data);
    void rece_channel_readS(QStringList data);

    void rece_key_sign(QString key);

    void rece_getServerInfo(ServerInfoStruct serverInfo);

    void on_pushButton_clicked();

    void on_textEdit_selectionChanged();

    //void on_textEdit_5_cursorPositionChanged();

    //void on_textEdit_s_cursorPositionChanged();

    //void on_textEdit_6_cursorPositionChanged();

    void scrollBarValueChanged(int value);
    void scrollBarValueChanged2(int value);

    void on_textEdit_textChanged();

    void rece_send_mousePress_sign();

    void rece_paste_sgin();

    void rece_resize_sign();

    void on_toolButton_toolkit_clicked();

    void on_toolButton_upload_clicked();

    void on_toolButton_fullScreen_clicked();

    void on_toolButton_find_clicked();

    void on_tabWidget_customContextMenuRequested(const QPoint &pos);

    void rece_addCommond_sgin();

    void rece_mkdirFolder_sgin();

    void on_toolButton_command_clicked();

    void on_toolButton_info_clicked();

    void on_toolButton_history_clicked();

private:
    Ui::sshwidget *ui;
    int lineNumber;         //记录行号
    int columnNumber;       //记录列数
    QThread * thread;
    QThread * threadExec;
    sshhandle * m_sshhandle;
    sshHandleExec * sshExec;
    QThread * thread2;
    sshhandle * m_sshhandle2;
    KeyFilter *keyFilter;
    MouseFilter * mouseFilter;
    QString commond; //记录最后一次
    QString commond2;
    QString commond3;
    QString tabCommond;
    int isDTab = 0;
    int lastCommond = 0;
    bool movePos; //是否可以移动光标

    QScrollBar *scrollBar_textEdit = NULL;
    QScrollBar *scrollBar_textEdit_s = NULL;
    CustomTextEdit *textEdit_s;
    findwidget * fwidget = NULL;
    downloadwidget * dlwidget = NULL;
    historycommondwidget * hcwidget = NULL;

    QString lastCommondS; //上一条命令
    QString ssh_path; //当前工作目录
    QString ZData;    //主缓存区数据
    QString BData;    //备缓存区数据

    int lineCount = 80;    //当前终端行数
    int columnCount = 24;  //当前终端列数

    QTextCursor cursor_s;
    QTextCharFormat originalFormat_s;

    int a = 0;

    //处理退格
    bool isChinese = false; //是否中文
    int ChineseBackspaceSum = 0; //记录中文退格

    //处理退格删除
    bool isDeleteChinese = false; //是否中文
    int ChineseBackspaceDeleteSum = 0; //记录中文退格

    //处理右移
    bool isRightShiftChinese = false; //是否中文
    int ChineseRightShiftSum = 0; //记录中文退格


    bool isEnter = false;   //是否回车状态

};

#endif // SSHWIDGET_H
