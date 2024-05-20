
#include "TaskModelList.h"

TaskModelList::TaskModelList()
{
    m_taskModel=new TaskModel;
    qDebug()<<Q_FUNC_INFO<<"1";
    m_taskModel->viewTask();
    qDebug()<<Q_FUNC_INFO<<"5";
    m_listTasks=m_taskModel->getMytask();
   // qDebug()<< "view model list size : "<<m_listTasks.size();
    //qDebug()<<Q_FUNC_INFO<<"6";

    connect(m_taskModel,&TaskModel::datachanged,this,&TaskModelList::ondeleteData);
    connect(m_taskModel,&TaskModel::showdatachange,this,&TaskModelList::onaddData);
    connect(m_taskModel,&TaskModel::senddate,this,&TaskModelList::ondataReceived);
    //connect(m_taskModel,&TaskModel::data,this,&TaskModelList::ondata);
}

TaskModelList::~TaskModelList()
{
   // qDebug()<<"TaskModelList desructor called"<<endl;
}


int TaskModelList::rowCount(const QModelIndex &parent) const
{
    return m_listTasks.count();
}

QVariant TaskModelList::data(const QModelIndex &index, int role) const
{
    if(role==0)
    {
        return QString::number(m_listTasks.at(index.row())->id());
    }
    if(role==1)
    {
        return  m_listTasks.at(index.row())->taskname();
    }
    if(role==2)
    {
        return  m_listTasks.at(index.row())->time();
    }
    if(role==3)
    {
        return  m_listTasks.at(index.row())->duedate();
    }
}

QHash<int, QByteArray> TaskModelList::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[IdRole] = "id";
    roles[TasknameRole] = "taskname";
    roles[DuedateRole] = "duedate";
    roles[TimeRole] = "time";
    return roles;
}

void TaskModelList::add(int a_taskid,QString a_taskname,QString a_time,QString a_duedate)
{
    //qDebug()<<"add function called"<<endl;
    qDebug()<<"time"<< a_time<<endl;
    m_taskModel->addTask(a_taskid, a_taskname,a_time,a_duedate);

}

void TaskModelList::deleteid(int a_taskid)
{
    //qDebug()<<"taskmodellist"<<a_taskid<<endl;
    m_taskModel->deleteTask(a_taskid);
}

// void TaskModelList::taskcompleted(int a_taskid, QString name,QString time,QString duedate)
// {
//     qDebug()<<"taskmodellist task complete"<<a_taskid<<name<<time<<duedate<<endl;
//     m_taskModel->completeTask(a_taskid,name,time,duedate);
//     m_taskModel->showcompletedtask();
//    // qDebug()<<Q_FUNC_INFO<<"7";
//     m_listTasks.clear();
//    m_listcompltetask=m_taskModel->getCompletetasklist();
//     //m_showtasklist=m_listcompltetask;
//     //qDebug()<< "view model completetask list size : "<< m_listTasks.size();

//    for(int i=0;i< m_listTasks.size();i++)
//     {
//         qDebug()<<"view1"<< m_listTasks.at(i)->id()<<endl;
//        qDebug()<<"view2"<< m_listTasks.at(i)->taskname()<<endl;
//         qDebug()<<"view3"<< m_listTasks.at(i)->time()<<endl;
//     }
// }

// void TaskModelList::ondata()
// {
//     qDebug()<<"ondata"<<endl;
//     beginResetModel();
//     m_listTasks=m_taskModel->getMytask();
//     endResetModel();
// }
void TaskModelList::ondeleteData()
{
    beginResetModel();
    m_listTasks=m_taskModel->getMytask();
    endResetModel();

}

void TaskModelList::onaddData()
{
    //qDebug()<<"show added data in view"<<endl;
    beginResetModel();
    m_listTasks=m_taskModel->getMytask();
    endResetModel();
}

void TaskModelList::onshowdata()
{
    beginResetModel();
    m_listTasks=m_taskModel->getMytask();
    endResetModel();
}
void TaskModelList::targetdate()
{
   // qDebug()<<"targetdate includes"<<endl;
    m_taskModel->Segregatetargetdatetime();
}

void TaskModelList::ondataReceived()
{
    //qDebug()<<"shows message"<<endl;
    emit alarmActivated();
}

//void TaskModelList::setTasks(QList<Task> *newTasks)
//{
//    m_listTasks = newTasks;
//}

