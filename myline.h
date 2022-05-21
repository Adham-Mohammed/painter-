#ifndef MYLINE_H
#define MYLINE_H
#include "shape.h"



class MyLine: public Shape
{
public:
    MyLine();
    MyLine(double l, QPen p,QString n);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    double getPerimeter();

private:

    double length;


    // QGraphicsItem interface
public:
    QRectF boundingRect() const;
};

#endif // MYLINE_H
