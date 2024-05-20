import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 1.4
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.3

Item {
    visible: true
    width: 640
    height: 480
    signal previous()

    Rectangle{
        id:r
        height:parent.height/1.5
        width:parent.width/2
        anchors.centerIn: parent
        // color:"#C70039"
        Image{
            source: "qrc:/Image/images.jpg"
            height:parent.height
            width:parent.width
            opacity: 0.4
        }

        Column{
            id:c1
            width:parent.width
            height:parent.height
            Rectangle{
                id:r1
                width:parent.height/2
                height:parent.width/2
                color: "transparent"
                anchors.centerIn:  parent

                GridLayout{
                    rows: 5
                    columns:2
                    columnSpacing: 2


                    Label{
                        width:parent.height/8
                        height:parent.width/8
                        text:"Taskid:"
                        font.pixelSize: 20

                    }
                    TextField{
                        id:_id
                        height:r1.height/2
                        width:r1.width/2
                        placeholderText: "entertaskid"
                        anchors.centerIn:r1.Center
                    }
                    Label{
                        text:"Taskname:"
                        font.pixelSize: 20
                    }
                    TextField{
                        id:_taskname
                        placeholderText: "enter Taskname"
                        //anchors.centerIn: parent
                    }

                    Label{
                        text:"Time:"
                        font.pixelSize: 20
                    }

                    TextField{
                        id: timeTextField
                        placeholderText: "enter time"


                        MouseArea {
                            anchors.fill: parent
                            onClicked: {
                                timeDialog.open()
                            }
                        }
                    }

                    Dialog {
                        id: timeDialog
                        title: "Select Time"
                        modal: true
                        standardButtons: Dialog.Ok | Dialog.Cancel

                        Column{

                            anchors.centerIn: parent

                            Label {
                                text: "Hour:"
                            }

                            SpinBox {
                                id: hourSpinBox
                                from: 0
                                to: 23
                            }

                            Label {
                                text: "Minute:"
                            }

                            SpinBox {
                                id: minuteSpinBox
                                from: 0
                                to: 59
                            }

                            Label {
                                text: ":"
                            }

                            ComboBox {
                                id: amPmComboBox
                                model: ["AM", "PM"]
                            }

                        }

                        onAccepted: {
                            // Handle the selected time
                            var selectedTime = hourSpinBox.value + ":" + minuteSpinBox.value +" " +amPmComboBox.currentText;
                            timeTextField.text = selectedTime;
                            console.log("Selected Time: " + selectedTime);
                        }
                    }

                    Calendar {
                        id: calendar
                        width: 300
                        height: 300
                        minimumDate: new Date(2024, 0, 1)
                        maximumDate: new Date(2055, 0, 1)
                        visible: false


                        onSelectedDateChanged: {
                            //Update the TextField text when a date is selected
                            _date.text=calendar.selectedDate.toDateString("dd-MM-yyyy")
                            calendar.visible = false; // Hide the calendar after a date is selected
                        }
                    }


                    Label{
                        text:"Duedate:"
                        font.pixelSize: 20
                    }
                    TextField{
                        id:_date
                        placeholderText: "enter date"
                        //anchors.centerIn: parent
                        Image{
                            id: calendarImage
                            height:50
                            width:50
                            source: "qrc:/calendar.png"
                            anchors.left: parent.left
                            anchors.leftMargin: 200

                            MouseArea{
                                anchors.fill:parent
                                onClicked: {
                                    console.log("date selected")

                                    //submit();
                                    calendar.visible = !calendar.visible
                                }
                            }
                        }
                    }

                    Row{
                        height:parent.height/2
                        width:parent.width/2
                        spacing :50
                        Rectangle{
                            height:50
                            width:90
                            anchors.left:r1.left
                            anchors.leftMargin: 150
                            radius:10

                            color: "#FFC300"
                            border.color: "black"
                            border.width:3
                            Text {
                                id: name
                                text: qsTr("Submit")
                                color:"black"
                                anchors.centerIn: parent

                            }
                            MouseArea{
                                anchors.fill: parent
                                onClicked: {
                                    console.log("submitted", _id.text , timeTextField.text)
                                   taskmanager.modellist.add(_id.text,_taskname.text, timeTextField.text,_date.text);
                                    successDialog.open()
                                }
                            }

                            Dialog {
                                id: successDialog
                                Text{
                                    text:"Task added succesfully"
                                }
                                standardButtons: Dialog.Ok

                                onAccepted: console.log("Ok clicked")
                                // onRejected: console.log("Cancel clicked")
                            }


                        }

                        Rectangle{
                            height:50
                            width:90
                            border.color: "black"//11:10=>1:10   //7 to 9
                            border.width:3
                            radius:10
                            color: "#FFC300"

                            Text {
                                id: name1
                                text: qsTr("Back")
                               anchors.centerIn: parent

                            }

                            MouseArea
                            {
                                anchors.fill:parent
                                onClicked:{
                                    console.log("back button")
                                    previous()
                                }
                            }

                        }

                    }
                }
            }
        }

    }

}





























































