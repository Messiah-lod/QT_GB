#include "ellipse.h"

Ellips::Ellips(QPoint *p, QObject *parent) : Figure(parent)
{
    if(p) {
        x = p->x();
        y = p->y();
    }
}

void Ellips::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(brush);
    painter->drawEllipse(x, y, 200, 100);
    Q_UNUSED(option)
    Q_UNUSED(widget)
}

QRectF Ellips::boundingRect() const         // Обязателен для переопределения
{
   return QRectF(x, y, 200, 100);                // Текущие координаты
}
