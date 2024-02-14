import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15

Item{
    id:i
    signal back()
    signal show()
    signal taskdeleted(string taskName, string dueDate, string time)
    signal completetask()
    Image{
        height:parent.height
        width:parent.width
        source:"qrc:/Image/purplecolor.jpg"

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
            model: taskmanager.modellist
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
                    CheckBox{
                        id:chk
                        onClicked: {
                            if(chk.checked)
                            {

                                //console.log("inside checkbox",id,taskname,duedate,time)
                                deleteConfirmationDialog.open()
                                //console.log("outside checkbox",id,taskname,duedate,time)
                               taskmanager.tasklist.taskcompleted(id,taskname,time,duedate);
                               taskmanager.modellist.deleteid(id)
                            }
                        }
                    }
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

        Dialog {
            id: deleteConfirmationDialog
            title: "Complete Task Sucessfully"
            standardButtons: Dialog.Ok
        }

        GridLayout{
             rows:1
             columns:2
             anchors.fill: parent

        Button{
            id:b1
            height:50
            width:150
            text: "Back"
            // anchors.bottom: parent.bottom
            // anchors.bottomMargin: 100
            // anchors.topMargin: 300
            // anchors.top: parent.top
            // anchors.centerIn: parent
            onClicked: {
                back()
            }

        }

        Button{
            id:b2
            height:50
            width:150
            text: "show"
            // anchors.left: parent.left
            // anchors.bottomMargin: 300
            // anchors.topMargin: 400
            // anchors.top: parent.top
            // anchors.centerIn: parent
            onClicked: {
                show()
            }

        }
    }//from another db =>  read the data from db
}
}



