#ifndef VIEWLANGUAGE_H
#define VIEWLANGUAGE_H

#include <QtWidgets>
#include <QtGui>
#include <QPushButton>
#include <QMessageBox>
#include <QListView>

class ViewLanguage : public QWidget
{
    Q_OBJECT
public:
    explicit ViewLanguage(QWidget *parent = nullptr);

private:
    QGridLayout *mainGrid; //создаем грид, который кладем на вкладку
    QLabel *desc;
    QListView *modelListView;
    QPushButton *btnAdd; //добавить элемент в список
    QPushButton *btnRm;  //удалить из списка
    QCheckBox *cbView; //изменяет представление

    QStandardItemModel *modelList;
    QStringList list;
    QModelIndex curInd;
signals:

public slots:
    void on_btnAdd_clicked();
    void on_btnRm_clicked();
    void on_cbView_clicked();
    void on_currentIndView_clicked(QModelIndex idx);
};

#endif // VIEWLANGUAGE_H
