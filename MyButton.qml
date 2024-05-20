import QtQuick 2.0

Item {
    id:_root
    property int myButtonHeight
    property int myButtonWidth
    property string myButtonname
    signal myClicked()
    height:myButtonHeight
    width:myButtonWidth
    Rectangle{
        id:_rect1
        height:parent.height
        width:parent.width
        color: "pink"
        Text{
            id:_text
            text:myButtonname
            anchors.centerIn: parent
        }
        MouseArea{
            id:_ma
            anchors.fill: parent
            onClicked: {
                myClicked()
            }
        }
    }
}
