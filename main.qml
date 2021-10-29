import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.0

ApplicationWindow{

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

        Metronome {
            id: mainView
        }

        Settings {
            id: settView
        }
    }

}
