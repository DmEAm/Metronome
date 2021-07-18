import QtQuick 2.0

Item {
    width: 100
    height: 100
    clip: true

    property alias view: view

    signal clicked(variant date);

    ListView {
        id: view
        model: picker.model
        width: picker.width / 3
        height: picker.height
        snapMode: ListView.SnapToItem

        delegate: Item {
            width: picker.width / 3
            height: picker.height / 3

            Text {
                text: model.value
                font.pixelSize: Math.min(0.5 * parent.width, parent.height)
                opacity: view.currentIndex == index ? 1 : 0.3
            }
        }
    }

}



/*##^##
Designer {
    D{i:0;formeditorZoom:4}
}
##^##*/
