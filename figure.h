#ifndef FIGURE_H
#define FIGURE_H

#include <QObject>
#include <QGraphicsItem>
#include <QContextMenuEvent>
#include <QBrush>
#include <QPainter>
#include <QGraphicsSceneMouseEvent>
#include <QMessageBox>
#include <cmath>

class Figure : public QObject, public QGraphicsItem
{
    Q_OBJECT
    Q_INTERFACES(QGraphicsItem)
 //   Q_PROPERTY(QBrush brush)

public:
        explicit Figure(QObject *parent = nullptr);

signals:
        void reDraw();

private:
       void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override = 0;
       QRectF boundingRect() const override = 0;

protected:
       int x, y; //координаты положеня фигуры
       QPoint bpoint;
       bool moving; //флаг движения
       bool rotateFigure; //флаг поворота фигуры
       QBrush brush;

       void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
       void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;
       void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
};

#endif // FIGURE_H
