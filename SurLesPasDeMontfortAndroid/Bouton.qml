import QtQuick 2.0

Rectangle {
    signal clicked
    property string text: ""
    id:root
    height: 60
    color: "#6e0917"
    border.color: "#ffffff"
    border.width: 5

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
        onClicked: {root.clicked()
            console.error(root.text + " clicked");
        }
    }
}

