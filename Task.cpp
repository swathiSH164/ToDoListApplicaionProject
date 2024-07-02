#include "Task.h"

Task::Task(QObject *parent) : QObject(parent)
{

}

QString Task::taskname() const
{
    return m_taskname;
}

void Task::setTaskname(const QString &taskname)
{
    m_taskname = taskname;
   // qDebug()<< m_taskname<<endl;
}

QString Task::duedate() const
{
    return m_duedate;
}

void Task::setDuedate(const QString &duedate)
{
    m_duedate = duedate;
    //qDebug()<< m_duedate<<endl;
}

QString Task::time() const
{
    return m_time;
}

void Task::setTime(const QString &time)
{
    m_time = time;
   //qDebug()<<"check time from ui"<<m_time <<endl;
}

int Task::id() const
{
    return m_id;
}

int Task::add(int a ,int b)
{
    return a+b;
}



void Task::setId(int newId)
{
    m_id = newId;
    //qDebug()<<"id"<<m_id<<endl;
}

QString Task::status() const
{
    return m_status;
}

void Task::setStatus(const QString &newStatus)
{
    m_status = newStatus;
}
