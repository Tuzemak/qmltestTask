#include "cserilizer.h"

CJsonSerilizer::CJsonSerilizer(QObject *parent)
{
    _data.clear();
}

void CJsonSerilizer::deserilize()
{
    QFile file("countries.json");
    if (!file.open(QIODevice::ReadOnly))
    {
        emit serilizeError("Unable to open file");
        return;
    }

    QJsonDocument doc(QJsonDocument::fromJson(file.readAll()));

    if (doc["countries"].isArray() == true)
    {
        QJsonArray countries(doc["countries"].toArray());
        for (QJsonValue item: countries)
        {
            if (item.isObject() == true )
            {
                QJsonObject country(item.toObject());
                if (country.contains("code") && country.contains("name"))
                {
                    _data.push_back(QPair<uint32_t, QString>(country["code"].toInt(), country["name"].toString()));
                }
            }
            else emit serilizeError("Incorrect country entry");
        }
    }
    else emit serilizeError("Countries array is not exists");
}

QList<QPair<uint32_t, QString> > &CJsonSerilizer::getData()
{
    return _data;
}
