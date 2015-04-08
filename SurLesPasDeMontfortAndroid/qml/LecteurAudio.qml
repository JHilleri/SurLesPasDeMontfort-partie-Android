import QtQuick 2.0
import QtQuick.Controls 1.3
import QtQuick.Dialogs 1.2
import QtMultimedia 5.0
import site 1.0

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
        if(urlFichierAudio == lecteurAudio.source && lecteurAudio.hasAudio)lecteurAudio.play();
        else lecteurAudio.source = urlFichierAudio;
    }

    Bouton{
        id:btnPause
        anchors.left: parent.left
        width: parent.width/2
        anchors.bottom: parent.top
        text:(etatEnCour === etatsLecture.lecture)?"pause":"reprendre"
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
            console.debug("debut de la lecture de " + lecteurAudio.source)
        }
        onStopped: {
            root.etatEnCour = etatsLecture.arret;
            finLecture();
        }
        onHasAudioChanged:
        {
                lecteurAudio.play();
        }
        onError: console.debug("erreur avec le fichier audio '" + root.urlFichierAudio +"'");
    }
}

