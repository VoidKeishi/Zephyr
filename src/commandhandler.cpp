// CommandHandler.cpp
#include "commandhandler.h"
#include <pty.h>
#include <QtDebug>
#include <QDebug>
#include <QProcess>
#include <QDir>


CommandHandler::CommandHandler(QObject *parent) : QObject(parent), currentDir(QDir::currentPath())
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
    // Prepare the command to be executed
    QString fullCommand = QString("cd %1 && %2").arg(currentDir, command);

    // If the command is a cd command, update currentDir
    if (command.startsWith("cd ")) {
        QDir dir(currentDir);
        dir.cd(command.mid(3));
        currentDir = dir.absolutePath();  // Update currentDir to the new absolute path
    }

    // Start the process
    process->start("bash", QStringList() << "-c" << fullCommand);

    // Emit the command with the current directory prefix
    emit handleCommand(currentDir + "$ " + command);

}
