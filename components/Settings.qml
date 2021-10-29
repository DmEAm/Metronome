import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3
import QtQml.Models 2.12
import QtMultimedia 5.12

import Player 1.0
import Tapper 1.0
import Picker 1.0
import TempoPicker 1.0

Component {
    id: settView
    ColumnLayout{
        property int settIndex: 0

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
                    currentIndex: 0
                    textRole: "text"
//                            valueRole: "value"
                    model: ListModel {
                           id: cbItems
                           ListElement { text: "Player"; color: "Yellow"}
                           ListElement { text: "Tempo"; color: "Green" }
                           ListElement { text: "Tapper"; color: "Brown" }
                       }
                    onCurrentIndexChanged: {
                        stackSettings.clear();
                        if(currentIndex == 0)
                            stackSettings.push(settViewPlayer);
                        else if(currentIndex == 1)
                            stackSettings.push(settViewTempo);
                        else if(currentIndex == 2)
                            stackSettings.push(settViewTapper);
                        settIndex = currentIndex;
                    }
                    Component.onCompleted: {currentIndex = settIndex;}
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
                    icon.source: "qrc:/icons/back.svg";
                    onClicked: {stack.pop()}
                }
            }
        }
        Item{
            Layout.fillWidth: true
            Layout.fillHeight: true
            StackView {
                id: stackSettings
                initialItem: settViewPlayer
                anchors.fill: parent
                Component {
                    id: settViewPlayer
                    Item{
                        Layout.fillWidth: true
                        Layout.fillHeight: true
                        property alias playerSettingsController: playerSettings.controller
                        PlayerSettings{
                            id: playerSettings
                            element.width: parent.width
                            anchors.top: parent.top
                            anchors.horizontalCenter: parent.horizontalCenter
                        }

                        Connections{
                            target: playerSettingsController
                            function onVolumeChanged(){
                                playerController.setVolume(playerSettingsController.getStrVolume());
                            }
                        }

                        Connections{
                            target: playerSettingsController
                            function onIdBaseSoundChanged(){
                                playerController.setBaseSound(playerSettingsController.getStrBaseSound());
                            }
                        }

                        Connections{
                            target: playerSettingsController
                            function onIdAccentSoundChanged(){
                                playerController.setAccentSound(playerSettingsController.getStrAccentSound());
                            }
                        }
                    }
                }
                Component {
                    id: settViewTempo
                    Item{
                        Layout.fillWidth: true
                        Layout.fillHeight: true
                        property alias tempoSettingsController: tempoSettings.controller
                        TempoSettings{
                            id: tempoSettings
                            element.width: parent.width
                            anchors.top: parent.top
                            anchors.horizontalCenter: parent.horizontalCenter
                        }
                        Connections{
                            target: tempoSettingsController
                            function onTempoChanged(){
                                tempoController.tempo = tempoSettingsController.tempo;
                            }
                        }
                        Connections{
                            target: tempoSettingsController
                            function onMaxTempoChanged(){
                                tempoController.tempo.max = tempoSettingsController.maxTempo;
                                tempoController.tempo.current = tempoSettingsController.tempo;
                            }
                        }
                        Connections{
                            target: tempoSettingsController
                            function onMinTempoChanged(){
                                tempoController.tempo.min = tempoSettingsController.minTempo;
                                tempoController.tempo.current = tempoSettingsController.tempo;
                            }
                        }
                    }
                }

                Component {
                    id: settViewTapper
                    Item{
                        Layout.fillWidth: true
                        Layout.fillHeight: true
                        property alias tapperSettingsController: tapperSettings.controller
                        TapperSettings{
                            id: tapperSettings
                            element.width: parent.width
                            anchors.top: parent.top
                            anchors.horizontalCenter: parent.horizontalCenter
                        }

                        Connections{
                            target: tapperSettingsController
                            function onInertiaChanged(){
                                tapperController.inertia = tapperSettingsController.inertia;
                            }
                        }
                    }
                }
            }
        }
    }
}
