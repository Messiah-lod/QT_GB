#include "viewlanguage.h"

ViewLanguage::ViewLanguage(QWidget *parent) : QWidget(parent)
{
    list << "C++" << "Python" << "Java"<< "C#"<< "PHP"<< "JavaScript";
    modelList = new QStandardItemModel(int(list.size()), 1, this);
    for (int i = 0; i < modelList->rowCount(); ++i) {
        QModelIndex index = modelList->index(i, 0);
        QString str = list[i];
        modelList->setData(index, str,Qt::DisplayRole);
        modelList->setData(index, QIcon(":/icon/Icons/" + str + ".png"),Qt::DecorationRole);
    }

    mainGrid = new QGridLayout(this);
    desc = new QLabel(this);
    modelListView = new QListView(this);
    modelListView->setModel(modelList);
    btnAdd = new QPushButton(this);
    btnAdd->setText("Добавить");
    btnRm = new QPushButton(this);
    btnRm->setText("Удалить");
    cbView = new QCheckBox(this);
    cbView->setText("Режим иконок");

    desc->setWordWrap(true);
    desc->setText("Названия языков программирования \n");

    mainGrid->addWidget(desc, 0 ,0, 1, 6);
    mainGrid->addWidget(modelListView, 1, 0 , 1, 6);
    mainGrid->addWidget(btnAdd, 2 ,0, 1, 2);
    mainGrid->addWidget(btnRm, 2 ,2, 1, 2);
    mainGrid->addWidget(cbView, 2 ,4, 1, 2);

    this->setLayout(mainGrid);
    this->setWindowTitle("Список языков программирования");

    connect(btnAdd, SIGNAL(clicked()), this, SLOT(on_btnAdd_clicked()));
    connect(btnRm, SIGNAL(clicked()), this, SLOT(on_btnRm_clicked()));
    connect(cbView, SIGNAL(clicked()), this, SLOT(on_cbView_clicked()));
    connect(modelListView, SIGNAL(clicked(QModelIndex)), this, SLOT(on_currentIndView_clicked(QModelIndex)));


    modelListView->setDragDropMode(QAbstractItemView::InternalMove);
    modelListView->setDefaultDropAction(Qt::TargetMoveAction);
    modelListView->setMovement(QListView::Free);
}

void ViewLanguage::on_btnAdd_clicked(){
    QStandardItem *item = new QStandardItem;
    item->setText("Новый язык");
    item->setIcon(QIcon(":/icon/Icons/others.ico"));
    modelList->appendRow(item);
}

void ViewLanguage::on_btnRm_clicked(){
//    modelList->removeRow(curInd.row());
    modelList->removeRow(modelListView->currentIndex().row());

}

void ViewLanguage::on_cbView_clicked(){
    if(cbView->isChecked()) modelListView->setViewMode(QListView::IconMode);
    else modelListView->setViewMode(QListView::ListMode);
}

void ViewLanguage::on_currentIndView_clicked(QModelIndex idx){
    Q_UNUSED(idx)
 //   curInd = idx;
}
