import QtQuick 2.4
import QtQuick.Controls 1.3
import QtQuick.Window 2.2
import QtQuick.Dialogs 1.2

Rectangle{
    id:root
    //title: qsTr("Sur les pas de montfort")
    //width: 640
    //height: 480
    anchors.fill: parent
    visible: true
    signal ouvrirFenetreBorne;

    ListView{
        id: liste
        anchors.fill: parent

        model: site

        delegate: Rectangle{
            height: 50
            border.width: 1
            width: parent.width
            Text{
                anchors.fill: parent

                horizontalAlignment: Text.AlignHCenter
                text:modelData
                verticalAlignment: Text.AlignVCenter
            }
            MouseArea{
                anchors.fill: parent
                onClicked: {
                    //messageDialog.show(modelData);
                    fenetreSite.ouvrirFenetreBorne(modelData);
                    ouvrirFenetreBorne();
                }
            }
        }
    }

    MessageDialog {
            id: messageDialog
            title: qsTr("borne sélectionné")

            function show(caption) {
                messageDialog.text = "vous aver selectionné la borne : " + caption;
                messageDialog.open();
            }
        }
}

