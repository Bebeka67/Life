#ifndef CELL_H
#define CELL_H

#include <QList>
#include <QDebug>

class Cell
{
public:
    Cell(QPoint);
    Cell(QPoint, bool value);

    bool alive;

    // virtual void findNeighbours() = 0;

    friend QDebug operator << (QDebug d, const Cell &cell) {
        return d << "key: " << cell.key << cell.coordinates;
    }
    friend QDebug operator << (QDebug d, const Cell *cell) {
        return d << "key: " << cell->key <<cell->coordinates;
    }

    QPoint coordinates;
    QString key;


    enum Neighbour {
        TopLeft = 0,
        Top,
        TopRight,
        BotRight,
        Bot,
        BotLeft,
        Left,
        Right
    };

    QList<Cell*> neighbours = { nullptr, nullptr, nullptr,
                                nullptr, /*this*/ nullptr,
                                nullptr, nullptr, nullptr };

/*                                 0        1       2
 *                                 6      this      7
 *                                 5        4       3
 *      for octocell             topLeft   top    topRight
 *                               left      this   right
 *                               botLeft   bot    botRight
 *
 *      for hexocell             topLeft   top    topRight
 *                               null      this   null
 *                               botLeft   bot    botRight
*/
};

#endif // CELL_H
