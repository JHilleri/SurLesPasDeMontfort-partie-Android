import QtQuick 2.0
import QtQuick.Controls 1.3
import QtQuick.Dialogs 1.2

Rectangle {
    id: rectangle1
    anchors.fill: parent
    signal retour

    Keys.onReleased: {
    if (event.key === Qt.Key_Back) {
        event.accepted = true
        retour()
        }
    }


    Titre{
        id:titre
        text:borne.nom()
        anchors.right: parent.right
        anchors.rightMargin: 0
        anchors.left: parent.left
        anchors.leftMargin: 0
        anchors.top: parent.top
        anchors.topMargin: 0
    }

    TextArea {
        id:text
        anchors.top: titre.bottom
        anchors.right: parent.right
        anchors.left: parent.left
        anchors.bottom: btnPosition.bottom
        readOnly: true
        text:borne.text()
    }

    Bouton{
        id:btnPosition
        anchors.left: parent.left
        width: parent.width/3
        anchors.bottom: parent.bottom
        text: "Position"
    }
    Bouton{
        id:btnItineraire
        anchors.left: btnPosition.right
        width: parent.width/3
        anchors.bottom: parent.bottom
        text: "Itineraire"
    }
    Bouton{
        id:btnPhotos
        anchors.left: btnItineraire.right
        anchors.right: parent.right
        width: parent.width/3
        anchors.bottom: parent.bottom
        text: "Photos"
    }
}
