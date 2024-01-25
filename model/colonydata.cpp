#include "colonydata.h"

ColonyData::ColonyData(QObject *parent)
    : QObject{parent}
{
    initMatrix();

    timer.setInterval(400);

    connect( &timer, &QTimer::timeout, this, &ColonyData::hit);



}

void ColonyData::appendData(const QModelIndex &index, const QVariant &value)
{
    if(dataMatrix[index.row()][index.column()] == value)
        return;

    dataMatrix[index.row()][index.column()] = value.toBool();
    emit dataCellChanged(index.row(), index.column());
}


void ColonyData::initMatrix()
{
    dataMatrix = DataMatrix(rows, QVector<QVariant>(columns, QVariant(false)));
}



