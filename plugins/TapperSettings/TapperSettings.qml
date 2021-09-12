import QtQuick 2.4
import QtQuick.Controls 2.0

import TapperSettings 1.0

TapperSettingsForm {
    property alias controller: controller
    TapperSettingsController{
        id: controller;
    }

    sInertia.onValueChanged: {controller.setInertia(sInertia.value);}

    Connections{
        target: controller
        function onInertiaChanged(){
            lInertia.text = controller.inertia;
        }
    }

    Component.onCompleted: {
        sInertia.from = controller.strongMinInertia;
        sInertia.to = controller.strongMaxInertia;

        controller.init();

        //Inertia
        sInertia.value = controller.inertia;
        lInertia.text = controller.inertia;
    }
}
