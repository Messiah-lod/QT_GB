#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "figure.h"

class Rect : public Figure
{
public:
    explicit Rect(QPoint *p = nullptr, QObject *parent = nullptr);

private:
       void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
       QRectF boundingRect() const override;
};

#endif // RECTANGLE_H
