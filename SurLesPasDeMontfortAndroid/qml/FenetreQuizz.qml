import QtQuick 2.4
import QtQuick.Controls 1.3
import QtQuick.Window 2.2
import QtQuick.Dialogs 1.2
//import quizz 1.0

Rectangle{
    id:root

    signal retour

    Keys.onReleased: {
    if (event.key === Qt.Key_Back) {
        event.accepted = true;
        retour();
        }
    }

    Text{
        id:question
        text: fenetre.questionTest.question
        anchors.right: parent.right
        anchors.left: parent.left
        anchors.top: parent.top

    }
    Bouton{
        id: reponse1
        width: parent.width / 2
        text: fenetre.questionTest.bonneReponse
        anchors.left: parent.left
        anchors.top:  question.bottom

    }
    Bouton{
        id: reponse2
        width: parent.width /2
        text: fenetre.questionTest.mauvaiseReponse1
        anchors.right: parent.right
        anchors.top: question.bottom
    }
    Bouton{
        id: reponse3
        width: parent.width /2
        text: fenetre.questionTest.mauvaiseReponse2
        anchors.left: parent.left
        anchors.bottom: parent.bottom
    }
    Bouton{
        id: reponse4
        width: parent.width /2
        text: fenetre.questionTest.mauvaiseReponse3
        anchors.right: parent.right
        anchors.bottom: parent.bottom
    }
}
