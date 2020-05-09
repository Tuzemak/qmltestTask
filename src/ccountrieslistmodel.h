#ifndef CCOUNTRIESLISTMODEL_H
#define CCOUNTRIESLISTMODEL_H

#include <QAbstractListModel>
#include "cserilizer.h"

class CCountriesListModel : public QAbstractListModel
{
    Q_OBJECT

public:
    explicit CCountriesListModel(QObject *parent = nullptr);

    // Header:
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;

    // Basic functionality:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;    
signals:
    void modelError(const QString msg);

private:
    QList<QPair<uint32_t, QString>> _data;
    CJsonSerilizer _serilizer;
};

#endif // CCOUNTRIESLISTMODEL_H
