import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import com.Zephyr 1.0

ApplicationWindow {
    visible: true
    width: 800
    height: 600
    title: "Zephyr Terminal"

    CommandHandler {
        id: commandHandler

        onHandleCommand: {
            commandOutput.appendText(command + "\n")
        }

        onCommandOutput: {
            commandOutput.appendText(output)
        }
    }
    Command {  // Create a Command object
        id: command
    }

    Rectangle {
        color: "#333333"
        anchors.fill: parent

        ScrollView {
            id: scrollArea
            width: parent.width
            height: parent.height * 0.9

            TextArea {
                id: commandOutput
                readOnly: true
                text: "Welcome to Zephyr \n"
                color: "#00FF00"
                font.family: "Fira Code"
                font.pointSize: 14
                width: scrollArea.width
                wrapMode: TextEdit.Wrap
                background: null
                function appendText(newText) {
                    text += newText;
                    cursorPosition = text.length;
                }
            }
        }

        TextField {
            id: commandInput
            width: parent.width
            height: parent.height * 0.1
            anchors.bottom: parent.bottom
            placeholderText: qsTr("Enter command...")
            color: "#00FF00"
            font.family: "Fira Code"
            font.pointSize: 14
            background: null
            onAccepted: {
                command.commandContent = text  // Set the command content
                commandHandler.receiveCommand(command)  // Pass the Command object to the CommandHandler
                text = ""
            }
            Keys.onUpPressed: {
                text = commandHandler.getPreviousCommand()  // Get the previous command from the command history
            }
            Keys.onDownPressed: {
                text = commandHandler.getNextCommand()  // Get the next command from the command history
            }
        }
    }
}
