#ifndef TASKMODEL_H
#define TASKMODEL_H
#include "Task.h"
#include "DBManager.h"
#include <QDate>
#include <QObject>
#include <QTimer>

class TaskModel : public QObject
{
    Q_OBJECT
public:
    explicit TaskModel(QObject *parent = nullptr);
    QList<Task *> getMytask() const;
    void setMytask(const QList<Task *> &newMytask);
    void deleteTask(int);
    void Segregatetargetdatetime();
    QString formatDateString(const QString &input);

    QDateTime alarmTime;

    QList<Task *> getCompletetasklist() const;
    void setCompletetasklist(const QList<Task *> &newCompletetasklist);

signals:
    void  datachanged();
    void  showdatachange();
    void senddate();
    void data();
public slots:
    void addTask(int a_id,QString a_name,QString a_time,QString a_date);
    void viewTask();
    void showcompletedtask();
    void onDeleteSuccessful(int);
    void onAddSuccessful(int ,QString,QString,QString,QString);
    void completeTask(int taskid,QString taskname,QString time,QString duedate);
    void oncompletetasksuccessful(int id,QString taskname,QString time,QString duedate);

private:
   //Task *task;
   // Task *completetask;
    DBManager *db;
    QList<Task*> mytask;
    QList<Task*>completetasklist;
};

#endif // TASKMODEL_H
