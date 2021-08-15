import QtQuick 2.4
import QtQuick.Controls 2.0

import Tapper 1.0

TapperForm {
    property alias controller: controller
    TapperController {
        id: controller
    }
    tapp.onPressed: controller.tap()
}
