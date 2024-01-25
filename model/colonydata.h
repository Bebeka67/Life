#ifndef COLONYDATA_H
#define COLONYDATA_H

#include <QObject>
#include <QVector>
#include <QVariant>
#include <QDebug>
#include <QModelIndex>

#include "octocolony.h"


#include <QTimer>

typedef QVector<QVector<QVariant>> DataMatrix;

class ColonyData : public QObject
{
    Q_OBJECT

public:
    explicit ColonyData(QObject *parent = nullptr);


    // enum LifeState {
    //     Dead = 0,
    //     Alive
    // };

    int rowCount() {return rows;};
    int columnCount() {return columns;};

    DataMatrix getData() {return dataMatrix;}

    void appendData(const QModelIndex &index, const QVariant &value);

    void addColumn(){};
    void deleteColumn(){};
    void addRow(){};
    void deleteRow(){};


    QTimer timer;

    void run() {

        timer.stop();
        timer.start();

    }

    void stop()
    {
        timer.stop();
    }

public slots:
    void getDatas(int row, int column, const QVariant &value)
    {
        if(dataMatrix[row][column] == value)
            return;

        dataMatrix[row][column] = value.toBool();
        emit dataCellChanged(row, column);
    }

    void hit()
    {
        OctoColony* colony = new OctoColony(dataMatrix);
        connect(colony, &OctoColony::cellChanged, this, &ColonyData::getDatas);
        colony->evolve();
    }


signals:
    void dataModelChanged();
    void dataCellChanged(int row, int column);

private:

    int rows = 10;
    int columns = 10;


    void initMatrix();


    DataMatrix dataMatrix;
};

#endif // COLONYDATA_H
