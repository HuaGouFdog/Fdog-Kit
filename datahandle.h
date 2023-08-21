#ifndef DATAHANDLE_H
#define DATAHANDLE_H
#pragma execution_character_set("utf-8")
#include <QString>
#include <QObject>
class datahandle : public QObject
{
    Q_OBJECT
public:
    explicit datahandle(QObject *parent = nullptr);
    QString processData(QString data);

signals:

public slots:
};

#endif // DATAHANDLE_H
