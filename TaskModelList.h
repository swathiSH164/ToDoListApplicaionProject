
#ifndef TASKMODELLIST_H
#define TASKMODELLIST_H
#include "QAbstractListModel"
#include "Task.h"
#include "TaskModel.h"

class TaskModelList:public QAbstractListModel
{
    Q_OBJECT

public:
    TaskModelList();
    ~TaskModelList();
    enum {
        IdRole,
        TasknameRole,
        DuedateRole,
        TimeRole
    };

    int rowCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;
    QHash<int, QByteArray> roleNames() const;

    Q_INVOKABLE void add(int,QString,QString,QString);

signals:
    void deletedata();
    void addnewdata();
    void alarmActivated();
    void datareeceived();
public slots:
    void deleteid(int);
    void ondeleteData();
    void onaddData();
    void targetdate();
    void ondataReceived();
    void onshowdata();

private:
    TaskModel *m_taskModel;
    QList<Task*> m_listTasks;
};

#endif // TASKMODELLIST_H
