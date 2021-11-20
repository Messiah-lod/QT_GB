#include "figure.h"

Figure::Figure(QObject *parent) : QObject(parent), QGraphicsItem()
{
    x = 0;
    y = 0;
    brush.setColor(QColor(rand() % 256, rand() % 256, rand() % 256));
    brush.setStyle(Qt::BrushStyle::SolidPattern); // Полностью закрашивать
    setPos(x,y);
    moving = false;
//    qDebug() << "Запилили фигуру";
}

void Figure::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
   if (event->button() == Qt::LeftButton) {       // Левая кнопка, режим перемещения
       moving = true;                            // Флаг активности перемещения
       bpoint = event->pos().toPoint();          // Запоминаем начальные координаты мыши
       emit reDraw();
   }
   else if (event->button() == Qt::MiddleButton) {       // колесо, режим вращения мышки
       rotateFigure = true;                            // Флаг активности перемещения
       bpoint = event->pos().toPoint();          // Запоминаем начальные координаты мыши
       emit reDraw();
   }
   qDebug() << "Нажали на фигуре мышь";
}

void Figure::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
   if (event->button() == Qt::LeftButton) {
       moving = false;                            // Снимаем флаг на перемещение
       emit reDraw();
   }
   else if (event->button() == Qt::MiddleButton) {       // колесо, режим вращения мышки
       rotateFigure = false;                      //закончили вращать фигуру
       emit reDraw();
   }
   qDebug() << "Отжали на фигуре мышь";
   QGraphicsItem::mouseReleaseEvent(event);
}

void Figure::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
   if (moving) {
       QPoint p = event->pos().toPoint() - bpoint; // Вычисляем вектор смещения
       x += p.x();
       y += p.y();
       bpoint = event->pos().toPoint();           // Запоминаем новую позицию курсора
       emit reDraw();                             // Переотрисовываем
   }
   else if(rotateFigure){
       QPoint p = event->pos().toPoint();
       int angle = 0;
       angle = static_cast<int> ( qRadiansToDegrees(atan2(p.x()-bpoint.x(), p.y()-bpoint.y()) ));// * 180.0 / M_PI  ) ;

       QTransform t;
       QPointF xlate = boundingRect().center();
       t.translate(xlate.x(), xlate.y());
       t.rotate(angle);
       t.translate(-xlate.x(), -xlate.y());
       setTransform(t);

       emit reDraw();
   }
//   qDebug() << "Двигаем фигуру";
   QGraphicsItem::mouseMoveEvent(event);
}
