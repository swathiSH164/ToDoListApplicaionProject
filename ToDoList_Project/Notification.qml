// PageB.qml
import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15

Item{
id:i
signal back1()
    Image{
        height:parent.height
        width:parent.width
        source:"qrc:/Image/completetask.jpg"
        Text {
            id: text1
            text: qsTr("Completed Task List")
            anchors.left:parent.left
            anchors.leftMargin: 150
            font.pixelSize: 20
            color: "red"
        }

        Text {
            text: "TASK LIST"
            anchors.centerIn: i.Center
            font.pixelSize: 20
        }
    }
    Rectangle{
        id:_rect
        height:parent.height/2
        width:parent.width
        anchors.centerIn: parent
        signal deletedata()
        ListView {
            id: taskListView
            anchors.fill: parent
            model: taskmanager.tasklist
            delegate:_comp
            clip:true
        }

        Component{
            id:_comp
            Rectangle{
                id:_r1
                width:_rect.width
                height:_rect.height/6
                border.color:"navy"

                Row{
                    anchors.fill: parent
                    Component.onCompleted: {
                        console.log("created with obj")
                    }
                    // Component.onDestruction: {
                    //     console.log("destroyed with obj")
                    // }

                    Item {
                        width:_r1.width
                        height:_r1.height
                        Row{
                            anchors.fill:parent
                            Rectangle{
                                height: parent.height
                                width:parent.width/4.2
                                border.color: "lightblue"
                                Text {
                                    text: id
                                    anchors.centerIn: parent
                                }

                            }
                            Rectangle{
                                height: parent.height
                                width:parent.width/4.2
                                border.color: "lightblue"
                                Text{
                                    text :taskname
                                    anchors.centerIn: parent
                                }

                            }
                            Rectangle{
                                height: parent.height
                                width:parent.width/4.2
                                border.color: "lightblue"
                                Text{
                                    text :time
                                    anchors.centerIn: parent
                                }
                            }
                            Rectangle{
                                height: parent.height
                                width:parent.width/4.2
                                border.color: "lightblue"
                                Text{
                                    text :duedate
                                    anchors.centerIn: parent
                                }
                            }

                        }
                    }

                }

            }
        }
            Button{
                id:b3
                height:50
                width:150
                text: "Back"
                anchors.bottom: parent.bottom
                anchors.bottomMargin: 100
                anchors.topMargin: 300
                anchors.top: parent.top
                anchors.centerIn: parent
                onClicked: {
                    back1()
                }

            }

        }



        }
    //from another db =>  read the data from db



























// import QtQuick 2.15
// import QtQuick.Controls 2.15

// Page {
//     id: pageB

//     // Define the ListModel for deleted tasks
//     ListModel {
//         id: deletedTasksModel
//     }



//     ListView {
//         id: deletedTasksView
//         model: deletedTasksModel  // Set the model to deletedTasksModel

//         delegate: Item {
//             Text{
//                 text: "Task id: " +model.id
//             }

//             Text {
//                 text: "Task Name: " + model.taskName
//             }

//             Text {
//                 text: "Due Date: " + model.dueDate
//             }

//             Text {
//                 text: "Time: " + model.time
//             }
//         }
//     }
// }
