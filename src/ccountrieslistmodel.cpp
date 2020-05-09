#include "ccountrieslistmodel.h"

CCountriesListModel::CCountriesListModel(QObject *parent)
    : QAbstractListModel(parent)
{
    connect(&_serilizer, SIGNAL(serilizeError(const QString)), this, SIGNAL(modelError(const QString)));
    _serilizer.deserilize();
    _data = _serilizer.getData();
}

QVariant CCountriesListModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    // FIXME: Implement me!
}

int CCountriesListModel::rowCount(const QModelIndex &parent) const
{
    return _data.count();
}

QVariant CCountriesListModel::data(const QModelIndex &index, int role) const
{
    if(role == Qt::DisplayRole) return QVariant(_data[index.row()].second);

    return QVariant();
}
