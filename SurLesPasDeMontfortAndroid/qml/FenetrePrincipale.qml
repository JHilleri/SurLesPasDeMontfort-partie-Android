import QtQuick 2.4
import QtQuick.Controls 1.3
import QtQuick.Window 2.2
import QtQuick.Dialogs 1.2
import site 1.0




ApplicationWindow {
    width: 640
    height: 480
    title: qsTr("sur les pas de montfort")
    visible: true
    id:root
    property int fenetreEnCours: enumFenetres.fenetreSite
    property bool lectureEnCours: false

    QtObject {
      id: enumFenetres
      property int fenetreSite: 0
      property int fenetreBorne: 1
      property int fenetreQuizz: 2
    }
    onContentItemChanged: {
        if(root.fenetreEnCours === enumFenetres.fenetreSite)
        {
            root.title = qsTr("sur les pas de montfort")
        }
        else
        {
            if(root.fenetreEnCours === enumFenetres.fenetreSite)
            {
                root.title = fenetre.borneSelectionne.nom
            }
            else
            {
                if(root.fenetreEnCours === enumFenetres.fenetreQuizz)
                {
                    root.title = qsTr("Quizz")
                }
            }
        }
    }

    menuBar: MenuBar {
            Menu {
                title: qsTr("&File")
                MenuItem {
                    text: qsTr("&Charger XML")
                    onTriggered:
                    {
                        root.fenetreEnCours = enumFenetres.fenetreSite;
                        fenetre.lireSiteXML();
                    }
                }
                MenuItem{
                    text: fenetre.borneAProximite.nom
                }
                MenuItem{
                    text: "longitude : " + fenetre.longitude
                }
                MenuItem{
                    text: "latitude : " + fenetre.latitude
                }
                MenuItem{
                    text: "jouer quizz"
                    onTriggered: {
                        root.fenetreEnCours = enumFenetres.fenetreQuizz;
                        fenetreQuizz.initQuestion()
                    }
                }
            }
        }

    Rectangle{
        id:zoneFenetres

        anchors.right: parent.right
        anchors.left: parent.left
        anchors.bottom: (root.lectureEnCours)?barreAudio.top : parent.bottom
        anchors.bottomMargin: 0
        anchors.top: parent.top

        FenetreSite{
            id:fenetreListe
            anchors.fill: zoneFenetres
            visible: (root.fenetreEnCours === enumFenetres.fenetreSite)?true:false
            onOuvrirFenetreBorne: {fenetreEnCours = enumFenetres.fenetreBorne;}
        }

        FenetreBorne{
            id:fenetreBorne
            anchors.fill: zoneFenetres
            visible: (root.fenetreEnCours === enumFenetres.fenetreBorne)?true:false
            focus: (root.fenetreEnCours === enumFenetres.fenetreBorne)?true:false
            onRetour: {fenetreEnCours = enumFenetres.fenetreSite;}
            onDebuterLecture: {barreAudio.debuterLecture(urlFichierAudio)}
        }

        FenetreQuizz{
            id:fenetreQuizz
            anchors.fill: zoneFenetres
            visible: (root.fenetreEnCours === enumFenetres.fenetreQuizz)?true:false
            focus: (root.fenetreEnCours === enumFenetres.fenetreQuizz)?true:false
            onRetour: {fenetreEnCours = enumFenetres.fenetreSite;}
        }
    }

    LecteurAudio{
        id:barreAudio
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.bottom: parent.bottom
        visible: (root.lectureEnCours)?true : false
        onFinLecture: root.lectureEnCours = false
        onDebutLecture: root.lectureEnCours = true
    }
}
