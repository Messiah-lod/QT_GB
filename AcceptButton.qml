import QtQuick 2.5
import QtQuick.Window 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import Qt.labs.qmlmodels 1.0


BorderImage {
    default property alias children: marea.data

    id: main
    signal clicked
    width: 20
    height: 20

    MouseArea {
        id: marea
        anchors.fill: parent
        hoverEnabled: true
        onClicked: parent.clicked()
        onPressed: {        }
        onReleased: {        }
    }

    Image {
        id: _release
        anchors.fill: parent
        source: marea.pressed ? "qrc:///img/acceptRelease.png" : "qrc:///img/acceptPres.png"
        fillMode: Image.Stretch
    }



}
