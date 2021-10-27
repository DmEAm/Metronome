import QtQuick 2.4
import QtQuick.Controls 2.0

import Player 1.0

PlayerForm {
    property var controller: playerController
    property string iconPlay: "qrc:/icons/play.svg"
    property string iconPause: "qrc:/icons/pause.svg"

    play.icon.width: 60;
    play.icon.height: 60;
    play.icon.source: iconPlay;
    play.onPressed:
    {
        controller.toggle();
        play.icon.source = controller.playing ? iconPause: iconPlay;
    }

}
