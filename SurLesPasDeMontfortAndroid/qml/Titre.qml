import QtQuick 2.0


/*!
  \qmlclass Titre
*/
Rectangle {
    property string text: ""
    height: 60
    color: "#6e0917"
    id:root

    Text {
        id: champText
        color: "#ffffff"
        text: root.text
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter
        anchors.fill: parent
        //font.pixelSize: 30
        fontSizeMode: Text.Fit
    }
}

