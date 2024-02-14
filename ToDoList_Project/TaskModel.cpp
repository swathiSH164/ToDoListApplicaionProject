#include "TaskModel.h"

TaskModel::TaskModel(QObject *parent) : QObject(parent)
{

    db=new DBManager;
    qDebug()<<"1","swathi","12","1/10/2023";
    connect(db,&DBManager::deleteSuccessful,this,&TaskModel::onDeleteSuccessful);
    connect(db,&DBManager::addsuccessful,this,&TaskModel::onAddSuccessful);
    connect(db,&DBManager::taskcompletedsuccessful,this,&TaskModel::oncompletetasksuccessful);

}

void TaskModel::addTask(int a_id,QString a_name, QString a_time, QString a_date)
{
    Task *task=nullptr;
    task=new Task;
    task->setId(a_id);
    task->setTaskname(a_name);
    task->setDuedate(a_date);
    task->setTime(a_time);
    task->setStatus("pending");
    mytask.append(task);
    db->insertdata(a_id,a_name,a_time,a_date,"pending");
    emit datachanged();
    Segregatetargetdatetime();
}

void TaskModel::viewTask()
{
    qDebug()<<"viewtask function"<<endl;
    Task *task=nullptr;
    qDebug()<<Q_FUNC_INFO<<"2";
    db->viewdata(mytask, task);
    // qDebug()<<"List size :"<<mytask.size();
    // qDebug()<<Q_FUNC_INFO<<"4.1";
    for(int i=0;i<mytask.size();i++)
    {
        qDebug()<<"myid"<<mytask.at(i)->id();
        //qDebug()<<"mystatus"<<mytask.at(i)->status();
    }
}

void TaskModel::showcompletedtask()
{
    Task *completetask=nullptr;
    qDebug()<<Q_FUNC_INFO<<5.2<<endl;
    db->displaycompleteddata(completetasklist, completetask);
    //  qDebug()<<"size"<<completetasklist.size();
    // for(int i=0;i<completetasklist.size();i++)
    // {
    //     qDebug()<<"completedid"<<completetasklist.at(i)->id();
    //     //qDebug()<<"mystatus"<<mytask.at(i)->status();

    // }
}

void TaskModel::onDeleteSuccessful(int id)
{
    qDebug()<<"task model:delete data"<<endl;
    qDebug()<<"List size bdelete:"<<mytask.size();
    for(int i=0;i<mytask.size();i++)
    {
        qDebug()<<"mystatus"<<mytask.at(i)->status()<<endl;
        if(id==mytask.at(i)->id())
        {
            // qDebug()<<"------------------------myid to delete-----------------------"<<endl;
            qDebug()<<"myid to delete"<<endl;
            mytask.removeAt(i);
            // qDebug()<<"List size adelete:"<<mytask.size();
        }
    }
    emit datachanged();
}

void TaskModel::oncompletetasksuccessful(int id,QString taskname,QString time,QString duedate)
{
    qDebug()<<"complete task"<<endl;
    qDebug()<<"task done"<<endl;
    qDebug()<<"List size badded:"<<completetasklist.size();
    emit data();
}

QList<Task *> TaskModel::getCompletetasklist() const
{
    return completetasklist;
}

void TaskModel::setCompletetasklist(const QList<Task *> &newCompletetasklist)
{
    completetasklist = newCompletetasklist;
}

void TaskModel::onAddSuccessful(int id,QString taskname,QString time,QString duedate,QString status)
{
    qDebug()<<"add data sucessfully"<<endl;
    qDebug()<<"task model:added data"<<endl;
    qDebug()<<"List size badded:"<<mytask.size();
    emit showdatachange();
}

void TaskModel::completeTask(int taskid,QString taskname,QString time,QString duedate)
{
    Task *completetask=nullptr;
    QString status="pending";
    completetask=new Task;
    completetask->setId(taskid);
    completetask->setTaskname(taskname);
    completetask->setTime(time);
    completetask->setDuedate(duedate);
    completetask->setStatus("complete");
    completetasklist.append(completetask);
    qDebug()<<"complete task"<<endl;
    db->insertcompletedtaskdata(taskid,taskname,time,duedate,status);
}

QList<Task *> TaskModel::getMytask() const
{
    return mytask;
}

void TaskModel::setMytask(const QList<Task *> &newMytask)
{
    mytask = newMytask;
}

void TaskModel::deleteTask(int taskId)
{
   QString status="pending";
    for(int i=0;i<mytask.size();i++){
        if(taskId==mytask.at(i)->id())
        {
            qDebug()<<"id found in db"<<taskId<<endl;
            db->deletedata(taskId,status);//in db =>deleted
        }
        else
        {
            qDebug()<<"taskid not found"<<endl;
        }
    }
}

QString convertTo12HourFormat(const QTime& trainTime)
{
    return trainTime.toString("hh:mm AP");
}


// void TaskModel::Segregatetargetdatetime()
// {

//     QTime currentTime = QTime::currentTime();
//     qDebug()<< "currentDateTime"<<currentTime<<endl;

//        // Format in 12-hour format with AM/PM
//            QString currenttime = currentTime.toString("h:mm:ss AP");
//            qDebug() << "formattedTime" << currenttime << endl;

//     //        for (int i = 0; i < mytask.size(); i++) {
//     //            QString tasktime = mytask.at(i)->time();
//     //            QString fifteenMinDifference = QTime::fromString(tasktime, "hh:mm:ss").addSecs(-15 * 60).toString("h:mm:ss AP");
//     //            qDebug() << "15" << fifteenMinDifference << endl;

