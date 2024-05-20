#include "DBManager.h"

DBManager::DBManager(QObject *parent) : QObject(parent)
{
    //insertdata("Swathi", "3", "04-01-2024");
    qDebug()<<"db constructor called"<<endl;
}

void DBManager::insertdata(int a_id,QString a_taskname, QString a_time, QString a_duedate,QString a_status)
{
   // qDebug()<<Q_FUNC_INFO<<a_taskname<< a_time<< a_duedate;

    sqlite3 *db;
    char* errMsg=nullptr;
    sqlite3_stmt *stmt;
    int rc;
    const char* dbFile = "C:/QML_Task/ToDoList_Project/task.db";
    rc=sqlite3_open(dbFile,&db);

    if(rc){
        qDebug()<<"error opening sqlite database";
    }

    // Create a table if it doesn't exist
    const char* createTableQuery = "CREATE TABLE IF NOT EXISTS task ("
                                   "id INTEGER PRIMARY KEY,"
                                   "taskname TEXT ,"
                                   "time TEXT  NOT NULL,"
                                   "duedate TEXT NOT NULL,"
                                   "status TEXT NOT NULL)";
    //  "status TEXT NOT NULL);";

    if (sqlite3_exec(db, createTableQuery, 0, 0, 0) != SQLITE_OK) {
        qDebug() << "Error creating table: " << sqlite3_errmsg(db) << endl;
        sqlite3_close(db);
    }

    // Insert data into the table
    QTime time = QTime::fromString(a_time, "h:mm AP");
    //qDebug()<<"time in qtime"<<time<<endl;
    QString formattedTime = time.toString("h:mm AP");
    const char* insertDataQuery = "INSERT INTO task (id,taskname,time,duedate,status) VALUES (?,?,?,?,'pending');";

    if (sqlite3_prepare_v2(db, insertDataQuery, -1, &stmt, 0) != SQLITE_OK) {
        qDebug() << "Error preparing statement: " << sqlite3_errmsg(db) << endl;
        sqlite3_close(db);
        //return;sqlite3_bind_text(stmt, 3, formattedTime.toUtf8().constData(), -1, SQLITE_STATIC);
    }
    int id  =sqlite3_bind_int(stmt, 1, a_id);
    sqlite3_bind_text(stmt, 2, a_taskname.toUtf8().constData(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 3, formattedTime.toUtf8().constData(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 4, a_duedate.toUtf8().constData(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 5, a_status.toUtf8().constData(), -1, SQLITE_STATIC);

    if (sqlite3_step(stmt) != SQLITE_DONE) {
        qDebug() << "Error inserting data: " << sqlite3_errmsg(db) << endl;
    }
     qDebug()<<"id of insert"<<a_id<<"a_taskname"<<a_taskname<<"time"<<formattedTime<<endl;
    qDebug() <<"Data inserted successfully." << endl;
    emit addsuccessful(a_id,a_taskname,formattedTime,a_duedate,a_status);

    // Finalize the prepared statement
    sqlite3_finalize(stmt);

    // Close the database connection
    sqlite3_close(db);
}



 void DBManager::deletedata(int a_id,QString a_status)
 {
//     sqlite3 *db;
//     char* errMsg=nullptr;
//     //sqlite3_stmt *stmt;
//     int rc;
//     const char* dbFile = "C:/QML_Task/ToDoList_Project/task.db";
//     rc=sqlite3_open(dbFile,&db);

//     if(rc){
//         qDebug()<<"error opening sqlite database";
//     }

//     // Delete data from the table based on the provided ID
//     const char *deleteDataQuery = "DELETE FROM task WHERE id = ?;";

//     sqlite3_stmt *stmt;
//     if (sqlite3_prepare_v2(db, deleteDataQuery, -1, &stmt, 0) != SQLITE_OK) {
//         qDebug() << "Error preparing statement: " << sqlite3_errmsg(db) << endl;
//         sqlite3_close(db);
//         return;
//     }

//     sqlite3_bind_int(stmt, 1, a_id);

//     if (sqlite3_step(stmt) != SQLITE_DONE) {
//         qDebug() << "Error deleting data: " << sqlite3_errmsg(db) << endl;
//         return;
//     }
//     qDebug() << "Data deleted successfully." << endl;
       emit deleteSuccessful(a_id);

//     // Finalize the prepared statement
//     sqlite3_finalize(stmt);

//     // Close the database connection
//     sqlite3_close(db);
 }

//read task
void DBManager::viewdata(QList<Task*>&mytask1, Task *task)
{
    qDebug()<<Q_FUNC_INFO<<"3";
    sqlite3 *db;
    int rc;
    const char *dbFile = "C:/QML_Task/ToDoList_Project/task.db";
    rc = sqlite3_open(dbFile, &db);

    if (rc) {
        qDebug() << "Error opening sqlite database";
        return;
    }
   mytask1.clear();
    // Select data from the table
    const char *selectDataQuery = "SELECT * FROM task;";

    sqlite3_stmt *stmt;
    if (sqlite3_prepare_v2(db, selectDataQuery, -1, &stmt, 0) != SQLITE_OK) {
        qDebug() << "Error preparing statement: " << sqlite3_errmsg(db) << endl;
        sqlite3_close(db);
        return;
    }
    while (sqlite3_step(stmt) == SQLITE_ROW) {
        task = new Task;

        task->setId(QString((const char *)sqlite3_column_text(stmt, 0)).toInt());

        task->setTaskname(QString::fromUtf8((const char *)sqlite3_column_text(stmt, 1)));

        QTime time = QTime::fromString(QString::fromUtf8((const char *)sqlite3_column_text(stmt, 2)), "h:mm AP");
        task->setTime(time.toString("h:mm AP"));
        // task->setTime(QString::fromUtf8((const char *)sqlite3_column_text(stmt, 2)));
        task->setDuedate(QString::fromUtf8((const char *)sqlite3_column_text(stmt, 3)));
        task->setStatus(QString::fromUtf8((const char *)sqlite3_column_text(stmt, 4)));
        mytask1.append(task);
        qDebug()<<"List size mytask1 in db:"<<mytask1.size();
        qDebug() <<"Id:"<< task->id()<< "Taskname: " << task->taskname() << ", Time: " << task->time() << ", DueDate: " << task->duedate();
    }
    qDebug()<<Q_FUNC_INFO<<"4";

    // Finalize the prepared statement
    sqlite3_finalize(stmt);

    // Close the database connection
    sqlite3_close(db);
}
void DBManager::insertcompletedtaskdata(int id, QString taskname, QString time, QString duedate,QString status)
{
    // Set up the SQLite database
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:/QML_Task/ToDoList_Project/task.db");

    if (!db.open()) {
        qDebug() << "Error opening SQLite database: " << db.lastError().text();
        return;
    }

    // Create the table if it does not exist
    QSqlQuery query;
    //query.exec("CREATE TABLE IF NOT EXISTS task (id INTEGER, taskname TEXT, time TEXT, duedate TEXT)");

    // Prepare and execute the INSERT query
    query.prepare("UPDATE task SET status = 'completed' WHERE id = :id");
    query.bindValue(":id", id);
    query.bindValue(":taskname", taskname);
    query.bindValue(":time", time);
    query.bindValue(":duedate", duedate);
    query.bindValue("status",status);

    if (query.exec()) {
        qDebug() << "Data updated successfully";
         emit deleteSuccessful(id);

    } else {
        qDebug() << "Error inserting data:" << query.lastError().text();
    }


    db.close();
}

void DBManager::displaycompleteddata(QList<Task*>& completedtasklist, Task *completedtask)
{
    //fetch the data from db
    qDebug() << "displaydata" << endl;
    completedtasklist.clear();
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:/QML_Task/ToDoList_Project/task.db");
    QSqlQuery query;

    if (!db.open()) {
        qDebug() << "Error opening SQLite database: " << db.lastError().text();
        return;
    }

    int rowCount=0;
    if (query.exec("SELECT * FROM task")) {
        QSqlRecord record = query.record();

        // Iterate through the results
        while (query.next()) {
            qDebug()<<"inside while" <<endl;


            //completedtask = new Task;  // Move inside the loop

            // Fetch data from the current record
            int fetchedId = query.value(record.indexOf("id")).toInt();
            qDebug() << "fetchid" << fetchedId << endl;
            QString fetchedName = query.value(record.indexOf("taskname")).toString();
           // qDebug() << "fetchname" << fetchedName << endl;
            QString fetchedTime = query.value(record.indexOf("time")).toString();
           // qDebug() << "fetchtime" << fetchedTime << endl;
            QString fetchedDuedate = query.value(record.indexOf("duedate")).toString();
           // qDebug() << "fetchduedate" << fetchedDuedate << endl;
             QString fetchedstatus = query.value(record.indexOf("status")).toString();
            if(fetchedstatus=="completed")
             {

            completedtask = new Task;
            completedtask->setId(fetchedId);
            completedtask->setTaskname(fetchedName);
            completedtask->setTime(fetchedTime);
            completedtask->setDuedate(fetchedDuedate);
            completedtask->setStatus(fetchedstatus);

            completedtasklist.append(completedtask);
          //  qDebug() << "completedList size in db:" << completedtasklist.size();

            emit taskcompletedsuccessful(fetchedId, fetchedName, fetchedTime, fetchedDuedate);
            rowCount++;
           // qDebug()<<"row"<< rowCount<<endl;

        }
            else{
                qDebug()<<"task not completed"<<endl;
            }
    }
    }
            else {
        // Handle query execution error
         qDebug() << "Query failed:" << query.lastError().text();
    }
    db.close();
}















