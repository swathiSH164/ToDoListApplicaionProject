// TaskManager.h
#ifndef TASKMANAGER_H
#define TASKMANAGER_H

#include <QObject>
#include "TaskModelList.h"
#include "TaskListInterface.h"

class TaskManager : public QObject
{
    Q_OBJECT
    Q_PROPERTY(TaskModelList *modellist READ getModellist WRITE setModellist NOTIFY modellistChanged FINAL)
    Q_PROPERTY(TaskListInterface *tasklist READ getTasklist WRITE setTasklist RESET resetTasklist NOTIFY tasklistChanged FINAL)


public:
    explicit TaskManager(QObject *parent = nullptr);
    Q_INVOKABLE TaskModelList *getModellist() const;
    Q_INVOKABLE TaskListInterface *getTasklist() const;

    void setModellist(TaskModelList *newModellist);
    void setTasklist(TaskListInterface *newTasklist);
    void resetTasklist();
signals:
    void modellistChanged();
    void tasklistChanged();
private:
    TaskListInterface *tasklist;
    TaskModelList *modellist;  // You need to ensure these pointers are properly initialized
};
#endif // TASKMANAGER_H




