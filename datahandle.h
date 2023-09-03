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
    void stringToHtmlFilter(QString &str);
    void stringToHtmlFilter2(QString &str);
    void stringToHtmlFilter3(QString &str);
    void stringToHtmlFilter4(QString &str);
    void stringToHtmlFilter5(QString &str);
    void stringToHtml(QString &str, QColor *crl);
    QString processDataStatsAndColor(QString & head, QString & commond, QString data);
    QString processData(QString data);

    int isDTab = 0;
signals:

public slots:
};

#endif // DATAHANDLE_H
