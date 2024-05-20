import QtQuick 2.0
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.0
Item{
    id:i1
    visible: true
    width: w1.width/1.2
    height: w1.height/1.2
    signal myclick()
    signal submit()
    Rectangle{
        id:r1
        width: i1.width/1.5
        height:i1.height/1.1
        //color: "#1a73e8"
        border.color: "black"
        border.width: 0.3
        anchors.centerIn:i1
        Rectangle{
            id:_rect1
            height:parent.height
            width:parent.width
            color: "white"
            Image {
                id: backgroundImage
                source: "qrc:/Image/istockphoto.jpg"
                anchors.fill: parent
                fillMode: Image.Stretch
                height:parent.height
                width:parent.width
                opacity:0.9

                // Text { text: "TO DO List";  color:"white";font.pixelSize: 30 ;anchors.centerIn: parent }

            }
        }

        Rectangle{
            id:r4
            height:parent.height/9
            width:parent.width/4
            radius: 6
            color: "#FFC300"
            anchors.verticalCenter: parent.verticalCenter
            anchors.left: parent.left
            anchors.leftMargin: 40
            border.color: "black"
            Text {
                id: name1
                text: qsTr("Add Task")
                anchors.centerIn: r4
            }

            MouseArea{
                anchors.fill: parent
                onClicked: {
                    console.log("add text")
                    myclick()
                }
            }

        }

        Rectangle{
            id:r5
            height:parent.height/9
            width:parent.width/4
            radius: 6
            color: "#FFC300"
            anchors.verticalCenter: parent.verticalCenter
            anchors.left: r4.right
            anchors.leftMargin: 120
            border.color: "black"
            Text {
                id: name2
                text: qsTr("View Task")
                anchors.centerIn: r5
            }

            MouseArea{
                anchors.fill: parent
                onClicked: {
                    console.log("view text")
                    submit()
                }
            }

        }
    }
}






































//ComboBox {
//            id: comboBox
//            width: 150
//            height: 30
//            anchors.left: parent
//            anchors.top: parent.top
//            anchors.topMargin: 20



//            model: ListModel {
//                id:list
//                ListElement { text: "All Lists" }
//                ListElement { text: "Work" }
//                ListElement { text: "Shopping" }
//                ListElement { text: "Personal" }


//            }

//            background: Rectangle {
//                            color: "lightblue"  // Set your desired background color
//                            border.color: "darkblue"  // Set the border color if needed
//                            radius: 5  // Optional: Set border radius for rounded corners
//                        }





//                Text {

//                   Text {
//                       id: mycombo1
//                       horizontalAlignment: Text.AlignHCenter
//                       verticalAlignment: Text.AlignVCenter
//                       font.pointSize: 20
//                       }
////                   }

//                }
//                ComboBox{
//                    id:mycombo
//                    model: ListModel{

//                        ListElement{
//                            text:"AllList"
//                        }

//                        ListElement{
//                            text:"Personal"
//                        }

//                        ListElement{
//                            text:"Work"
//                        }
//                    }
//                }

//                ComboBox {
//                            id: comboBox
//                            width: 150
//                            height: 30
//                            anchors.left: parent
//                            anchors.top: parent.top
//                            anchors.topMargin: 20






//                                        model: ListModel {
//                                            ListElement { text: "Option 1" }
//                                            ListElement { text: "Option 2" }
//                                            ListElement { text: "Option 3" }
//                                        }
//                            background: Rectangle {
//                                            color: "lightblue"  // Set your desired background color
//                                            border.color: "darkblue"  // Set the border color if needed
//                                            radius: 5  // Optional: Set border radius for rounded corners
//                                        }



