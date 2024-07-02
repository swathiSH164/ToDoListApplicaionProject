#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <qqmlcontext.h>
#include "TaskManager.h"
#include <gtest/gtest.h>

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    TaskManager manager;
    engine.rootContext()->setContextProperty("taskmanager",&manager);
    ::testing::InitGoogleTest(&argc, argv);
    RUN_ALL_TESTS();
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));  
    if (engine.rootObjects().isEmpty())
        return -1;
    return app.exec();
}
