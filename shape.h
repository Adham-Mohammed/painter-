#ifndef SHAPES_H
#define SHAPES_H


#include <QPainter>
#include <QGraphicsItem>


class Shape: public QGraphicsItem
{
public:
    Shape();
    double getPerimeter();

    double perimeter;


    QString name;
    QPen pen;

};

#endif // SHAPES_H
