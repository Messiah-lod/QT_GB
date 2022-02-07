import QtQuick 2.5
import QtQuick.Window 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import Qt.labs.qmlmodels 1.0
import TaskManager 1.0
import TaskManagerModel 1.0


ApplicationWindow  {
    id: _mainWindow
    width: 645
    height: 480
    visible: true
    maximumHeight: height
    maximumWidth: width
    minimumHeight: height
    minimumWidth: width
    title: qsTr("Органайзер")

    Component.onCompleted: startupFunction();
    onClosing: { //по закрытию программы
//        if(_txtTaskName.text) { //проверим, если имя задачи введено - сохраним ее в файл
//            _TaskManager.Write = _txtTaskName.text + ";;" + _txtDeadLine.text + ";;" + _sbProgress.displayText
//        }
    }

    BorderImage {
        source: "qrc:///img/background.jpg"
        anchors.fill: parent
    }

    TaskManager {
        id: _TaskManager
    }

    function startupFunction() {
        //Выполняем подгрузку всех данных из файла
        _taskManagerModel.addObject(_TaskManager.readFile())
    }

    GridLayout  {
        id: _mainGrid
        columns: 3
        rows: 4
        rowSpacing: 5
        anchors.fill: parent

        TaskManagerModel {
            id: _taskManagerModel
        }

        Rectangle {
            id: _backRect
            height: (_mainWindow.height*3)/4
            width: _mainWindow.width
            color: "#dfd6b9"

            Layout.columnSpan: 3
            Layout.rowSpan: 1
            Layout.row: 0
            Layout.column: 0

            TableView {
                id: _taskManagerModelView
                anchors.fill: parent
                clip: true
                model:  _taskManagerModel
                topMargin: _columnsHeader.implicitHeight //отступ от верха на размер хедера

                ScrollBar.horizontal: ScrollBar{}
                ScrollBar.vertical: ScrollBar{}
                ScrollIndicator.horizontal: ScrollIndicator { }
                ScrollIndicator.vertical: ScrollIndicator { }

                onWidthChanged: _taskManagerModelView.forceLayout()
                columnWidthProvider: function (column) { //подгоняет ширину столбцов по ширине вьюшки
                            return _taskManagerModelView.model ? _taskManagerModelView.width/_taskManagerModelView.model.columnCount() : 0
                        }

                rowHeightProvider: function (Row) { //подгоняет высоту столбцов
                    return textId.height
                }

                delegate: Rectangle {
                    border{
                        color: 'black'
                        width: 1
                    }
                    color: "#dfd6b9"
                    Text {
                        id: textId
                        text: display
                        anchors.fill: parent
                        anchors.margins: 10
                        color: 'black'
                        font.pixelSize: 16
                        verticalAlignment: Text.AlignVCenter
                        horizontalAlignment: Text.AlignHCenter
                        wrapMode: Text.WordWrap //перенос строки
                        onContentHeightChanged: {
                            textId.height = contentHeight
                    //        console.log(textId.height)
                        }
                    }

                    MouseArea {
                        anchors.fill: parent
                        onClicked: {
                            console.log("proba:" + textId.text)
                        }
                    }
                }

//                Rectangle { // mask the headers
//                    z: 3
//                    color: "#000033"
//                    y: _taskManagerModelView.contentY
//                    x: _taskManagerModelView.contentX
//                    width: _taskManagerModelView.leftMargin
//                    height: _taskManagerModelView.topMargin
//                }

                Row {
                    id: _columnsHeader
                    y: _taskManagerModelView.contentY
                    z: 2
                    Repeater {
                        model: _taskManagerModelView.columns > 0 ? _taskManagerModelView.columns : 1
                        Label {
                            width: _backRect.width/_taskManagerModelView.columns
                            height: 35
                            text: _taskManagerModel.headerData(modelData, Qt.Horizontal)
                            color: 'black'

                            font.pixelSize: 15
                            padding: 10
                            verticalAlignment: Text.AlignVCenter
                            horizontalAlignment: Text.AlignHCenter
                            background: Rectangle {
                                radius: 5
                               // color: "#dfd6b9"
                            }
                        }
                    }
                }

            }
        }


        TextField{
            id: _txtTaskName
            placeholderText: "Введите наименование задачи"
            horizontalAlignment: TextInput.AlignHLeft
            selectByMouse: true
            wrapMode: TextEdit.Wrap

            Layout.row: 2
            Layout.column: 0
            Layout.fillWidth: true
            Layout.fillHeight: true
        }


        TextField{
            id: _txtDeadLine
            placeholderText: "Дата завершения: dd.mm.yyyy"
            inputMethodHints: Qt.ImhDigitsOnly
            verticalAlignment: TextInput.AlignVCenter
            horizontalAlignment: TextInput.AlignHCenter
            validator: RegularExpressionValidator { regularExpression: /^[0-9]{2}\.[0-9]{2}\.[0-9]{4}$/}

            Layout.row: 2
            Layout.column: 1
            Layout.fillWidth: true
            Layout.fillHeight: true
        }

        SpinBox{
            id: _sbProgress
            value: 0
            from: 0
            to: 10
            editable: false

            Layout.row: 2
            Layout.column: 2
            Layout.fillWidth: true
            Layout.fillHeight: true
        }

        Row {
            spacing: 10
            Layout.row: 3
            Layout.column: 2

            AcceptButton {
                id: _btnOK
                ToolTip{
                    text: "Принять"
                    visible: false
                }
                width: 40
                height: 40
                onClicked: {
               //    console.log("Длина даты: " + _txtDeadLine.text.length)
                    if(_txtTaskName.text.length != 0 &&
                            _txtDeadLine.text.length == 10 &&
                            _sbProgress.displayText.length != 0) { //проверим, если имя задачи введено - сохраним ее в файл
                        _TaskManager.Write = _txtTaskName.text + ";;" + _txtDeadLine.text + ";;" + _sbProgress.displayText
                        _taskManagerModel.addObject(_txtTaskName.text, _txtDeadLine.text, _sbProgress.displayText)
                    }
                }
            }

            DeleteButton {
                id: _btnDel
                ToolTip{
                    text: "Удалить"
                    visible: false
                }
                width: 40
                height: 40
                onClicked: {
                    Qt.quit() //пока что так, чтобы не пустовала
                }
            }
        }
    }


}
