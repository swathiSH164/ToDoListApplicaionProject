#ifndef TASK_H
#define TASK_H
#include <qdebug.h>
#include <QObject>

class Task : public QObject
{
    Q_OBJECT
public:
    explicit Task(QObject *parent = nullptr);

    QString taskname() const;
    void setTaskname(const QString &taskname);

    QString duedate() const;
    void setDuedate(const QString &duedate);

    QString time() const;
    void setTime(const QString &time);

    int id() const;
    void setId(int newId);

    QString status() const;
    void setStatus(const QString &newStatus);

signals:
public slots:

private:
    int m_id;
    QString m_taskname;
    QString m_duedate;
    QString m_time;
    QString m_status;
};

#endif // TASK_H
