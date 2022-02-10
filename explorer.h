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

Q_PROPERTY(QStandardItemModel *model READ getCurrentModel WRITE setNewModel)

class Explorer : public QWidget
{
    Q_OBJECT
public:
    explicit Explorer(QWidget *parent = nullptr);

private:
       QGridLayout *gridLay;
       QTreeView *tree;
       QFileSystemModel *model;
       QLabel *lbl;

public slots:
       void on_tree_clicked(const QModelIndex &index);

protected:


};

#endif // EXPLORER_H
