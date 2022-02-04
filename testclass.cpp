#include "testclass.h"

#include <QGridLayout>

TestClass::TestClass(QWidget *parent)
    : QWidget{parent}
{
    QGridLayout *mainGrid = new QGridLayout(this);
    this->setLayout(mainGrid);

    model = new TaskManagerModel;
    view = new QTableView(this);
    view->setModel(model);
    mainGrid->addWidget(view);
}
