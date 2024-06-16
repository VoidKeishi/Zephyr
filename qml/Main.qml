import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import QtQml.Models 2.15
import com.Zephyr 1.0

ApplicationWindow {
    visible: true
    width: 800
    height: 600
    title: "Zephyr Terminal"
    Rectangle {
        color: "#333333"
        anchors.fill: parent
        ColumnLayout {
            anchors.fill: parent

            RowLayout {
                width: parent.width
                height: 50
                Layout.fillWidth: true

                Repeater {
                    id: tabBar
                    model: tabModel
                    delegate: RowLayout {
                        Button {
                            text: model.title
                            onClicked: {
                                if (index < stackView.depth) {
                                    stackView.pop(stackView.depth - index);
                                } else {
                                    stackView.push("qrc:/Terminal.qml");
                                }
                            }
                        }
                        Button {
                            text: "X"
                            width: 10
                            onClicked: {
                                tabModel.remove(index);
                                if (index < stackView.depth) {
                                    stackView.pop();
                                }
                            }
                        }
                    }
                }

                Button {
                    text: "+"
                    onClicked: {
                        var newIndex = tabModel.count + 1;
                        tabModel.append({"title": "Terminal " + newIndex});
                        stackView.push("qrc:/Terminal.qml");
                    }
                }
            }

            StackView {
                id: stackView
                Layout.fillWidth: true
                Layout.fillHeight: true
                initialItem: "qrc:/Terminal.qml"
            }
        }
    }

    ListModel {
        id: tabModel
        ListElement { title: "Terminal 1" }
    }
}