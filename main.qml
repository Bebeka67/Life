import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.5

import Life.Game 1.0

Window {
    minimumWidth: 640
    minimumHeight: 480

    property var backend: LifeGame

    visible: true
    title: qsTr("The Life Game")

    MainFrame {
        anchors.fill: parent
    }
}
