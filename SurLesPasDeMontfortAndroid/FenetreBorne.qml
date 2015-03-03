import QtQuick 2.0

Rectangle {
    id: rectangle1
    anchors.fill: parent
    signal retour
    Titre{
        text:borne.nom()
        anchors.right: parent.right
        anchors.rightMargin: 0
        anchors.left: parent.left
        anchors.leftMargin: 0
        anchors.top: parent.top
        anchors.topMargin: 0
    }
    Keys.onReleased: {
    if (event.key === Qt.Key_Back) {
        event.accepted = true
        retour()
        }
    }
}

