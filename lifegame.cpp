#include "lifegame.h"

#include <QDebug>

LifeGame::LifeGame(QObject *parent)
    : QObject{parent}
    , m_model(new ColonyTableModel)
{
}

QAbstractTableModel *LifeGame::model() const
{
    return m_model;
}
