#include "explorer.h"

Explorer::Explorer(QWidget *parent) : QWidget(parent)
{
    this->setWindowTitle("Просмоторщик файловой истемы");


    model = new QFileSystemModel();
    model->setFilter(QDir::QDir::AllEntries);
    model->setRootPath("");
    model->setResolveSymlinks(false);//отобразит название ярлыка, а не файла на который он указывает

    tree = new QTreeView();
    tree->setModel(model);

    lbl = new QLabel;
    lbl->setWordWrap(true);

    gridLay = new QGridLayout(this);
    gridLay->addWidget(tree, 0, 0);
    gridLay->addWidget(lbl, 1, 0);

    this->setLayout(gridLay);

    QObject::connect(tree, SIGNAL(clicked(QModelIndex)), this, SLOT(on_tree_clicked(QModelIndex)));
}

void Explorer::on_tree_clicked(const QModelIndex &index)
{
    QFileInfo fileInfo = model->fileInfo(index);
    QString path = fileInfo.absolutePath();
    lbl->setText("Директория: " + path);
}
