#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "command.h"
#include "commandhandler.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    qmlRegisterType<Command>("com.Zephyr", 1, 0, "Command");  // Register the Command class
    qmlRegisterType<CommandHandler>("com.Zephyr", 1, 0, "CommandHandler");  // Register the CommandHandler class

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/Main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
        &app, [url](QObject *obj, const QUrl &objUrl) {
            if (!obj && url == objUrl)
                QCoreApplication::exit(-1);
        }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
