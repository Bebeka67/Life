#ifndef LIFEGAME_H
#define LIFEGAME_H

#include <QObject>
#include <QMap>
#include <QHash>

#include <QAbstractTableModel>


#include "model/colonytablemodel.h"


class LifeGame : public QObject
{
    Q_OBJECT


    Q_PROPERTY(QAbstractTableModel* model READ model CONSTANT)

public:
    explicit LifeGame(QObject *parent = nullptr);


    QAbstractTableModel *model() const;



private:

    ColonyTableModel* m_model;
};

#endif // LIFEGAME_H
