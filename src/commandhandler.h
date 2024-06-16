// CommandHandler.h
#ifndef COMMANDHANDLER_H
#define COMMANDHANDLER_H

#include <QObject>
#include <QString>
#include <QProcess>
#include <QVector>
#include "command.h"

class CommandHandler : public QObject
{
    Q_OBJECT

public:
    explicit CommandHandler(QObject *parent = nullptr);
    Q_INVOKABLE void receiveCommand(Command* command);
    Q_INVOKABLE QString getPreviousCommand();
    Q_INVOKABLE QString getNextCommand();
    void addCommandToHistory(const QString &command);

signals:
    void handleCommand(const QString &command);
    void commandOutput(const QString &output);

private:
    QVector<QString> commandHistory;  // Vector to store the command history
    int commandIndex = -1;  // Index of the current command in the command history
    void execCommand(const QString &command);
    QProcess *process;
    QString currentDir;
};
#endif // COMMANDHANDLER_H
