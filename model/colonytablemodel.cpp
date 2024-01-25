#include "colonytablemodel.h"

ColonyTableModel::ColonyTableModel(QObject *parent)
    : QAbstractTableModel{parent}
    , colonyData(new ColonyData(this))
{
    connect( colonyData, &ColonyData::dataModelChanged, this, &ColonyTableModel::updateModel);
    connect( colonyData, &ColonyData::dataCellChanged, this, &ColonyTableModel::updateCell);

}

int ColonyTableModel::rowCount(const QModelIndex &parent) const
{
    return colonyData->rowCount();
}

int ColonyTableModel::columnCount(const QModelIndex &parent) const
{
    return colonyData->columnCount();
}

QVariant ColonyTableModel::data(const QModelIndex &index, int role) const
{

    return colonyData->getData()[index.row()][index.column()];

    //return QVariant(QString("%0 %1").arg(index.column()).arg(index.row()));
}

bool ColonyTableModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if(role == CellLifeState)
    {
        colonyData->appendData(index, value);
        return true;
    }

    return false;
}

QHash<int, QByteArray> ColonyTableModel::roleNames() const
{
    QHash<int, QByteArray> roles;

    roles[CellLifeState] = "lifeState";
    return roles;
}

void ColonyTableModel::updateModel()
{
    this->layoutChanged();
}

void ColonyTableModel::updateCell(int row, int column)
{
    QModelIndex topLeft = createIndex(row, column);
    emit dataChanged(topLeft, topLeft, {});
}
