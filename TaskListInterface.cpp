#include "TaskListInterface.h"

TaskListInterface::TaskListInterface()
{
    qDebug()<<"task interface"<<endl;
    completetask();

}

int TaskListInterface::rowCount(const QModelIndex &parent) const
{
    return m_listcompltetask.count();
}

QVariant TaskListInterface::data(const QModelIndex &index, int role) const
{
    if(role==0)
    {
        return QString::number(m_listcompltetask.at(index.row())->id());
    }
    if(role==1)
    {
        return  m_listcompltetask.at(index.row())->taskname();
    }
    if(role==2)
    {
        return m_listcompltetask.at(index.row())->time();
    }
    if(role==3)
    {
        return m_listcompltetask.at(index.row())->duedate();
    }
}

QHash<int, QByteArray> TaskListInterface::roleNames() const
{

    QHash<int, QByteArray> roles;
    roles[IdRole] = "id";
    roles[TasknameRole] = "taskname";
    roles[DuedateRole] = "duedate";
    roles[TimeRole] = "time";
    return roles;
}

// QList<Task *> TaskListInterface::listcompltetask() const
// {
//     qDebug()<<"listcompletedtask function"<<endl;
// }


void TaskListInterface::taskcompleted(int a_taskid, QString name, QString time, QString duedate)
{

    qDebug()<<"taskinterface task complete"<<a_taskid<<name<<time<<duedate<<endl;
    model->completeTask(a_taskid,name,time,duedate);
    model->showcompletedtask();
    // qDebug()<<Q_FUNC_INFO<<"7";
    //m_listTasks.clear();
    m_listcompltetask=model->getCompletetasklist();
        //m_showtasklist=m_listcompltetask;
        //qDebug()<< "view model completetask list size : "<< m_listTasks.size();

    // for(int i=0;i< m_listTasks.size();i++)
    // {
    //     qDebug()<<"view1"<< m_listTasks.at(i)->id()<<endl;
    //     qDebug()<<"view2"<< m_listTasks.at(i)->taskname()<<endl;
    //     qDebug()<<"view3"<< m_listTasks.at(i)->time()<<endl;
    // }
}

void TaskListInterface::ondata()
{
    qDebug()<<"ondata"<<endl;
    beginResetModel();
    m_listcompltetask=model->getMytask();
    endResetModel();
}
void TaskListInterface::completetask()
{
    qDebug()<<"inside complete task function"<<endl;
    model=new TaskModel;
    model->showcompletedtask();
    qDebug()<<"9.1"<<endl;
    m_listcompltetask=model->getMytask();
    qDebug()<<"10"<<endl;
    connect(model,&TaskModel::data,this,&TaskListInterface::ondata);
}

