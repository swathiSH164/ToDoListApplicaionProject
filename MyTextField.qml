import QtQuick 2.0
import QtQuick.Controls 2.5
Item {
    id:_item
    property int mytextfieldHeight:0
    property int mytextfieldwidth:0
    property string mylabeltext:""
    property string myplaceholdertext: ""
    property  alias myid :_textfld
    property alias myText:_textfld.text
    height:mytextfieldHeight
    width:mytextfieldwidth
    Row{
        id:_row
        height:parent.height
        width:parent.width
        spacing:parent.width/16
        Label{
            id:_label
            text:mylabeltext
            height:parent.height
            width:parent.width/2
        }
        TextField{
            id:_textfld
            height:parent.height
            width:parent.width/2
            placeholderText:myplaceholdertext
            text : myText

        }
    }
}
