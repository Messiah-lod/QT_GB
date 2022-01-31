#ifndef COMPUTERVIEW_H
#define COMPUTERVIEW_H

#include <QtWidgets>
#include <QtGui>
#include <QPushButton>
#include <QMessageBox>
#include <QListView>

class ComputerView : public QWidget
{
    Q_OBJECT
public:
    explicit ComputerView(QWidget *parent = nullptr);

private:
    QGridLayout *mainGrid; //создаем грид, который кладем на вкладку
    QLabel *desc;
    QTableView *computerView;
    QStandardItemModel *computerModel;
    QPushButton *btnSelected;
    QPushButton *btnAdd;

    QItemSelectionModel* computerSelectionModel;

    QList<QStandardItem *> standardItemsList; //строка с данными (лист item'ов)
signals:

public slots:
    void on_btnSelected_clicked(); //слот при изменении цвета
    void on_btnAdd_clicked();
};

#endif // COMPUTERVIEW_H
