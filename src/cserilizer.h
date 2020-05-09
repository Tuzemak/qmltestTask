#ifndef CSERILIZER_H
#define CSERILIZER_H

#include <QObject>
#include <QJsonDocument>
#include <QFile>
#include <QPair>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>

class CAbstractSerilizer: public QObject
{
public:
    virtual void deserilize() = 0;
    virtual void serilize() =0;
};

class CJsonSerilizer : public CAbstractSerilizer
{
    Q_OBJECT
public:
    explicit CJsonSerilizer(QObject *parent = nullptr);

    void deserilize();
    void serilize() {};
    QList<QPair<uint32_t, QString>>& getData();

private:
    QFile _file;
    QList<QPair<uint32_t, QString>> _data;

signals:
    void serilizeError(const QString errMsg);

};

#endif // CSERILIZER_H
