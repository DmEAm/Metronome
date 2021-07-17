import QtQuick 2.4
import QtQuick.Controls 2.0

import mainwindow 1.0

MainWindowForm {

    MainController {
            id: backend
        }
    txt.text: backend.userName

}
