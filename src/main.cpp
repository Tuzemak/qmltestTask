#include <QGuiApplication>
#include <QtQml>
#include <QQmlApplicationEngine>
#include "ccountrieslistmodel.h"
#include "cbusinesslogic.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);
    qmlRegisterType<CCountriesListModel>("com.testtask.CountriesListModel", 1, 0, "CountriesListModel");
    qmlRegisterType<CBusinessLogic>("com.testtask.BusinessLogic", 1, 0, "BusinessLogic");

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
