#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "commandhandler.h"

int main(int argc, char *argv[]) {
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;
    qmlRegisterType<CommandHandler>("com.Zephyr", 1, 0, "CommandHandler");
    CommandHandler handler;
    engine.rootContext()->setContextProperty("CommandHandler", &handler);
    engine.load(QUrl(QStringLiteral("qrc:/Main.qml")));

    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
