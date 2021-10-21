import QtQuick 2.4
import QtQuick.Controls 2.0

import UpDown 1.0

UpDownForm {
    property alias controller: controller
    property string iconDown: "qrc:/icon/arrow-down-sign-to-navigate.svg"
    property string iconUp: "qrc:/icon/up-arrow.svg"

    UpDownController {
        id: controller
    }
    buttonDown.icon.source: iconDown;
    buttonUp.icon.source: iconUp;

    buttonDown.onPressed: controller.pressDown();
    buttonDown.onReleased: controller.releaseDown();
    buttonUp.onPressed: controller.pressUp();
    buttonUp.onReleased: controller.releaseUp();
}
