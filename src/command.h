#ifndef COMMAND_H
#define COMMAND_H

#include <QString>
#include <QDateTime>
#include <QObject>

class Command : public QObject  // Make Command a QObject-derived class
{
    Q_OBJECT  // Use the Q_OBJECT macro

    Q_PROPERTY(QString commandContent READ getCommandContent WRITE setCommandContent NOTIFY commandContentChanged)
    Q_PROPERTY(QDateTime executeTime READ getExecuteTime CONSTANT)
    Q_PROPERTY(QString userExecute READ getUserExecute CONSTANT)

public:
    Command(QObject *parent = nullptr);  // Default constructor
    Command(const QString &commandContent, const QDateTime &executeTime, const QString &userExecute, QObject *parent = nullptr);

    QString getCommandContent() const;
    void setCommandContent(const QString &commandContent);

    QDateTime getExecuteTime() const;
    QString getUserExecute() const;

signals:
    void commandContentChanged(const QString &commandContent);

private:
    QString commandContent;
    QDateTime executeTime;
    QString userExecute;
};

#endif // COMMAND_H
