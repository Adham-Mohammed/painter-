#ifndef MYCIRCLE_H
#define MYCIRCLE_H

#include "shape.h"


class MyCircle: public Shape
{
public:
    MyCircle();
    MyCircle(double r, QPen p,QString n);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    double getPerimeter();

private:

    double radius;


    // QGraphicsItem interface
public:
    QRectF boundingRect() const;
};

#endif // MYCIRCLE_H