//     //            // Convert both currenttime and fifteenMinDifference to QTime for calculating the time difference
//     //            QTime currentTimeQTime = QTime::fromString(currenttime, "h:mm:ss AP");
//     //            QTime fifteenMinDifferenceQTime = QTime::fromString(fifteenMinDifference, "h:mm:ss AP");


//     //            qDebug() << "fifteenMinDifferenceQTime:" << fifteenMinDifferenceQTime << endl;
//     //        }

//     //    QTimer timer=new QTimer;
//     //   QString alarmTime = QDateTime::currentDateTime().addSecs((3 - 15) * 60);

//     //    timer.setSingleShot(true);
//     //    timer.start(alarmTime - QDateTime::currentDateTime().currentSecsSinceEpoch() * 1000);

// }




// void TaskModel::Segregatetargetdatetime()
// {
//    QDate currentDate = QDate::currentDate();//currentdate
//    QString date = currentDate.toString("dd-MM-yyyy");
//    qDebug()<<"date"<<date<<endl;
//    QTime currentTime = QTime::currentTime();//currenttime
//    qDebug()<<"current time::"<<currentTime<<endl;

//    // Check the time format
//    QString timeFormat = currentTime.toString("ap");//am
//    qDebug()<<"timeFormat"<<timeFormat<<endl; //1:06
//    bool is12HourFormat = timeFormat.contains("ap");
//    qDebug()<<"is12HourFormat"<<is12HourFormat<<endl;//1:25 am

//    QString time12Hour;
//    // Change the format if it's 24-hour
//    if (!is12HourFormat) // 1:25 am
//    {
//        time12Hour = currentTime.toString("h:mm ap");
//        time12Hour.replace("am", "AM");
//        time12Hour.replace("pm", "PM");

//        qDebug()<<"Converted 24-hour format to 12-hour format: "<<time12Hour;
//        qDebug()<<mytask.size()<<endl;
//    }
//    else
//    {
//        qDebug()<<"Time is already in 12-hour format: "<<currentTime.toString();
//        qDebug()<<mytask.size()<<endl;
//    }

//    for (int i = 0; i < mytask.size(); i++)
//    {
//        QString formattedDate = formatDateString(mytask.at(i)->duedate());
//        QString formattedTime = mytask.at(i)->time();
//        QTime taskTime = QTime::fromString(formattedTime, "h:mm AP");
//        QTime timeBefore15Min = taskTime.addSecs(-15 * 60);

//        qDebug() << "<-------------15min ------------->" << timeBefore15Min.toString("h:mm AP") << endl;

//        if (date == formattedDate && (currentTime >= timeBefore15Min && currentTime <= taskTime))
//        {
//            qDebug() << "inside2 loop" << endl;
//            //emit senddate();
//        }
//        else
//        {
//            qDebug() << "date not between given timing" << endl;
//        }
//        }
// }


void TaskModel:: Segregatetargetdatetime()
{
    QDate currentDate = QDate::currentDate();
    QString date = currentDate.toString("dd-MM-yyyy");
    qDebug() << "Date: " << date << endl;

    QTime currentTime = QTime::currentTime();
    qDebug() << "Current Time: " << currentTime.toString("h:mm AP") << endl;

    QString timeFormat = currentTime.toString("ap");
    qDebug() << "Time Format: " << timeFormat << endl;

    bool is12HourFormat = timeFormat.contains("ap");
    qDebug() << "Is 12-Hour Format: " << is12HourFormat << endl;

    for (int i = 0; i < mytask.size(); i++)
    {
        QString formattedDate = formatDateString(mytask.at(i)->duedate());
        QString formattedTime = mytask.at(i)->time();
        QTime taskTime = QTime::fromString(formattedTime, "h:mm AP");
        QTime timeBefore15Min = taskTime.addSecs(-15 * 60);

        qDebug() << "<-------------15min ------------->" << timeBefore15Min.toString("h:mm AP") << endl;

        if (date == formattedDate && (currentTime >= timeBefore15Min && currentTime <= taskTime))
        {
            qDebug() <<"Task within 15 minutes before due time:"<<endl;
            // Perform actions or emit signals as needed
        }
        else
        {
            qDebug() << "Task not within the given timing" << endl;
        }
    }
}

QString TaskModel::formatDateString(const QString &inputDate)
{
    QMap<QString, int> monthMap;
    monthMap["Jan"] = 1;
    monthMap["Feb"] = 2;
    monthMap["Mar"] = 3;
    monthMap["Apr"] = 4;
    monthMap["May"] = 5;
    monthMap["Jun"] = 6;
    monthMap["Jul"] = 7;
    monthMap["Aug"] = 8;
    monthMap["Sep"] = 9;
    monthMap["Oct"] = 10;
    monthMap["Nov"] = 11;
    monthMap["Dec"] = 12;
    // Split the input date string into parts
    QStringList dateParts = inputDate.split(" ");

    // Extract the day, month, and year from the parts
    int day = dateParts[2].toInt();
    int month = monthMap.value(dateParts[1]);
    int year = dateParts[3].toInt();

    // Create a QDate object
    QDate date(year, month, day);

    // Format the date in dd-mm-yyyy format
    return date.toString("dd-MM-yyyy");
}





































//    QTime timeBefore15Min = currentTime.addSecs(-15 * 60); // 15 minutes in seconds

//    // Display the results
//    qDebug() << "Current time: " << currentTime.toString("hh:mm");
//    QString timedate=currentTime.toString("hh:mm");
//    qDebug()<<"timedate"<<timedate<<endl;
//    qDebug() << "15minutes before: " << timeBefore15Min.toString("hh:mm");
//    QString date = currentDate.toString("dd-MM-yyyy");

//    // Print the formatted date
//    qDebug() << "Current Date in dd-mm-yy format: " << date;
