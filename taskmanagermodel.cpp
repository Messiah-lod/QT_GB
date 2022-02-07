#include "taskmanagermodel.h"

TaskManagerModel::TaskManagerModel(QObject *parent) :
    QAbstractTableModel(parent)
{
    modelData  = new QVector <rowData>;
}

TaskManagerModel::~TaskManagerModel()
{

}

void TaskManagerModel::addObject(QString _name, QString _deadLine, QString _progress)
{
    rowData row {_name,_deadLine,_progress};
    beginInsertRows(QModelIndex(), int(modelData->size()), int(modelData->size()));
    modelData->append(row);
    endInsertRows();
}

void TaskManagerModel::addObject(QByteArray _parametr)
{
    QString temp, parametr;
    parametr = _parametr;
    QVector <QString> list;
    //Получим текстовый файл, раскидаем по строкам
    for(int i = 0; i< parametr.size(); i++){
        if(parametr[i] == '\r' || parametr[i] == '\n' || parametr[i] == '\t'){
            list.push_back(temp);
            temp.clear();
        }
        else temp.push_back(parametr[i]);
    }

    //бежим по строкам, раскидываем по ячейкам
    for(int i = 0; i < list.size(); i++){
        int count = 0;
        temp.clear();
        QString _name,_deadLine,_progress;
        for(int j = 0; j < list[i].size(); j++){
            if(list[i][j] != ';')
                temp.push_back(list[i][j]);
            else {
                switch (count) {
                case 0: _name = temp; temp.clear() ;break;
                case 2: _deadLine = temp; temp.clear(); break;
                }
                count ++;
            }
        }
        _progress = temp;
        temp.clear();
        addObject(_name,_deadLine,_progress);
    }

}

void TaskManagerModel::delObject(const QModelIndex &index)
{
    beginRemoveRows(QModelIndex(), index.row(), index.row());
    modelData->removeAt(index.row());
    endRemoveRows();
}

void TaskManagerModel::delData()
{
    for (int k = 0; k < modelData->count(); k++)
        modelData->removeAt(k);
    modelData->clear();
}

QVariant TaskManagerModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if(role == Qt::DisplayRole)
    {
        if(orientation == Qt::Horizontal)
        {
            switch (section)
            {
            case 0:
                return tr("Наименование задачи");
            case 1:
                return tr("Дата завершения");
            case 2:
                return tr("Прогресс выполнения");
            }
        }
    }
    return QVariant();
}

int TaskManagerModel::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;
    return int(modelData->size());
}

int TaskManagerModel::columnCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;
    return 3;
}

QVariant TaskManagerModel::data(const QModelIndex &index, int role) const
{
    QVariant value;
    if (!index.isValid())
        return QVariant();
    if((role == Qt::DisplayRole || role == Qt::EditRole) && index.row() >= 0 && index.row() < rowCount()
            && index.column() >= 0 && index.column() < columnCount())
    {
        switch (index.column())
        {
        case 0:
            value = (*modelData)[index.row()].nameTask;
            break;
        case 1:
            value = (*modelData)[index.row()].deadLine;
            break;
        case 2:
            value = (*modelData)[index.row()].progress;
            break;
        }
        return value;
    }
    return QVariant();
}

Qt::ItemFlags TaskManagerModel::flags(const QModelIndex &index) const
{
    Qt::ItemFlags flags = QAbstractTableModel::flags(index);
        return index.isValid()
            ? (flags | Qt::ItemIsEditable)
            : flags;
}
