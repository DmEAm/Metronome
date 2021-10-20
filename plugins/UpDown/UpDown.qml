import QtQuick 2.4
import QtQuick.Controls 2.0

import UpDown 1.0

UpDownForm {
    property alias controller: controller
    UpDownController {
        id: controller
    }
    buttonDown.onPressed: controller.pressDown();
    buttonDown.onReleased: controller.releaseDown();
    buttonUp.onPressed: controller.pressUp();
    buttonUp.onReleased: controller.releaseUp();
}
