import QtQuick 2.0
import QtQuick.Controls 1.3
import QtQuick.Dialogs 1.2
import site 1.0


Rectangle {
    id: root
    anchors.fill: parent
    signal retour

    signal debuterLecture(string urlFichierAudio)

    Keys.onReleased: {
    if (event.key === Qt.Key_Back) {
        event.accepted = true
        retour()
        }
    }

    Titre{
        id:titre
        text:fenetre.borneSelectionne.nom
        anchors.right: parent.right
        anchors.left: parent.left
        anchors.top: parent.top
    }

    TextArea {
        id:text
        readOnly: true
        text:fenetre.borneSelectionne.text
        anchors.right: parent.right
        anchors.left: parent.left
        anchors.bottom: btnPosition.top
        anchors.top: titre.bottom
    }

    Bouton{
        id:btnPosition
        anchors.left: parent.left
        enabled: (fenetre.borneSelectionne.altitude != 0.0 || fenetre.borneSelectionne.latitude != 0.0 || fenetre.borneSelectionne.longitude != 0.0) ? true : false
        width: parent.width/3
        anchors.bottom: parent.bottom
        text: "Position"
        border.color: "#ffffff"
        onClicked: {
            fenetre.afficherCarte(fenetre.borneSelectionne.nom);
        }
    }
    Bouton{
        id:btnItineraire
        anchors.left: btnPosition.right
        width: parent.width/3
        anchors.bottom: parent.bottom
        enabled: (fenetre.borneSelectionne.altitude != 0.0 || fenetre.borneSelectionne.latitude != 0.0 || fenetre.borneSelectionne.longitude != 0.0) ? true : false
        text: "Itineraire"
        border.color: "#ffffff"
        onClicked: fenetre.afficherItineraire(fenetre.borneSelectionne.nom)
    }
    Bouton{
        id:btnLecture
        anchors.left: btnItineraire.right
        anchors.right: parent.right
        width: parent.width/3
        anchors.bottom: parent.bottom
        text: "Lecture"
        border.color: "#ffffff"
        enabled: (fenetre.borneSelectionne.urlPisteAudioEstValid)?true:false
        onClicked: {
            root.debuterLecture(fenetre.borneSelectionne.urlPisteAudio)
        }
    }
}
