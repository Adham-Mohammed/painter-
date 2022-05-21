#ifndef MYSQUARE_H
#define MYSQUARE_H

#include "shape.h"


class  MySquare: public Shape
{
public:
    MySquare();
    MySquare(double w , double l, QPen p,QString n);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    double getPerimeter();

private:

    double width;
    double length;


    // QGraphicsItem interface
public:
    QRectF boundingRect() const;
};

#endif // MYSQUARE_H
