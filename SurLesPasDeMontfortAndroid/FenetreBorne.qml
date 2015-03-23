import QtQuick 2.0
import QtQuick.Controls 1.3
import QtQuick.Dialogs 1.2


Rectangle {
    id: root
    anchors.fill: parent
    signal retour

    property int lectureEnCour: 0
    signal debuterLecture(string urlFichierAudio)

    Keys.onReleased: {
    if (event.key === Qt.Key_Back) {
        event.accepted = true
        retour()
        }
    }

    Titre{
        id:titre
        text:borneSelectionne.nom
        anchors.right: parent.right
        anchors.left: parent.left
        anchors.top: parent.top
    }

    TextArea {
        id:text
        readOnly: true
        text:borneSelectionne.text
        anchors.right: parent.right
        anchors.left: parent.left
        anchors.bottom: btnPosition.top
        anchors.top: titre.bottom
    }

    Bouton{
        id:btnPosition
        anchors.left: parent.left
        width: parent.width/3
        anchors.bottom: parent.bottom
        text: "Position"
        border.color: "#ffffff"
        onClicked: {
            fenetre.afficherCarte(borneSelectionne.nom);
        }
    }
    Bouton{
        id:btnItineraire
        anchors.left: btnPosition.right
        width: parent.width/3
        anchors.bottom: parent.bottom
        text: "Itineraire"
        border.color: "#ffffff"
        onClicked: fenetre.afficherItineraire(borneSelectionne.nom)
    }
    Bouton{
        id:btnLecture
        anchors.left: btnItineraire.right
        anchors.right: parent.right
        width: parent.width/3
        anchors.bottom: parent.bottom
        text: "Lecture"
        border.color: "#ffffff"
        onClicked: {
            root.debuterLecture(borneSelectionne.urlPisteAudio)
        }
    }
}
