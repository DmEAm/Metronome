import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3
import QtQml.Models 2.15
import QtMultimedia 5.12

import Player 1.0
import Tapper 1.0
import Picker 1.0

ApplicationWindow{
    property alias playerController: player.controller
    property alias tapperController: tapper.controller
    property alias settView: settView
    property alias tempoController: tempoPicker.controller
    property alias accentController: accentPicker.controller
    property alias tempoTumbler: tempoPicker.tumbler
    property alias stack: stack

    property string iconSett: "qrc:/icons/setting_line.svg"
    property string iconBack: "qrc:/icons/back.svg"

    title: qsTr("Metronome")
    visible: true

    width: 400
    height: 500
    maximumHeight: height
    maximumWidth: width
    minimumHeight: height
    minimumWidth: width

    StackView {
            id: stack
            initialItem: mainView
            anchors.fill: parent
        }

    ColumnLayout{
        id: mainView
        spacing: 0
        //anchors.fill: parent

        RowLayout{
            spacing: 0
            Layout.maximumHeight: settButton.height
            Layout.minimumHeight: settButton.height
            Item{
                Layout.fillWidth: true
                Layout.fillHeight: true
                Rectangle{
                    anchors.fill: parent
                    color: "#E0E0E0"
                }
            }
            Item{
                Layout.preferredWidth: settButton.width
                Layout.alignment: Qt.AlignRight
                Button{
                    id: settButton
                    width: 50;
                    height: 40;
                    anchors.centerIn: parent
                    icon.source: iconSett;
                    onClicked: stack.push(settView)
                }
            }
        }

        RowLayout{
            spacing: 4
            Layout.minimumHeight: tempoPicker.height
            Item{
                Layout.fillWidth: true
                Layout.fillHeight: true
            }
            Item{
                Layout.fillWidth: true
                Layout.alignment: Qt.AlignHCenter
                TempoPicker{
                    id: tempoPicker
                    anchors.centerIn: parent
                    delegateComponent.model: playerController.range
                    controller.maxTempo: playerController.tempoMax
                    controller.minTempo: playerController.tempoMin
                    tumbler.currentIndex: playerController.tempo - playerController.tempoMin
                }
            }
            Item{
                Layout.fillWidth: true
                Layout.alignment: Qt.AlignRight
                Tapper{
                    id: tapper
                    anchors.centerIn: parent
                }
            }
        }

        Player{
            id: player
            Layout.alignment: Qt.AlignHCenter
        }

        RowLayout{
            spacing: 2
            Layout.minimumHeight: accentPicker.height
            Item{
                Layout.fillWidth: true
                Layout.fillHeight: true
                DurationPicker{
                    id: durationPicker
                    anchors.centerIn: parent
                }
            }
            Item{
                Layout.fillWidth: true
                Layout.alignment: Qt.AlignHCenter
                DurationPicker{
                    id: durationPicker_2
                    anchors.centerIn: parent
                }
            }
            Item{
                Layout.fillWidth: true
                Layout.alignment: Qt.AlignHCenter
                AccentPicker{
                    id: accentPicker
                    delegateComponent.model: 13
                    anchors.centerIn: parent
                }
            }
        }
    }

    Component {
        id: settView
        ColumnLayout{
            spacing: 0
            RowLayout{
                spacing: 0
                Layout.fillWidth: true
                Layout.maximumHeight: returnButton.height
                Layout.minimumHeight: returnButton.height
                Layout.alignment: Qt.AlignHCenter | Qt.AlignTop
                Item{
                    Layout.fillWidth: true
                    Layout.fillHeight: true
                    ComboBox {
                        anchors.fill: parent
                        currentIndex: 2
                        textRole: "text"
                        valueRole: "value"
                        model: ListModel {
                               id: cbItems
                               ListElement { text: "Banana"; color: "Yellow"}
                               ListElement { text: "Apple"; color: "Green" }
                               ListElement { text: "Coconut"; color: "Brown" }
                           }
                      }
                }
                Item{
                    Layout.preferredWidth: returnButton.width
                    Layout.alignment: Qt.AlignRight
                    Button{
                        id: returnButton
                        width: 50;
                        height: 40;
                        anchors.centerIn: parent
                        icon.source: iconBack;
                        onClicked: stack.pop()
                    }
                }

            }
        }
    }

    Connections{
        target: tempoController
        function onIndexChanged(){
            playerController.tempo = tempoController.tempo;
        }

    }

    Connections{
        target: tempoController
        function onTempoChanged(){
            playerController.tempo = tempoController.tempo;
            tempoTumbler.currentIndex = tempoController.index;
        }
    }

    Connections{
        target: tapperController
        function onTempoChanged(){
            tempoController.tempo = tapperController.tempo;
        }
    }

    Connections{
        target: accentController
        function onIndexChanged(){
            playerController.accent = accentController.index;
        }
    }
}
