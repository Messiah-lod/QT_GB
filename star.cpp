#include "star.h"

Star::Star(QPoint *p, QObject *parent) : Figure(parent)
{
    if(p) {
        x = p->x();
        y = p->y();
    }
}


void Star::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(brush);
    QPainterPath star;
    star.moveTo(x+80, y);
    star.lineTo(x+98, y+54);
    star.lineTo(x+160, y+54);
    star.lineTo(x+110, y+90);
    star.lineTo(x+130, y+148);
    star.lineTo(x+80, y+112);
    star.lineTo(x+30, y+148);
    star.lineTo(x+50, y+90);
    star.lineTo(x, y+54);
    star.lineTo(x+62, y+54);
    star.lineTo(x+80, y);
    painter->drawPath(star);
    Q_UNUSED(option)
    Q_UNUSED(widget)
}

QRectF Star::boundingRect() const         // Обязателен для переопределения
{
   return QRectF(x, y, 160, 148);                // Текущие координаты
}
