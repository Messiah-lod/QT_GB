#include "explorer.h"

Explorer::Explorer(QWidget *parent) : QWidget(parent)
{
    this->setWindowTitle("Просмоторщик файловой истемы");


    model = new QFileSystemModel(this);
    model->setFilter(QDir::QDir::AllEntries);
    model->setRootPath("");
    model->setResolveSymlinks(false);//отобразит название ярлыка, а не файла на который он указывает

    tree = new QTreeView(this);
    tree->setModel(model);

    result = new QListWidget(this);
    splitter = new QSplitter(Qt::Vertical);

    lbl = new QLabel(this);
    lbl->setWordWrap(true);
    edit = new QLineEdit(this);
    edit->setText("");
    search = new QPushButton(this);
    search->setText("Search");

    gridLay = new QGridLayout(this);
    gridLay->addWidget(tree, 0, 0, 1,4);
    gridLay->addWidget(lbl, 1, 0, 1,4);
    gridLay->addWidget(edit, 2, 0, 1,3);
    gridLay->addWidget(search, 2, 3);

    QWidget *centralWgt = new QWidget(this);
    centralWgt->setLayout(gridLay);
    splitter->addWidget(centralWgt);
    splitter->addWidget(result);

    QGridLayout *mainGrid = new QGridLayout(this);
    mainGrid->addWidget(splitter);

    this->setLayout(mainGrid);
    this->setMinimumSize(800, 600);

    connect(tree, SIGNAL(clicked(QModelIndex)), this, SLOT(on_tree_clicked(QModelIndex)));
    connect(search, SIGNAL(clicked()), this, SLOT(on_search_clicked()));
}

void Explorer::on_tree_clicked(const QModelIndex &index)
{
    QFileInfo fileInfo = model->fileInfo(index);
    path = fileInfo.absolutePath();
    lbl->setText("Директория для поиска: " + path);
}

void Explorer::on_search_clicked()
{
     result->clear();
     SerchFiles *files = new SerchFiles(this);
     connect(files, SIGNAL(foundFile(QString)), this, SLOT(addSerchFile(QString)));
     QThread* thread = QThread::create(std::bind(&SerchFiles::startSerching, files, path, edit->text()));
     thread->start();
}

void Explorer::addSerchFile(QString pathFile)
{
    result->addItem(pathFile);
}
