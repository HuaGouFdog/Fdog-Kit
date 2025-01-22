#ifndef SSHWIDGET_H
#define SSHWIDGET_H

#include <QWidget>
#include "module_connect/createconnect.h"
#include "module_ssh/sshhandle.h"
#include "module_ssh/datahandle.h"
#include <QKeyEvent>
#include <QObject>
#include <QThread>
#include <QScrollBar>
#include <QTextEdit>
#include <QPlainTextEdit>
#include <QClipboard>
#include <QTextCursor>
#include <QInputMethodEvent>
#include "module_ssh/findwidget.h"
#include "module_ssh/downloadwidget.h"
#include "module_ssh/mkdirfolderwidget.h"
#include "module_ssh/addcommondwidget.h"
#include "module_utils/config.h"
#include "module_utils/utils.h"
class CustomPlainTextEdit : public QPlainTextEdit {
    Q_OBJECT
public:
    CustomPlainTextEdit(QWidget *parent = nullptr) : QPlainTextEdit(parent) {}

signals:
    void send_mousePress_sign();
    void send_paste_sgin();
    void send_resize_sign();

protected:
    void mousePressEvent(QMouseEvent *event) override
    {
//        if (event->button() == Qt::LeftButton) {
//            //qDebug() << "Mouse pressed inside QTextEdit!";
//            emit send_mousePress_sign();
//        } else if (event->button() == Qt::RightButton) {
//            //如果有选中，则复制，无选中则粘贴
//            QString copyData = this->textCursor().selectedText();
//            copyData.replace(QChar(0xA0), ' ');
//            if (copyData == "") {
//                //粘贴
//                emit send_paste_sgin();
//            } else {
//                //复制
//                //qDebug() << "Mouse RightButton QTextEdit! = " << this->textCursor().selectedText();
//                QClipboard *clipboard = QApplication::clipboard();
//                clipboard->setText(copyData);
//                QTextCursor cursor = this->textCursor();
//                cursor.clearSelection();
//                this->setTextCursor(cursor);
//                //qDebug() << "Mouse RightButton QTextEdit! = " << this->textCursor().selectedText();
//            }

            emit send_mousePress_sign();
//        }
        // 将事件传递给父类的实现
        QPlainTextEdit::mousePressEvent(event);
    }

    void mouseDoubleClickEvent(QMouseEvent *event) override {
        qDebug() << "双击";
        if (event->button() == Qt::LeftButton) {
            QTextCursor cursor = textCursor();

            QString text = document()->toPlainText();

            int start, end;
            start = cursor.position() - 1;
            end = cursor.position();
            getNonnullString(text, start, end);
            // //替换不可见字符
            // text.replace(QChar(0xA0), ' ');

            // text.replace(QChar(0x2028), ' ');
            // int start, end;

            // // 向前查找空格字符或行首
            // for (start = cursor.position() - 1; 
            //     start >= 0 && text.mid(start, 1) != " " && text.mid(start, 1) != "\r\n" &&
            //      text.mid(start, 1) != "\n" && text.mid(start, 1).at(0).unicode() != 0x2028; 
            //     start--)
            // {
            // }

            // // 向后查找空格字符或行尾
            // for (end = cursor.position(); 
            //     end < text.length() && text.mid(end, 1) != " " && text.mid(end, 1) != "\n" && text.mid(end, 1).at(0).unicode() != 0x2028; 
            //     end++)
            // {
            // }

            // 设置光标选中范围
            cursor.setPosition(start + 1);
            cursor.setPosition(end, QTextCursor::KeepAnchor);
            setTextCursor(cursor);
            QString a = textCursor().selectedText();
            qDebug() <<  " 选中字符" << a;

            //CoutCharacterEncoding(a);

            return;
        }

           // 如果没有找到非空字符，则继续默认的双击事件处理
           QPlainTextEdit::mouseDoubleClickEvent(event);
    }

    void resizeEvent(QResizeEvent *event) override
    {
        qDebug() << "resizeEvent 被调用";
        //QTextEdit::resizeEvent(event);
        emit send_resize_sign();
        QPlainTextEdit::resizeEvent(event);
    }

private:
    QPoint startPos;
    QPoint endPos;
};

static int mode = 1;  //1数字模式 2应用模式

