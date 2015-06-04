import QtQuick 2.4
import QtQuick.Controls 1.3
import QtQuick.Window 2.2
import QtQuick.Dialogs 1.2
import QtQuick.Layouts 1.1
import quizz 1.0

/*!
  \qmlclass FenetreQuizz
*/
Rectangle{
    id:root

    property int score : 0

    signal retour
    function initQuestion()
    {
        var tab = [fenetre.quizz.questionEnCours.bonneReponse,fenetre.quizz.questionEnCours.mauvaiseReponse1,fenetre.quizz.questionEnCours.mauvaiseReponse2,fenetre.quizz.questionEnCours.mauvaiseReponse3];
        console.debug(tab);
        var nb = Math.floor(Math.random()*4);
        reponse1.text = tab[nb];
        tab.splice(nb,1)
        console.debug(tab);
        nb = Math.floor(Math.random()*3);
        reponse2.text = tab[nb]
        tab.splice(nb,1)
        console.debug(tab);
        nb = Math.floor(Math.random()*2);
        reponse3.text = tab[nb]
        tab.splice(nb,1)
        console.debug(tab);
        reponse4.text = tab[0]
    }

    /*!
     *
     */
    function verifierResultat(propositionChoisie)
    {
        if(propositionChoisie === fenetre.quizz.questionEnCours.bonneReponse)
        {
            console.debug("bonne reponse")
            ++root.score;
        }
        else
        {
            console.debug("mauvaise reponse")
            --root.score;
        }
        if(fenetre.quizz.questionSuivante())
        {
            root.initQuestion();
        }
        else
        {

            console.debug("le score est de : " + root.score);
            retour();
        }
    }

    Keys.onReleased: {
    if (event.key === Qt.Key_Back) {
        event.accepted = true;
        retour();
        }
    }

    Titre{
        id:question
        height: 60
        text: fenetre.quizz.questionEnCours.question
        anchors.right: parent.right
        anchors.left: parent.left
        anchors.top: parent.top

    }

     GridLayout{
        id: grid1
        rows: 2
        columns: 2
        flow: GridLayout.TopToBottom

        anchors.right: parent.right
        anchors.rightMargin: 0
        anchors.left: parent.left
        anchors.leftMargin: 0
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 0
        anchors.top: question.bottom
        anchors.topMargin: 0

        BoutonQuizz{
            id: reponse1
            text: qsTr("reponse 0")
            Layout.fillHeight: true
            Layout.fillWidth: true
            onClicked: {
                root.verifierResultat(text);
            }
        }

        BoutonQuizz{
            id: reponse2
            text: qsTr("reponse 1")
            Layout.fillHeight: true
            Layout.fillWidth: true
            onClicked: {
                root.verifierResultat(text);
            }
        }

        BoutonQuizz{
            id: reponse3
            text: qsTr("reponse 2")
            Layout.fillHeight: true
            Layout.fillWidth: true
            onClicked: {
                root.verifierResultat(text);
            }
        }

        BoutonQuizz{
            id: reponse4
            text: qsTr("reponse 3")
            Layout.fillHeight: true
            Layout.fillWidth: true
            onClicked: {
                root.verifierResultat(text);
            }
        }
    }
}
