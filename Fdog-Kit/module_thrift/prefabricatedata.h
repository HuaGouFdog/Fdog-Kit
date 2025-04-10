#ifndef PREFABRICATEDATA_H
#define PREFABRICATEDATA_H

#include <QWidget>
#include <QTextCodec>
#include <QDebug>
#include <QByteArray>
namespace Ui {
class prefabricatedata;
}

class prefabricatedata : public QWidget
{
    Q_OBJECT

public:
    explicit prefabricatedata(QWidget *parent = nullptr);
    ~prefabricatedata();

    void openPreFile();
    void openPreFile2();
    void printHex(const QByteArray &data);
    void writePreFile();
    QString  detectEncoding(const QByteArray &data);

signals:
    void send_reReadData();
private slots:
    void on_toolButton_recover_clicked();

    void on_toolButton_save_clicked();

private:
    Ui::prefabricatedata *ui;
};

#endif // PREFABRICATEDATA_H