static int mode_2_length = -1; 

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
                //qDebug() << "Up key pressed";
                if (mode == 2) {
                    emit send_key_sign("\u001BOA");
                } else {
                    emit send_key_sign("\u001B[A");
                }
                return true;
            } else if (keyEvent->key() == Qt::Key_Down) {
                //qDebug() << "Down key pressed";
                if (mode == 2) {
                    emit send_key_sign("\u001BOB");
                } else {
                    emit send_key_sign("\u001B[B");
                }
                
                return true;
            } else if (keyEvent->key() == Qt::Key_Left) {
                if (mode == 2) {
                    emit send_key_sign("\u001BOD");
                } else {
                    emit send_key_sign("\u001B[D");
                }
                //qDebug() << "Left key pressed";
                return true;
            } else if (keyEvent->key() == Qt::Key_Right) {
                if (mode == 2) {
                    emit send_key_sign("\u001BOC");
                } else {
                    emit send_key_sign("\u001B[C");
                }
                //qDebug() << "Right key pressed";
                return true;
            }

            QString key = keyEvent->text();
            //qDebug() << "Pressed key:" << key;
            if (key != "") {
                 emit send_key_sign(key);
            }
            return true;
        } else if (event->type() == QEvent::InputMethod) {
            QInputMethodEvent *keyEvent = dynamic_cast<QInputMethodEvent *>(event);
            QString strInput =  keyEvent->commitString();

            if (strInput.length() == 0) {
               return true;
            }
            //qDebug() << "输入法事件:" << strInput;
            if (strInput != "") {
                 emit send_key_sign(strInput);
            }
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
        //qDebug() << "Mouse clicked inside QTextEdit!" << event->type();
        if (event->type() == QEvent::MouseButtonPress) {
            QMouseEvent *mouseEvent = static_cast<QMouseEvent *>(event);
            //qDebug("Mouse clicked inside QTextEdit! 1");
            if (mouseEvent->button() == Qt::LeftButton) {
                //qDebug("Mouse clicked inside QTextEdit!");
                // 获取 QTextEdit 控件
                QPlainTextEdit *textEdit = qobject_cast<QPlainTextEdit *>(obj);

                // 获取 QTextEdit 控件的矩形区域
                QRect textEditRect = textEdit->rect();

                // 判断鼠标点击是否在 QTextEdit 控件的范围内
                if (textEditRect.contains(mouseEvent->pos())) {
                    //qDebug("Mouse clicked inside QTextEdit!");
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
    explicit sshwidget(connnectInfoStruct& cInfoStruct, config * confInfo, QString sign, QWidget *parent = 0);
    ~sshwidget();

    enum MoveMode {
        MoveAnchor,
        KeepAnchor
    };

    QWidget * createCommand(QString name, QString data, bool isLineFeed);

    //发送命令
    void sendCommandData(QString data);
    //发送上传命令
    void sendUploadCommandData(QString local_file_path, QString remote_file_path, QString fileName);
    //设置终端窗口大小
    void setTerminalSize(int height, int width);

    void sendData(QString data);

    void sendData2(QString data);

    void setData(QString data);

    //向上移动
    void movePositionUp(sshwidget::MoveMode mode = sshwidget::MoveAnchor, int n = 1);

    void movePositionUp_s(sshwidget::MoveMode mode = sshwidget::MoveAnchor, int n = 1);
    //向下移动
    void movePositionDown(sshwidget::MoveMode mode = sshwidget::MoveAnchor, int n = 1);

    void movePositionDown_s(sshwidget::MoveMode mode = sshwidget::MoveAnchor, int n = 1);
    //向左移动
    void movePositionLeft(sshwidget::MoveMode mode = sshwidget::MoveAnchor, int n = 1);

    void movePositionLeft_s(sshwidget::MoveMode mode = sshwidget::MoveAnchor, int n = 1);
    //向右移动
    void movePositionRight(sshwidget::MoveMode mode = sshwidget::MoveAnchor, int n = 1);

    void movePositionRight_s(sshwidget::MoveMode mode = sshwidget::MoveAnchor, int n = 1);
    //行开始
    void movePositionStartLine(sshwidget::MoveMode mode = sshwidget::MoveAnchor);
    //行结尾
    void movePositionEndLine(sshwidget::MoveMode mode = sshwidget::MoveAnchor);
    //文本尾
    void movePositionEnd(sshwidget::MoveMode mode = sshwidget::MoveAnchor);
    //选中文本
    QString movePositionRightSelect(sshwidget::MoveMode mode = sshwidget::MoveAnchor, int n = 1);

    QString movePositionLeftSelect(sshwidget::MoveMode mode = sshwidget::MoveAnchor, int n = 1);

    QString movePositionEndLineSelect(sshwidget::MoveMode mode = sshwidget::MoveAnchor, int n = 1);
    
    //获取选中文本
    QString getSelectText_s();

    //删除文本
    void movePositionRemoveLeftSelect(sshwidget::MoveMode mode = sshwidget::MoveAnchor, int n = 1);
    //删除文本
    void movePositionRemoveRightSelect(sshwidget::MoveMode mode = sshwidget::MoveAnchor, int n = 1);
    //删除文本
    void movePositionRemoveEndLineSelect(sshwidget::MoveMode mode = sshwidget::MoveAnchor, int n = 1);
    //删除文本
    void movePositionRemoveRight(sshwidget::MoveMode mode = sshwidget::MoveAnchor, int n = 1);
    //获取当前行位置
    int getCurrentRowPosition();

    void setCurrentRowPosition(int n);

    void setCurrentRowPositionToZero();

    int getCurrentRowPositionByLocal();

    int getCurrentRowPositionByLocal_s();

    //获取当前列位置
    int getCurrentColumnPosition();

    int getCurrentColumnPositionByLocal();

    int getCurrentColumnPositionByLocal_s();
    //获取当前列对于行尾长度
    int getTolineLength();
    //获取当前行对于底部长度

    void amendPosition();

    void sendBuffData();

    void appendData(QString data);
    void appendData_s(QString data);
    QString m_sign;
signals:
    void send_toolButton_toolkit_sign();
    void send_connection_success(sshwidget *);
    void send_connection_fail(sshwidget *);
    void send_toolButton_fullScreen_sign();
    void send_searchTextNumbers(int sn, int sum);
    void send_windowsSetting();
private slots:
    void on_textEdit_cursorPositionChanged();

    //接收命令
    void rece_channel_readS(QStringList data);

    void rece_key_sign(QString key);

    void rece_getServerInfo(ServerInfoStruct serverInfo);

    void rece_fileProgress_sgin(int64_t sum, int64_t filesize);

    void on_pushButton_clicked();

    void on_textEdit_selectionChanged();

    //void on_textEdit_5_cursorPositionChanged();

    //void on_textEdit_s_cursorPositionChanged();

    //void on_textEdit_6_cursorPositionChanged();

    void scrollBarValueChanged(int value);
    void scrollBarValueChanged2(int value);

    void on_textEdit_textChanged();

    void rece_send_mousePress_sign();

    void rece_find_sgin();

    void rece_copy_sgin();

    void rece_paste_sgin();

    void rece_pasteSelect_sgin();

    void rece_resize_sign();

    void rece_setting();

    void rece_searchTextChanged(const QString data);

    void on_toolButton_toolkit_clicked();

    void on_toolButton_upload_clicked();

    void on_toolButton_fullScreen_clicked();

    void on_toolButton_find_clicked();

    void rece_toolButton_find_clicked();

    void on_tabWidget_customContextMenuRequested(const QPoint &pos);

    void rece_addCommond_sgin();

    void rece_mkdirFolder_sgin();

    void rece_createNewFile_sgin(QString filePath = "", QString fileName = "", int fileType = -1, int64_t fileSize = 0);

    void on_toolButton_command_clicked();

    void on_toolButton_info_clicked();

    void on_toolButton_history_clicked();

    void on_toolButton_conectStats_clicked();

    void rece_downloadFile_sgin(QString fileName = "");

    void rece_ssh_init(bool isok);

    void rece_ssh_exec_init(bool isok);

    void rece_ssh_sftp_init();

    void rece_addCommond(QString name, QString data, QString oldData, bool isLineFeed);

    void rece_mkdirFolder(QString data);

    void rece_clicked_run();

    void rece_clicked_edit();

    void on_toolButton_edit_clicked();

    void on_toolButton_2_clicked();

    void on_verticalScrollBar_valueChanged(int value);


    void on_toolButton_setting_clicked();

private:
    Ui::sshwidget *ui;
    int lineNumber;         //记录行号
    int columnNumber;       //记录列数
    QThread * thread;
    QThread * threadExec;
    QThread * threadSftp;
    sshhandle * m_sshhandle;
    sshHandleExec * sshExec;
    sshHandleSftp * sshSftp;
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
    CustomPlainTextEdit *textEdit_s;
    findwidget * fwidget = NULL;
    QVector<fileProgressWidget *> fwidgetList;
    downloadwidget * dlwidget = NULL;
    historycommondwidget * hcwidget = NULL;

    addcommondwidget * addcwidget = NULL;
    mkdirfolderwidget * mkdirfwidget = NULL;

    struct commondInfo {
        QString commond;
        bool isLineFeed;
    };

    QMap<QString, commondInfo> commondList;

    QString lastCommondS; //上一条命令
    QString lastData;  //上一条返回的数据
    int backspaceSum = 0; //记录退格数
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

    bool isScrollBar = false; //是否显示滚动区

    bool isfirstR = false;

    bool isfirstR2 = false;

    int firstS = 0;
    int firstE = 0;

    int firstS2 = 0;
    int firstE2 = 0;

    int currentLine = 1;  //这个记录的是终端本身的位置

    int currentLineLocal = -1;  //这个记录的是控件本身的位置

    int currentLineC = -1;

    bool isBuffer = false;

    int scrollZone = 0;

    int clearPos = 0;
    int clearSPos = 0;

    connnectInfoStruct  cInfoStruct;

    QString buffData; //存普通数据

    int gsum = 0;

    int m_visibleLines = 0;  //当前终端高
    int m_visibleColumns = 0; //当前终端宽


};

#endif // SSHWIDGET_H
