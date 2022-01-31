#include "computerview.h"

ComputerView::ComputerView(QWidget *parent) : QWidget(parent)
{

    mainGrid = new QGridLayout(this);
    desc = new QLabel(this);
    desc->setText("По нажатию на кнопку \"Выделить\" меняется задний фон ячейки таблицы");

    computerModel = new QStandardItemModel(this);
    computerModel->setColumnCount(4);
    computerModel->setHorizontalHeaderLabels(QStringList() << "№" << "Имя компьютера" << "IP адрес" << "MAC адрес");

    for (int i =0 ; i < 5; i++) {
        standardItemsList.append(new QStandardItem(QString::number(i+1)));//№
        standardItemsList.append(new QStandardItem("Компьютер № "+ QString::number(i+1)));//Имя компьютера
        standardItemsList.append(new QStandardItem("192.168.1."+ QString::number(i+10)));//IP адрес
        standardItemsList.append(new QStandardItem("AAA:AAA:AAA:AAA:AAA:AAA"));//MAC адрес
        computerModel->insertRow(computerModel->rowCount(), standardItemsList);
        standardItemsList.clear();
    }

    computerSelectionModel = new QItemSelectionModel(computerModel);
    computerView = new QTableView(this);
    computerView->setModel(computerModel);
    computerView->setSelectionModel(computerSelectionModel);
    computerView->resizeColumnsToContents();
    computerView->verticalHeader()->hide();

    btnSelected = new QPushButton(this);
    btnSelected->setText("Выделить");
    btnAdd = new QPushButton(this);
    btnAdd->setText("Добавить");

    mainGrid->addWidget(desc, 0, 0, 1,4);
    mainGrid->addWidget(computerView, 1, 0, 1,4);
    mainGrid->addWidget(btnSelected, 2, 0, 1,2);
    mainGrid->addWidget(btnAdd, 2, 2, 1,2);

    connect(btnSelected, SIGNAL(clicked()), this, SLOT(on_btnSelected_clicked()));
    connect(btnAdd, SIGNAL(clicked()), this, SLOT(on_btnAdd_clicked()));

    this->setLayout(mainGrid);
}

void ComputerView::on_btnSelected_clicked(){
    QModelIndexList selectedIndex = computerSelectionModel->selection().indexes();//лист выделенных индексов
    for(int i = 0; i < selectedIndex.size(); i++)
        computerModel->itemFromIndex(selectedIndex[i])->setBackground(Qt::cyan);
}

void ComputerView::on_btnAdd_clicked(){
    standardItemsList.append(new QStandardItem(QString::number(computerModel->rowCount()+1)));//№
    computerModel->insertRow(computerModel->rowCount(), standardItemsList);
    standardItemsList.clear();
}
