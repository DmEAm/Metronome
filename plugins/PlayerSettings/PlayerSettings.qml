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

    // Base Combo Box
    cbBaseSound.valueRole: "value"
    cbBaseSound.model: ListModel {
           id: cbBaseItems
           ListElement { text: "Basic 1"; color: "Yellow"}
           ListElement { text: "Basic 2"; color: "Green" }
           ListElement { text: "Basic 3"; color: "Brown" }
           ListElement { text: "Basic 4"; color: "Brown" }
           ListElement { text: "Basic 5"; color: "Brown" }
           ListElement { text: "Kick 1"; color: "Brown" }
       }
    cbBaseSound.currentIndex: controller.idBaseSound;
    cbBaseSound.onCurrentIndexChanged: {controller.setIdBaseSound(cbBaseSound.currentIndex);}

    // Accent Combo Box
    cbAccentSound.valueRole: "value"
    cbAccentSound.model: ListModel {
           id: cbAccentItems
           ListElement { text: "Actient 1"; color: "Yellow"}
           ListElement { text: "Actient 2"; color: "Green" }
       }
    cbAccentSound.currentIndex: controller.idAccentSound;
    cbAccentSound.onCurrentIndexChanged: {controller.setIdAccentSound(cbAccentSound.currentIndex);}

}
