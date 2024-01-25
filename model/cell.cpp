#include "cell.h"

Cell::Cell(QPoint point)
    : alive(false)
    , coordinates(point)
{
    key = QString::number(coordinates.x()) + "_" + QString::number(coordinates.y());
}

Cell::Cell(QPoint point, bool value)
    : alive(value)
    , coordinates(point)
{
    key = QString::number(coordinates.x()) + "_" + QString::number(coordinates.y());
}
