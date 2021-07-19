import QtQuick 2.12
import QtQuick.Controls 2.0

import Picker 1.0

Item {
    Picker {
        model: PickerModel { }
        width: 200
        height: 200
        x: 100
        y: 200
        onClicked: console.log('onClicked', date)
    }
}
