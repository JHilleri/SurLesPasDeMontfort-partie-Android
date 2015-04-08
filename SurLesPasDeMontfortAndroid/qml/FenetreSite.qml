import QtQuick 2.4
import QtQuick.Controls 1.3
import QtQuick.Window 2.2
import QtQuick.Dialogs 1.2
import site 1.0

Rectangle{
    id:root
    anchors.fill: parent
    visible: true
    signal ouvrirFenetreBorne;

    Titre{
        id: titre
        text: "Liste des bornes"
        anchors.right: parent.right
        anchors.rightMargin: 0
        anchors.left: parent.left
        anchors.leftMargin: 0
        anchors.top: parent.top
        anchors.topMargin: 0

    }

    ListView{
        id: liste
        anchors.top: titre.bottom
        anchors.right: parent.right
        anchors.bottom: parent.bottom
        anchors.left: parent.left
        anchors.topMargin: 0

        model: fenetre.site.liste

        delegate: Rectangle{
            height: 50
            border.width: 1
            width: parent.width
            Text{
                anchors.fill: parent

                horizontalAlignment: Text.AlignHCenter
                text:modelData.nom
                verticalAlignment: Text.AlignVCenter
            }
            MouseArea{
                anchors.fill: parent
                onClicked: {
                    fenetre.setBorneSelectionne(modelData.nom);
                    ouvrirFenetreBorne();
                }
            }
        }
    }
}

