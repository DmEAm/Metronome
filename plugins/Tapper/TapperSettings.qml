import QtQuick 2.4
import QtQuick.Controls 2.0

import Tapper 1.0

TapperSettingsForm {
    property var controller: tapperSettingsController
    property bool isLoad: true


    sInertia.onValueChanged: {
        if(isLoad)
            return;
        controller.setInertia(sInertia.value);
    }

    Connections{
        target: controller
        function onInertiaChanged(){
            lInertia.text = controller.inertia;
        }
    }

    Component.onCompleted: {
        sInertia.from = controller.strongMinInertia;
        sInertia.to = controller.strongMaxInertia;
        sInertia.value = controller.inertia;
        lInertia.text = controller.inertia;

        isLoad = false;
    }
}
