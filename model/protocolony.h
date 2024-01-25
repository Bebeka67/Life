#ifndef PROTOCOLONY_H
#define PROTOCOLONY_H

#include <QObject>

#include "cell.h"

class ProtoColony : public QObject
{
    Q_OBJECT
public:
    ProtoColony();

    enum Type {
        Octa,
        Hex
    };

    virtual void createPopulation() = 0;
    virtual void introduceNeighbors(QString key) = 0;

    QMap<QString,Cell*> population;

    QString pointToKey(QPoint coord);
    QPoint keyToPoint(QString key);
};

#endif // PROTOCOLONY_H
