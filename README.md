# Zephyr
Zephyr is a sleek and efficient terminal application built with QML and the Qt Framework. Designed for performance and simplicity.
## Deb Package
```bash
    git clone https://github.com/VoidKeishi/Zephyr.git
    cd Zephyr-Deb
    sudo dpkg -i zephyr.deb
```
Class Diagram
command.h
```plantuml
- commandContent : QString
- commandType : QString
- executionTime : QDateTime
- userExecute : QString
+ Command(commandContent : QString, commandType : QString, executionTime : QDateTime, userExecute : QString)
+ getCommandContent() : QString
+ getCommandType() : QString
+ getExecutionTime() : QDateTime
+ getUserExecute() : QString
+ setCommandContent(commandContent : QString) : void
+ setCommandType(commandType : QString) : void
+ setExecutionTime(executionTime : QDateTime) : void
+ setUserExecute(userExecute : QString) : void
```
commandHandler.h
```plantuml
- commandHistory : QVector<QString>
- *process : QProcess
- currentDir : QString
+ handleCommand(command : QString) : void
+ commandOutput(output : QString) : void
+ receiveCommand(command : QString) : void
+ getNextCommand() : QString
+ getPreviousCommand() : QString
+ addCommandToHistory(command : QString) : void
- execCommand(command : QString) : void
```
