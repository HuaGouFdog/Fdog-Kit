#ifndef CREATECONNECT_H
#define CREATECONNECT_H

#include <QWidget>
#include "createconnect.h"
#define SSH_CONNECT_TYPE 1
#define ZK_CONNECT_TYPE 2
#define REDIS_CONNECT_TYPE 3
#define KAFKA_CONNECT_TYPE 4
#define DB_CONNECT_TYPE 5
struct connnectInfoStruct
{
    int8_t connectType;
    QString name;
    QString host;
    QString port;
};

namespace Ui {
class createconnect;
}

class createconnect : public QWidget
{
    Q_OBJECT

public:
    explicit createconnect(int8_t connectType, QWidget *parent = 0);
    ~createconnect();

signals:
    void newCreate(connnectInfoStruct &);
    void newClose();

private slots:
    void on_pushButton_connect_clicked();

    void on_pushButton_close_clicked();

private:
    Ui::createconnect *ui;
    int8_t connectType = 0;
};

#endif // CREATECONNECT_H
