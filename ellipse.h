#ifndef ELLIPSE_H
#define ELLIPSE_H

#include "figure.h"

class Ellips : public Figure
{
public:
    explicit Ellips(QPoint *p = nullptr, QObject *parent = nullptr);


private:
       void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
       QRectF boundingRect() const override;
};

#endif // ELLIPSE_H
