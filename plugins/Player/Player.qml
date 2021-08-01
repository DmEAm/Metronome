import QtQuick 2.4
import QtQuick.Controls 2.0

import Player 1.0

PlayerForm {
    property alias controller: controller
    PlayerController {
            id: controller
        }
    play.onPressed: controller.toggle()

}
