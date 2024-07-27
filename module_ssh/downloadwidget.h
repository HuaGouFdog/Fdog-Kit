#ifndef DOWNLOADWIDGET_H
#define DOWNLOADWIDGET_H

#include <QWidget>
#include <QProgressBar>
#include <QLabel>
#include <QSpacerItem>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QStackedLayout>
namespace Ui {
class downloadwidget;
}

class fileProgressWidget : public QWidget {
    Q_OBJECT
public:
    explicit fileProgressWidget(QString filePath = "", QString fileName = "", int fileType = -1, int64_t fileSize = 0, QWidget *parent = 0);
    void rece_file_progress_sgin(int64_t sumSize, int64_t fileSize, bool status = true);
    QWidget * widgetf;  //容器
private slots:

private:
    int id; //下载ID
    QString fileName; //下载文件名
    int64_t sumSize;  //当前下载大小
    int64_t fileSize; //总大小
    bool status;      //下载状态
    int fileType;     //上传还是下载
    QString filePath; //下载路径

    QWidget * widgetFileFata;  //容器2
    QWidget * widgetDatProgreessBarData;  //容器3
    QProgressBar *progressBar; //进度条
    QLabel * labelName; //文件名
    QLabel * labelIcon; //图标
    QLabel * labelData; //下载参数
    QSpacerItem * horizontalSpacer;

    QHBoxLayout * hLayout;
    QVBoxLayout * vLayout;
    QStackedLayout * sLayout;
};

class downloadwidget : public QWidget
{
    Q_OBJECT

public:
    explicit downloadwidget(QWidget *parent = 0);
    fileProgressWidget * fwidget;
    void createNewFile(QString filePath = "", QString fileName = "", int fileType = -1, int64_t fileSize = 0);
    void updateFileProgress(int64_t sumSize, int64_t fileSize, bool status = true);
    ~downloadwidget();

signals:
    void send_setting();
private slots:
    void on_toolButton_file_clicked();

    void on_toolButton_file_open_clicked();

    void on_toolButton_file_setting_clicked();

private:
    Ui::downloadwidget *ui;

};

#endif // DOWNLOADWIDGET_H
