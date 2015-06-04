import QtQuick 2.0

/*!
  \qmlclass BoutonQuizz
*/
Rectangle {
    signal clicked
    property string text: ""
    id:root
    height: 60
    color: "#ffffff"
    border.color: "#000000"
    border.width: 1
    Text{
        id:champText
        color: "#000000"
        text: root.text
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter
        anchors.fill: parent
        font.pixelSize: 30
        fontSizeMode: Text.Fit
    }
    MouseArea{
        id:mouseArea
        anchors.fill: parent
        onClicked: {
            console.debug("quizz : choix de la reponse : " + root.text)
            root.clicked();
        }
    }
}
