import QtQuick 2.4
import QtQuick.Controls 2.0

import TempoSettings 1.0

TempoSettingsForm {
    property alias controller: controller
    TempoSettingsController{
        id: controller;
    }

    sMinTempo.onValueChanged: {controller.setMinTempo(sMinTempo.value);}
    sMaxTempo.onValueChanged: {controller.setMaxTempo(sMaxTempo.value);}
    sTempo.onValueChanged: {controller.setTempo(sTempo.value);}

    Connections{
        target: controller
        function onMinTempoChanged(){
            lMinTempo.text = controller.minTempo;
        }
    }
    Connections{
        target: controller
        function onMaxTempoChanged(){
            lMaxTempo.text = controller.maxTempo;
        }
    }
    Connections{
        target: controller
        function onTempoChanged(){
            lTempo.text = controller.tempo;
        }
    }

    Component.onCompleted: {
        sMinTempo.from = controller.strongMinTempo;
        sMinTempo.to = controller.strongMaxTempo;
        sMaxTempo.from = controller.strongMinTempo;
        sMaxTempo.to = controller.strongMaxTempo;
        sTempo.from = controller.strongMinTempo;
        sTempo.to = controller.strongMaxTempo;

        controller.init();

        //MIN TEMPO
        sMinTempo.value = controller.minTempo;
        lMinTempo.text = controller.minTempo;

        //MAX TEMPO
        sMaxTempo.value = controller.maxTempo;
        lMaxTempo.text = controller.maxTempo;

        //TEMPO
        sTempo.value = controller.tempo;
        lTempo.text = controller.tempo;
    }
}
