#ifndef EXPLORER_H
#define EXPLORER_H

#include <QWidget>
#include <QGridLayout>
#include <QTreeView>
#include <QComboBox>
#include <QPushButton>
#include <QStandardItemModel>
#include <QApplication>
#include <QFileInfo>
#include <QDir>
#include <QFileSystemModel>
#include <QMessageBox>
#include <QLabel>
#include <QLineEdit>
#include <QListWidget>
#include <QSplitter>
#include <QtConcurrent>
#include <QFuture>

#include "serchfiles.h"

Q_PROPERTY(QStandardItemModel *model READ getCurrentModel WRITE setNewModel)

class Explorer : public QWidget
{
    Q_OBJECT
public:
    explicit Explorer(QWidget *parent = nullptr);

private:
       QGridLayout *gridLay {nullptr};
       QTreeView *tree {nullptr};
       QFileSystemModel *model {nullptr};
       QLabel *lbl {nullptr};
       QLineEdit *edit {nullptr};
       QPushButton *search {nullptr};
       QListWidget *result {nullptr};
       QSplitter *splitter {nullptr};

       QString path;
public slots:
       void on_tree_clicked(const QModelIndex &index);
       void on_search_clicked();
       void addSerchFile(QString pathFile);
protected:


};

#endif // EXPLORER_H
