#include "myline.h"

MyLine::MyLine()
{

}

MyLine::MyLine(double l, QPen p, QString n)
{
    length = l;
    pen = p;
    name =n;
    perimeter = length/10;
    setFlag(ItemIsMovable);

}

void MyLine::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QRectF rec =boundingRect();
    painter->setPen(pen);
    painter->drawRect(rec);

}

QRectF MyLine::boundingRect() const
{
     return QRectF(0,0,0,length);

}


