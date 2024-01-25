#include "octocolony.h"
#include <QDebug>
OctoColony::OctoColony(int rows, int cols)
    : ProtoColony()
    , m_rows(rows)
    , m_cols(cols)
{
    createPopulation();
    introduceNeighbors("");
}

OctoColony::OctoColony(DataMatrix matrix)
{
    for(int rows = 0; rows < matrix.length(); rows++)
    {
        for(int cols = 0; cols < matrix[0].length(); cols++)
        {
            QPoint point(rows,cols);
            auto currentKey = pointToKey(point);
            population.insert(currentKey,new Cell(point, matrix[rows][cols].toBool()));
        }
    }


    introduceNeighbors("");

}

void OctoColony::createPopulation()
{
    for(int i = 0; i < m_rows; i++)
    {
        for(int j = 0; j < m_cols; j++)
        {
            QPoint point = QPoint(i,j);
            auto currentKey = pointToKey(point);

            population.insert(currentKey,new Cell(point));

            // introduceNeighbors(currentKey);
        }
    }
    qDebug() << population;
}

void OctoColony::introduceNeighbors(QString key)
{
    /*
 * x-1 \  x  \ x+1
 * y-1 \ y-1 \ y-1
 * -------------
 * x-1 \  x  \ x+1
 *  y  \  y  \  y
 * --------------
 * x-1 \  x  \ x+1
 * y+1 \ y+1 \ y+1
 *
*/


    // перебор всех клеток в мапе
    foreach (auto cell, population)
    {
        //topLeft check

        // перебор всех соседей в листе клетки
        for(int neighbourPosition = 0; neighbourPosition < 8; neighbourPosition++)
        {
            if(cell->neighbours[neighbourPosition])
            {
                // The neighbor has already been found
                continue;
            }

            int x = cell->coordinates.x();
            int y = cell->coordinates.y();

            switch (neighbourPosition) {
            case Cell::TopLeft: {
                // чекаем верхний плевый угол
                auto topLeft = pointToKey(QPoint(x-1,y-1));

                // если такой имеется, то записываем его в клетку
                // а саму клетку в соответсвующего соседа
                if(population.contains(topLeft))
                {
                    auto topLeftNeighbour = population.value(topLeft);
                    cell->neighbours[Cell::TopLeft] = topLeftNeighbour;
                    topLeftNeighbour->neighbours[Cell::BotRight] = cell;
                }
                break;
            }
            case Cell::Top: {
                // чекаем верхний плевый угол
                auto top = pointToKey(QPoint(x,y-1));

                // если такой имеется, то записываем его в клетку
                // а саму клетку в соответсвующего соседа
                if(population.contains(top))
                {
                    auto topNeighbour = population.value(top);
                    cell->neighbours[Cell::Top] = topNeighbour;
                    topNeighbour->neighbours[Cell::Bot] = cell;
                }
                break;
            }
            case Cell::TopRight: {
                // чекаем верхний плевый угол
                auto topRight = pointToKey(QPoint(x+1, y-1));

                // если такой имеется, то записываем его в клетку
                // а саму клетку в соответсвующего соседа
                if(population.contains(topRight))
                {
                    auto topRightNeighbour = population.value(topRight);
                    cell->neighbours[Cell::TopRight] = topRightNeighbour;
                    topRightNeighbour->neighbours[Cell::BotLeft] = cell;
                }
                break;
            }
            case Cell::Right: {
                // чекаем верхний плевый угол
                auto right = pointToKey(QPoint(x+1,y));

                // если такой имеется, то записываем его в клетку
                // а саму клетку в соответсвующего соседа
                if(population.contains(right))
                {
                    auto rightNeighbour = population.value(right);
                    cell->neighbours[Cell::Right] = rightNeighbour;
                    rightNeighbour->neighbours[Cell::Left] = cell;
                }
                break;
            }
            case Cell::BotRight: {
                // чекаем верхний плевый угол
                auto botRight = pointToKey(QPoint(x+1,y+1));

                // если такой имеется, то записываем его в клетку
                // а саму клетку в соответсвующего соседа
                if(population.contains(botRight))
                {
                    auto botRightNeighbour = population.value(botRight);
                    cell->neighbours[Cell::BotRight] = botRightNeighbour;
                    botRightNeighbour->neighbours[Cell::TopLeft] = cell;
                }
                break;
            }
            case Cell::Bot: {
                // чекаем верхний плевый угол
                auto bot = pointToKey(QPoint(x,y+1));

                // если такой имеется, то записываем его в клетку
                // а саму клетку в соответсвующего соседа
                if(population.contains(bot))
                {
                    auto botNeighbour = population.value(bot);
                    cell->neighbours[Cell::Bot] = botNeighbour;
                    botNeighbour->neighbours[Cell::Top] = cell;
                }
                break;
            }
            case Cell::BotLeft: {
                // чекаем верхний плевый угол
                auto botLeft = pointToKey(QPoint(x-1,y+1));

                // если такой имеется, то записываем его в клетку
                // а саму клетку в соответсвующего соседа
                if(population.contains(botLeft))
                {
                    auto botLeftNeighbour = population.value(botLeft);
                    cell->neighbours[Cell::BotLeft] = botLeftNeighbour;
                    botLeftNeighbour->neighbours[Cell::TopRight] = cell;
                }
                break;
            }
            case Cell::Left: {
                // чекаем верхний плевый угол
                auto left = pointToKey(QPoint(x-1,y));

                // если такой имеется, то записываем его в клетку
                // а саму клетку в соответсвующего соседа
                if(population.contains(left))
                {
                    auto leftNeighbour = population.value(left);
                    cell->neighbours[Cell::Left] = leftNeighbour;
                    leftNeighbour->neighbours[Cell::Right] = cell;
                }
                break;
            }
            default:
                qDebug("WTF");
                break;
            }

        }
        // if( population.contains(pointToKey(cell->coordinates)))
        // {

        // }
    }

    qDebug() << "itroduction was done!";
}

void OctoColony::evolve()
{
    foreach (auto cell, population) {
        int counter = 0;

        foreach (auto neib, cell->neighbours) {
            if(neib && neib->alive)
                counter++;
        }

        bool newValue;
        if(cell->alive) {
            newValue = (counter == 3 || counter == 2 );
        } else {
            newValue = counter == 3;
        }

        emit cellChanged(cell->coordinates.x(), cell->coordinates.y(), QVariant(newValue));
    }

    qDebug() << population;

}
