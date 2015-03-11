import QtQuick 2.0

Rectangle {
    signal clicked
    property string text: ""
    id:root
    height: 50
    color: "#6e0917"

    Text{
        color: "#ffffff"
        text: root.text
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter
        anchors.fill: parent
        font.pixelSize: 30
    }

    MouseArea{
        anchors.fill: parent
        onClicked: root.clicked()
    }
}

