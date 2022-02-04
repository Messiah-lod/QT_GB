#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QDebug>
#include <QWidget>

#include "taskmanager.h"
#include "taskmanagermodel.h"

#include "testclass.h"
#include <QApplication>

int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif
    QGuiApplication app(argc, argv);

    qmlRegisterType<TaskManager>("TaskManager", 1,0, "TaskManager");
    qmlRegisterType<TaskManager>("TaskManagerModel", 1,0, "TaskManagerModel");

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    QApplication a(argc, argv);
    TestClass w;
//        w.setMinimumHeight(100);
//        w.setMinimumWidth(200);
//        w.setMaximumHeight(200);
//        w.setMaximumWidth(400);
        w.show();

    return app.exec();
}
