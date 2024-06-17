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

    ColumnLayout {
        anchors.fill: parent
        RowLayout {
            Layout.fillWidth: true
            height: 30
            ListView {
                id: listView
                Layout.fillWidth: true
                height: parent.height
                orientation: ListView.Horizontal
                model: tabModel
                delegate: Item {
                    width: listView.width / tabModel.count
                    height: parent.height
                    TabButton {
                        text: model.title
                        onClicked: listView.currentIndex = index
                        width: parent.width - closeBtn.width
                        height: parent.height
                        background: Rectangle {
                            color: listView.currentIndex === index ? "#333333" : "#2F2F2F"
                        }
                    }

                    Button {
                        id: closeBtn
                        text: "x"
                        anchors.right: parent.right
                        width: 20
                        height: parent.height
                        onClicked: {
                            tabModel.remove(index);
                            if (listView.currentIndex >= index) {
                                listView.currentIndex -= 1;
                            }
                        }
                        background: Rectangle {
                            color: listView.currentIndex === index ? "#333333" : "#2F2F2F"
                        }
                    }
                }
            }

            Button {
                text: "+"
                width: 50
                height: parent.height
                onClicked: {
                    var newIndex = tabModel.count + 1;
                    tabModel.append({"title": "Terminal " + newIndex});
                    listView.currentIndex = tabModel.count - 1;
                }
            }
        }
        StackLayout {
            id: stackLayout
            Layout.fillWidth: true
            Layout.fillHeight: true

            Repeater {
                model: tabModel
                delegate: Loader {
                    source: "qrc:/Terminal.qml"
                }
            }
        }
    }

    ListModel {
        id: tabModel
        ListElement { title: "Terminal 1" }
    }

    Connections {
        target: listView
        onCurrentIndexChanged: {
            stackLayout.currentIndex = listView.currentIndex;
        }
    }
}
