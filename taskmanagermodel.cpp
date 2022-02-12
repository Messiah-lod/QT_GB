#include "taskmanagermodel.h"

TaskManagerModel::TaskManagerModel(QObject *parent) :
    QSqlTableModel(parent)
{
    database = QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName("taskmanager.db");

    if (!database.open()) qDebug() << "не возможно открыть БД";
    QSqlQuery query(database);

    if(!query.exec("CREATE TABLE if not exists TaskManager (	"
                   "id	INTEGER NOT NULL,	"
                   "name	TEXT NOT NULL,	"
                   "deadline	TEXT,	"
                   "progress	INTEGER,	"
                   "PRIMARY KEY(id)  );"))
    {
         qDebug() << "Не смогли создать таблицу";
        qDebug() << query.lastError().text();
    }

  //  this->setEditStrategy(QSqlTableModel::EditStrategy::OnFieldChange);

    this->setSort(0,Qt::AscendingOrder); //сортировка по 1 столбику
}

TaskManagerModel::~TaskManagerModel()
{
    database.close();
}

void TaskManagerModel::addObjectFromBD()
{
    QSqlQuery query(database);
    query.exec("SELECT name,deadLine,progress from TaskManager");
    this->setQuery(query);
  //  this->setHeaderData(0, Qt::Horizontal, tr("ID"));
    this->setHeaderData(0, Qt::Horizontal, tr("Наименование"));
    this->setHeaderData(1, Qt::Horizontal, tr("Срок исполнения"));
    this->setHeaderData(2, Qt::Horizontal, tr("Прогресс"));
}


void TaskManagerModel::addObject(QString _name, QString _deadLine, QString _progress)
{
    QSqlQuery query(database);
    if(!query.exec("insert into TaskManager (name, deadLine, progress) "
                   "values ('" +  _name + "','" + _deadLine + "'," + _progress + ")"))
    {
        qDebug() << "Не смогли вставить запись";
        qDebug() << query.lastError().text();
    }
    addObjectFromBD();
}

void TaskManagerModel::delObject(const QModelIndex &index)
{
    Q_UNUSED(index)
//    beginRemoveRows(QModelIndex(), index.row(), index.row());
//    modelData->removeAt(index.row());
//    endRemoveRows();
}

void TaskManagerModel::delData()
{
    QSqlQuery query(database);
    if(!query.exec("DELETE FROM TaskManager") )
    {
        qDebug() << "Не смогли удалить данные в таблице";
        qDebug() << query.lastError().text();
    }
    addObjectFromBD();
}
