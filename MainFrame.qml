import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.5

import Life.Game 1.0

Rectangle {
    id: _root
    color: "white"
    border.color: "black"


    Control {
        id: _cellsWidget
        // background: Rectangle {
        //     color: "red"
        //     opacity: 0.5
        // }
        anchors.left: parent.left
        anchors.top: parent.top
        anchors.bottom: parent.bottom
        width: height

        TableView {
            anchors.centerIn: parent

            width: contentWidth
            height: contentHeight



            columnSpacing: 1
            rowSpacing: 1
            clip: true

            model: LifeGame.model

            delegate: Rectangle {
                implicitWidth: 25
                implicitHeight: 25
                color: lifeState ? "green" : "gray"

                MouseArea {
                    anchors.fill: parent
                    onClicked: lifeState = !lifeState
                }

            }
        }

        // GridLayout {
        //     id: _cells
        //     anchors.centerIn: parent

        //     columns: 10
        //     rows: 10


        //     Repeater {
        //         model: _cells.columns * _cells.rows
        //         delegate: Rectangle {
        //             width: 10
        //             height: 10
        //             color: "red"
        //         }
        //     }
        // }
    }

    Rectangle {
        id: divider
        width: 1
        anchors.left: _cellsWidget.right
        anchors.top: parent.top
        anchors.bottom: parent.bottom
        color: "black"
    }

    Control {
        id: _toolbar

        anchors.left: divider.right
        anchors.right: parent.right
        anchors.top: parent.top
        anchors.bottom: parent.bottom
        anchors.margins: 5

        // RowLayout {
        //     Button {
        //         Layout.preferredWidth: 25
        //         Layout.preferredHeight: 25
        //         text: "+"
        //         background: Rectangle {
        //             color: "darkgray"
        //         }
        //     }
        //     Button {
        //         Layout.preferredWidth: 25
        //         Layout.preferredHeight: 25
        //         text: "-"
        //         background: Rectangle {
        //             color: "darkgray"
        //         }
        //     }
        // }

        ColumnLayout {
            anchors.fill: parent
            anchors.margins: 10
            Button {
                text: "Run"
                onClicked: LifeGame.model.run()
            }
            Button {
                text: "Stop"
                onClicked: LifeGame.model.stop()
            }

        }



    }


}
