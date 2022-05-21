#include "mycircle.h"

MyCircle::MyCircle()
{

}

MyCircle::MyCircle(double r, QPen p, QString n)
{

    radius = r*2;
    pen = p;
    name =n;
    perimeter = 2 * 3.1416 * (radius/10);
    setFlag(ItemIsMovable);
}

void MyCircle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QRectF rec =boundingRect();
    painter->setPen(pen);
    painter->drawEllipse(rec);

}

QRectF MyCircle::boundingRect() const
{
    return QRectF(0,0,radius,radius);
}


