import QtQuick 2.4
import QtQuick.Controls 2.3

Item {
    id: element
    width: 200
    height: 200
    property alias bStart: bStart

    RoundButton {
        id: bStart
        x: 0
        y: 0
        width: 200
        height: 200
        text: "+"
    }
}
