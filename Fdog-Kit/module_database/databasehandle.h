#ifndef DATABASEHANDLE_H
#define DATABASEHANDLE_H

#include <QObject>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QRunnable>
class DbRunnable : public QObject, public QRunnable {
    Q_OBJECT

public:
    QSqlDatabase * m_db;

    DbRunnable(QSqlDatabase * db):m_db(db) {

    }
    ~DbRunnable() {

    }

    void run() override {
        if (m_db == nullptr) {
            qDebug("m_db is null");
            return;
        }
    }
};

class databasehandle
{
public:
    databasehandle();
};

#endif // DATABASEHANDLE_H
