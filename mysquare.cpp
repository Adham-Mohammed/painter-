#include "mysquare.h"

MySquare::MySquare()
{


}

MySquare::MySquare(double w, double l, QPen p, QString n)
{
    width = w;
    length = l;
    pen = p;
    name =n;
    perimeter = (width)/5 + (length)/5;
    setFlag(ItemIsMovable);
}

void MySquare::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QRectF rec =boundingRect();
    painter->setPen(pen);
    painter->drawRect(rec);

}


QRectF MySquare::boundingRect() const
{
   return QRectF(0,0,width,length);
}


