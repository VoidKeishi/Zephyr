// CommandHandler.h
#ifndef COMMANDHANDLER_H
#define COMMANDHANDLER_H

#include <QObject>
#include <QString>
#include <QProcess>
#include "command.h"

class CommandHandler : public QObject
{
    Q_OBJECT

public:
    explicit CommandHandler(QObject *parent = nullptr);
    Q_INVOKABLE void receiveCommand(Command* command);
signals:
    void handleCommand(const QString &command);
    void commandOutput(const QString &output);

private:
    void execCommand(const QString &command);
    QProcess *process;
    QString currentDir;
};
#endif // COMMANDHANDLER_H
