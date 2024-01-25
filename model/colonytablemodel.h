#ifndef COLONYTABLEMODEL_H
#define COLONYTABLEMODEL_H

#include <QAbstractTableModel>
#include "colonydata.h"


class ColonyTableModel : public QAbstractTableModel
{
    Q_OBJECT

public:
    explicit ColonyTableModel(QObject *parent = nullptr);


    enum ColonyRoles {
        CellLifeState = 0
    };

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    int columnCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole) override;


    QHash<int, QByteArray> roleNames() const override;



    Q_INVOKABLE void addColumn()        {colonyData->addColumn();};
    Q_INVOKABLE void deleteColumn()     {colonyData->deleteColumn();};

    Q_INVOKABLE void addRow()           {colonyData->addColumn();};
    Q_INVOKABLE void deleteRow()        {colonyData->deleteColumn();};

    Q_INVOKABLE void run() {colonyData->run();}
Q_INVOKABLE void stop() {colonyData->stop();}

private slots:

    void updateModel();
    void updateCell(int row, int column);

private:

    ColonyData* colonyData;
};

#endif // COLONYTABLEMODEL_H
