#include "command.h"

Command::Command(QObject *parent)
    : QObject(parent) {}  // Default constructor

Command::Command(const QString &commandContent, const QDateTime &executeTime, const QString &userExecute, QObject *parent)
    : QObject(parent), commandContent(commandContent), executeTime(executeTime), userExecute(userExecute) {}

QString Command::getCommandContent() const {
    return commandContent;
}

void Command::setCommandContent(const QString &commandContent) {  // Setter method for commandContent
    if (this->commandContent != commandContent) {
        this->commandContent = commandContent;
        emit commandContentChanged(this->commandContent);  // Emit a signal when the commandContent changes
    }
}

QDateTime Command::getExecuteTime() const {
    return executeTime;
}

QString Command::getUserExecute() const {
    return userExecute;
}
