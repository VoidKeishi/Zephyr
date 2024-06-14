import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15

Item {
    width: 800
    height: 600

    ColumnLayout {
        anchors.fill: parent
        spacing: 10

        // Current directory display
        TextField {
            Layout.fillWidth: true
            text: qsTr("Current directory")
            readOnly: true
            font.pixelSize: 16
            // You can bind the text property to a C++ property or set it dynamically
        }

        // Input area
        TextInput {
            Layout.fillWidth: true
            TextField {
                placeholderText: qsTr("Enter command...")
            }
            font.pixelSize: 16
            onAccepted: {
                console.log("Command entered:", text)
                text = "" // Clear input after submission (optional)
            }
        }
    }
}
