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


    FenetreSite{
        id:fenetreListe
        visible: true
        onOuvrirFenetreBorne: {
            fenetreListe.visible = false;
            fenetreBorne.visible = true;
            fenetreBorne.focus = true;
        }
    }
    FenetreBorne{
        id:fenetreBorne
        visible: false
        onRetour: {
            fenetreListe.visible = true;
            fenetreBorne.visible = false;
            fenetreBorne.focus = false;
        }
    }
}
