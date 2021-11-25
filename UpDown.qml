import QtQuick 2.4
import QtQuick.Controls 2.0

import UpDown 1.0

UpDownForm {
    property alias controller: controller
    property string iconDown: "qrc:/icons/arrow-down.svg"
    property string iconUp: "qrc:/icons/arrow-up.svg"

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
