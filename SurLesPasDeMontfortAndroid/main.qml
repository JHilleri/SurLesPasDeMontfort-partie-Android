import QtQuick 2.4
import QtQuick.Controls 1.3
import QtQuick.Window 2.2
import QtQuick.Dialogs 1.2




ApplicationWindow {
    title: qsTr("Hello World")
    width: 640
    height: 480
    visible: true
    id:root
    property int fenetreEnCours: fenetres.fenetreSite
    QtObject {
      id: fenetres
      property int fenetreSite: 0
      property int fenetreBorne: 1
      property int fenetreQuizz: 2
    }

    /*
    menuBar: MenuBar {
            Menu {
                title: qsTr("&File")
                MenuItem {
                    text: qsTr("&Charger XML")
                    onTriggered: fenetreSite.lireSiteXML()
                }
            }
        }
*/

    FenetreSite{
        id:fenetreListe
        visible: (root.fenetreEnCours == fenetres.fenetreSite)?true:false
        onOuvrirFenetreBorne: {
            fenetreEnCours = fenetres.fenetreBorne;
        }
    }

    FenetreBorne{
        id:fenetreBorne
        visible: (root.fenetreEnCours == fenetres.fenetreBorne)?true:false
        focus: (root.fenetreEnCours == fenetres.fenetreBorne)?true:false
        onRetour: {
            fenetreEnCours = fenetres.fenetreSite;
        }
    }
}
