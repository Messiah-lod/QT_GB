#ifndef STAR_H
#define STAR_H

#include "figure.h"

class Star : public Figure
{
public:
    explicit Star(QPoint *p = nullptr, QObject *parent = nullptr);


private:
       void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
       QRectF boundingRect() const override;
};

#endif // STAR_H
