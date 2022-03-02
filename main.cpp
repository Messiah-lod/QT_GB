#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QDebug>
#include <QWidget>

#include "taskmanager.h"
#include "taskmanagermodel.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    qmlRegisterType<TaskManager>("TaskManager", 1,0, "TaskManager"); //работа с файлами
    qmlRegisterType<TaskManagerModel>("TaskManagerModel", 1, 0, "TaskManagerModel");

    const QIcon mainIcon = QIcon::fromTheme("mainIcon", QIcon(":/img/1086460.png"));
    app.setWindowIcon(mainIcon);

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
