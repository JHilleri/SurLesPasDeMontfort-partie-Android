import QtQuick 2.0

/*!
  \qmlclass Bouton
*/
Rectangle {
    signal clicked
    property string text: ""
    id:root
    height: 60
    color: (root.enabled)?"#6e0917":"#424242"
    border.color: "#ffffff"
    border.width: 5

    Text{
        color: "#ffffff"
        text: root.text
        id:champText
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter
        anchors.fill: parent
        font.pixelSize: 30
    }

    MouseArea{
        id:mouseArea
        anchors.fill: parent
        onClicked: {root.clicked();
            console.debug("'" + root.text + "' button clicked");
        }
    }
}

