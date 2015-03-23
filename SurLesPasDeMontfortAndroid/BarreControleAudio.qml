import QtQuick 2.0
import QtQuick.Controls 1.3
import QtQuick.Dialogs 1.2
import QtMultimedia 5.0

Rectangle {
    id:root
    color: "#ffffff"
    border.color: "#ffffff"

    QtObject{
        id: etatsLecture
        property int arret: 0
        property int lecture: 1
        property int pause:2
    }
    property int etatEnCour: etatsLecture.arret
    property bool lectureEnCour: (etatEnCour == etatsLecture.arret)?false:true
    signal finLecture
    signal debutLecture

    function debuterLecture(urlFichierAudio)
    {
        lecteurAudio.source = urlFichierAudio;
        lecteurAudio.play();
    }

    //visible: (lectureEnCour === etatsLecture.arret)?false:true

    Bouton{
        id:btnPause
        anchors.left: parent.left
        width: parent.width/2
        anchors.bottom: parent.top
        text:(etatEnCour === etatsLecture.lecture)?"pause":"reprendre"
        //onClicked: (etatEnCour == etatsLecture.lecture)?{lecteurAudio.pause()}:{lecteurAudio.play()}
        onClicked: {
            if(etatEnCour === etatsLecture.lecture)
            {
                lecteurAudio.pause()
            }
            else
            {
                lecteurAudio.play()
            }
        }
    }

    Bouton{
        id:btnStop
        anchors.right: parent.right
        width: parent.width/2
        anchors.bottom: parent.top
        text:"stop"
        //visible: (root.etatEnCour == 0)?false:true
        onClicked: {
            lecteurAudio.stop()
        }
    }

    Audio{
        id:lecteurAudio
        source: ""
        onPaused: {root.etatEnCour = etatsLecture.pause;}
        onPlaying: {
            root.etatEnCour = etatsLecture.lecture;
            debutLecture();
            console.debug("debut de la lecture de " + urlFichierAudio)
        }
        onStopped: {
            root.etatEnCour = etatsLecture.arret;
            finLecture();
        }
    }
}

