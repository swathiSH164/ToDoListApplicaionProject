#ifndef DBMANAGER_H
#define DBMANAGER_H
#include "sqlite-amalgamation-3440000/sqlite3.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QTime>  // Add this include directive for QTime
#include <QDateTime>
#include <QDebug>
#include <QObject>
#include "Task.h"
#include <QSqlRecord>

class DBManager : public QObject
{
    Q_OBJECT
public:
    explicit DBManager(QObject *parent = nullptr);
signals:
    void deleteSuccessful(int);
    void addsuccessful(int,QString,QString,QString,QString);
    void taskcompletedsuccessful(int,QString,QString,QString);

public slots:
    void insertdata(int,QString,QString,QString,QString);
   // void taskcompleted(int,QString,QString,QString);
    void deletedata(int,QString);
    void viewdata(QList<Task*>& mytask1, Task *task);
    //void completetaskdata(int,QString,QString,QString);
    void displaycompleteddata(QList<Task*>& completedtasklist,Task *completedtask);
    void insertcompletedtaskdata(int,QString,QString,QString,QString);
private:
    //QList<DBMa>completedtask;
};

#endif // DBMANAGER_H
