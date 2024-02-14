#include "TaskManager.h"

TaskManager::TaskManager(QObject *parent)
    : QObject{parent}
{
    qDebug()<<"taskmanager constructor called"<<endl;
    modellist=new TaskModelList;
    tasklist=new  TaskListInterface;
}

TaskModelList *TaskManager::getModellist() const
{
   // qDebug()<<"add in modelllist"<<endl;
    return modellist;
}

TaskListInterface *TaskManager::getTasklist() const
{
    return tasklist;
}

void TaskManager::setModellist(TaskModelList *newModellist)
{
    if (modellist == newModellist)
        return;
    modellist = newModellist;
    emit modellistChanged();
}

void TaskManager::setTasklist(TaskListInterface *newTasklist)
{
    if (tasklist == newTasklist)
        return;
    tasklist = newTasklist;
    emit tasklistChanged();
}

void TaskManager::resetTasklist()
{
    // Implement the logic to reset the tasklist property
    // For example:
    setTasklist(nullptr);
}
