import QtQuick 2.4
import QtQuick.Controls 2.0

import Player 1.0

PlayerForm {

    PlayerController {
            id: backend
        }
    bStart.text: backend.userName
    bStart.onPressed: backend.changeWorkState()

}
