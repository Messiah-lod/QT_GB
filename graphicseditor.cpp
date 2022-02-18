#include "graphicseditor.h"

graphicsEditor::graphicsEditor(QWidget *parent)
    : QGraphicsView(parent)
{
    scence = new QGraphicsScene(this);                      // Новая сцена
    this->setScene(scence);
    this->setInteractive(true);
    this->setDragMode(QGraphicsView::RubberBandDrag);
//    setTransformationAnchor(QGraphicsView::AnchorUnderMouse);
//    this->setAlignment(Qt::AlignCenter);                        // Делаем привязку содержимого к центру

    setFixedSize(820, 620);
//    setMinimumHeight(600);
//    setMinimumWidth(800);

    int h = 600;
    int w = 800;
    scence->setSceneRect(0,0,w,h);


}

void graphicsEditor::scaleView(int angle)
{
    // zoom
    this->setTransformationAnchor(QGraphicsView::AnchorUnderMouse);
    const ViewportAnchor anchor = this->transformationAnchor();
    qreal factor;
    (angle > 0) ? factor = 1.1 : factor = 0.9;
    this->scale(factor, factor);
//    rotate(factor);
    this->setTransformationAnchor(anchor);
}

void graphicsEditor::updateView()
{
    scence->update();
    this->update();
}

void graphicsEditor::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton && this->itemAt(event->pos()) == nullptr) {       // Левая кнопка
        QPoint p = event->pos();
        if(typeFigure == 1) {
            Rect *rect = new Rect(&p);
            scence->addItem(rect);
            QObject::connect(rect, &Rect::reDraw, this, &graphicsEditor::updateView);
            typeFigure = 2;
        } else if(typeFigure == 2) {
            Ellips *el = new Ellips(&p);
            scence->addItem(el);
            QObject::connect(el, &Ellips::reDraw, this, &graphicsEditor::updateView);
            typeFigure = 3;
        } else if(typeFigure == 3) {
            Star *star = new Star(&p);
            scence->addItem(star);
            QObject::connect(star, &Star::reDraw, this, &graphicsEditor::updateView);
            typeFigure = 1;
        }
    }
    if (event->button() == Qt::RightButton && this->itemAt(event->pos()) != nullptr)       // Правая кнопка
    {
        //            qDebug() << "Нашли фигуру ПКМ";
        QGraphicsItem *item = itemAt(event->pos()); //получили объект под кликом
        //            scence->removeItem(item);
        delete item;
        updateView();
    }
    QGraphicsView::mousePressEvent(event);  //транслируем сигнал дальше от родителя
}

void graphicsEditor::wheelEvent(QWheelEvent *event)
{
    int angle = event->angleDelta().y(); //определяем куда крутим колесо

    scaleView(angle);

    QGraphicsView::wheelEvent(event);
}

void graphicsEditor::keyPressEvent(QKeyEvent *event)
{
    int angle = 0;

    if (event->key() == Qt::Key_Minus){
        angle = -1;
        scaleView(angle);
    } else if (event->key() == Qt::Key_Plus) {
        angle = 1;
        scaleView(angle);
    }

    QGraphicsView::keyPressEvent(event);
}