//import QtQuick 2.0
//import QtQuick.Controls 1.4
//import QtQuick.Controls 2.15

//Rectangle {
//    width:w1.width
//    height: w1.height
//    color: "#1a73e8"
//    //    signal submit()
//    signal previous()
//    Rectangle{
//        height: parent.height/2
//        width:parent.width/2
//        color: "transparent"
//        anchors.centerIn: parent
//        Column{
//            id:_column
//            anchors.fill: parent
//            spacing:parent.height/18
//            MyTextField{
//                id:_id
//                mytextfieldHeight: parent.height/8
//                mytextfieldwidth: parent.width
//                mylabeltext:"Taskid:"
//                myplaceholdertext: "enter Taskid"
//            }
//            MyTextField{
//                id:_taskname
//                mytextfieldHeight: parent.height/8
//                mytextfieldwidth: parent.width
//                mylabeltext:"Taskname:"
//                myplaceholdertext: "enter Taskname"
//            }

//            MyTextField{
//                id:_time
//                mytextfieldHeight: parent.height/8
//                mytextfieldwidth: parent.width
//                mylabeltext:"Time:"
//                myplaceholdertext: "enter time"
//            }

//            Calendar {
//                id: calendar
//                width: 300
//                height: 300
//                minimumDate: new Date(2024, 0, 1)
//                maximumDate: new Date(2055, 0, 1)
//                visible: false

//                onVisibleChanged: {
//                    if (visible) {
//                        // Position the calendar next to the image
//                        calendar.x = calendarImage.x + calendarImage.width
//                        calendar.y = calendarImage.y
//                    }
//                }

//                onSelectedDateChanged: {
//                    // Update the TextField text when a date is selected
//                    _date.text=calendar.selectedDate.toDateString("dd-MM-yyyy")
//                    calendar.visible = false; // Hide the calendar after a date is selected
//                }
//            }


//            Row{
//                id:_row
//                height:parent.height
//                width:parent.width
//                spacing:parent.width/16

//                Label{
//                    id:_label
//                    text:  "Duedate:"
//                    height:parent.height
//                    width:parent.width/2
//                }
//                TextField{
//                    id:_date
//                    //                mytextfieldHeight: parent.height/8
//                    //                mytextfieldwidth: parent.width
//                    //                mylabeltext:"DueDate:"
//                    //                myplaceholdertext: "enter duedate"
//                    width: parent.width/2
//                    height:parent.height/8
//                    text:mytext
//                    // anchors.centerIn:parent

//                    //anchors.leftMargin: 20

//                    Image {
//                        id: calendarImage
//                        height:28
//                        width:30
//                        source: "qrc:/Image/calendar.png"
//                        anchors.left:parent.right
//                        anchors.topMargin: 1
//                        anchors.top: parent.top

//                        MouseArea{
//                            anchors.fill:parent
//                            onClicked: {
//                                console.log("date selected")

//                                //submit();
//                                calendar.visible = !calendar.visible
//                            }
//                        }
//                    }
//                }
//            }
//                Grid{
//                    rows:1
//                    columns: 2
//                    id:_row1
//                    height:120
//                    width:120


//                    Rectangle{

//                        id:_back
//                        height:50
//                        width:50
//                        radius:10
//                        anchors.top:_row.top
//                        anchors.topMargin: 70
//                        anchors.left:_row.right
//                        anchors.leftMargin: 30
//                        Text {
//                            id: back
//                            text: qsTr("Back")
//                        }
//                        MouseArea
//                        {
//                            anchors.fill:parent
//                            onClicked:{
//                                console.log("back button")
//                                previous()
//                            }
//                        }
//                    }

////                Row{
////                    id:row
////                    height:parent.height/8
////                    width: parent.width
////                    spacing: parent.width/7.75
////                    anchors.horizontalCenter: parent.horizontalCenter
////                    Mybutton{
////                        id:_submit
////                        myButtonHeight:parent.height
////                        myButtonWidth:parent.width/4
////                        myButtonname: "Submit"
//                    Rectangle{
//                        id:b1
//                        height:50
//                        width:100
//                        radius:10
//                        color:"white"
//                        Text {
//                            id: name
//                            text: qsTr("submit")
//                        }
//                        anchors.top: _row.top
//                        anchors.topMargin: 70

//                        MouseArea{
//                            anchors.fill: parent
//                            onClicked: {
//                                console.log("submitted", _id.myText)

//                                modellist.add(_id.myText,_taskname.myText,_time.myText,_date.text);
//                               successDialog.open()
//                            }


//                        }

//                        Dialog {
//                            id: successDialog
//                           Text{
//                               text:"data added succesfully"
//                           }
//                            standardButtons: Dialog.Ok

//                            onAccepted: console.log("Ok clicked")
//                           // onRejected: console.log("Cancel clicked")
//                        }


//                    }

//                }
//            }

//        }

//}



