#ifndef TESTCLASS_H
#define TESTCLASS_H

#include <QWidget>
#include <QTableView>

#include "taskmanagermodel.h"

class TestClass : public QWidget
{
    Q_OBJECT
public:
    explicit TestClass(QWidget *parent = nullptr);

private:
    QTableView *view;
    TaskManagerModel *model;
signals:

};

#endif // TESTCLASS_H
