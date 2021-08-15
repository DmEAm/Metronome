import QtQuick 2.12
import QtQml.Models 2.2
import QtQuick.Controls 2.12

import Picker 1.0

PickerForm {
    id: picker
    currentItemFrame.width: parent.width;
    currentItemFrame.background: Rectangle{
        border.color: "black"}
    frame.background: Rectangle{
        border.width: 3;
        radius: 10}
}
