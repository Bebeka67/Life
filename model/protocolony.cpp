#include "protocolony.h"

ProtoColony::ProtoColony() : QObject(nullptr) {}

QString ProtoColony::pointToKey(QPoint coord)
{
    return QString::number(coord.x()) + "_" + QString::number(coord.y());
}

QPoint ProtoColony::keyToPoint(QString key)
{
    auto parsed = key.split("_");
    return QPoint(parsed[0].toInt(), parsed[1].toInt());
}
