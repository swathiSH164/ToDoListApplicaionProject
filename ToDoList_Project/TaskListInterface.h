#ifndef TASKLISTINTERFACE_H
#define TASKLISTINTERFACE_H
#include <QAbstractListModel>
#include "TaskModel.h"
#include "TaskModelList.h"

class TaskListInterface:public QAbstractListModel
{
    Q_OBJECT
public:
    TaskListInterface();

    enum {
        IdRole,
        TasknameRole,
        DuedateRole,
        TimeRole
    };
    // QAbstractItemModel interface
public:
    int rowCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;
    QHash<int, QByteArray> roleNames() const;
   // QList<Task *> listcompltetask() const;

public slots:

    void taskcompleted(int,QString,QString,QString);
    void ondata();
    void completetask();

private:
    QList<Task*> m_listcompltetask;
    TaskModel *model;
   // Q_PROPERTY(QList<Task *> listcompltetask READ listcompltetask CONSTANT FINAL)
};

#endif // TASKLISTINTERFACE_H
