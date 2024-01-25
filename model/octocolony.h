#ifndef OCTOCOLONY_H
#define OCTOCOLONY_H

#include "protocolony.h"

#include <QModelIndex>
#include <QAbstractItemModel>


// #include <QObject>

typedef QVector<QVector<QVariant>> DataMatrix;

class OctoColony : public ProtoColony
{

    Q_OBJECT
public:
    OctoColony(int rows, int cols);
    OctoColony(DataMatrix matrix);

signals:
    void cellChanged(int rows, int cols, const QVariant &value);

public:
    const int maxNeighboursCount = 8;

    void createPopulation() override;
    void introduceNeighbors(QString key) override;

    int m_rows, m_cols;

    void evolve();
};


#endif // OCTOCOLONY_H
