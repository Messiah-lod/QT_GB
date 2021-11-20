#include "rectangle.h"

Rect::Rect(QPoint *p, QObject *parent) : Figure(parent)
{
    if(p) {
        x = p->x();
        y = p->y();
    }
}

void Rect::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(brush);
    painter->drawRect(x, y, 200, 100);
    Q_UNUSED(option)
    Q_UNUSED(widget)
}

QRectF Rect::boundingRect() const         // Обязателен для переопределения
{
   return QRectF(x, y, 200, 100);                // Текущие координаты
}
