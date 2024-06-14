// CommandHandler.cpp
#include "commandhandler.h"
#include <pty.h>
#include <QtDebug>
#include <QDebug>
#include <QProcess>
#include <QDir>


CommandHandler::CommandHandler(QObject *parent) : QObject(parent)
{
    process = new QProcess(this);

    connect(process, &QProcess::readyReadStandardOutput, this, [this]() {
        QString output = process->readAllStandardOutput();
        emit commandOutput(output);
    });

    connect(process, &QProcess::readyReadStandardError, this, [this]() {
        QString errorOutput = process->readAllStandardError();
        emit commandOutput(errorOutput);
    });
}

void CommandHandler::receiveCommand(const QString &command)
{
    qDebug() << "Command received:" << command;
    execCommand(command);
}

void CommandHandler::execCommand(const QString &command)
{
    // Get the current working directory
    QString currentDir = QDir::currentPath();

    // Prepare the command to be executed
    QString fullCommand = QString("cd %1 && %2").arg(currentDir, command);

    // Emit the command with the current directory prefix
    emit handleCommand(currentDir + "$ " + command);

    // Start the process
    process->start("bash", QStringList() << "-c" << fullCommand);
}
