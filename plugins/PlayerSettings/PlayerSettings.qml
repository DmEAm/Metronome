import QtQuick 2.4
import QtQuick.Controls 2.0

import PlayerSettings 1.0

PlayerSettingsForm {
    property alias controller: controller
    PlayerSettingsController{
        id: controller;
    }
    sVolume.value: controller.volume;
    sVolume.onValueChanged: {controller.setVolume(sVolume.value);}
}
