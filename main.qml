import QtQuick 2.9
import QtQuick.Window 2.2

Window
{
    property var _w1:w1
    id:w1
    visible: true
    width: 640
    height: 480
    title: qsTr("ToDoList")

  //   function print(){
  // console.log("start")
  //  }

    Loader{
        id:loader

        anchors.fill: parent

        source: "qrc:/HomeScreen.qml"
    }

    Connections{
        target: loader.item
         ignoreUnknownSignals: true
        onMyclick:{
             print();
            loader.source="qrc:/AddTask.qml"
            console.log("start qml");
        }

        onSubmit:{
            loader.source="qrc:/Tasklist.qml"

        }
        onPrevious:{
            loader.source="qrc:/HomeScreen.qml"
        }
        onBack:{
            console.log("back button")
            loader.source="qrc:/HomeScreen.qml"
        }
        onShow:{
            console.log("show button")
            loader.source="qrc:/Notification.qml"
        }
        onTaskDeleted: {
            // Handle the deleted task information and update Page B accordingly
            deletedTasksModel.append({taskName: taskName, dueDate: dueDate, time: time});
        }
        onBack1:{
            loader.source="qrc:/HomeScreen.qml"
        }
    }
}







