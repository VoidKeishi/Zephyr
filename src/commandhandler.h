// CommandHandler.h
#ifndef COMMANDHANDLER_H
#define COMMANDHANDLER_H

#include <QObject>
#include <QString>
#include <QProcess>

class CommandHandler : public QObject
{
    Q_OBJECT

public:
    explicit CommandHandler(QObject *parent = nullptr);
public slots:
    void receiveCommand(const QString &command);
    void execCommand(const QString &command);

signals:
    void handleCommand(const QString &command);
    void commandOutput(const QString &output);

private:
    QProcess *process;
};
#endif // COMMANDHANDLER_H
