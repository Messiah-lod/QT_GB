#include "taskmanagermodel.h"

TaskManagerModel::TaskManagerModel(QObject *parent):
    QStandardItemModel(parent)
{
    const QStringList labels {"Наименование задачи","Срок выполнения","Прогресс"};
    setHorizontalHeaderLabels(labels);

    // Заполняем модель данными построчно
    for (int i = 0; i < 4; ++i)
    {
        add(Name+QString::number(i), DeadLine, Progress);
    }

}

QVariant TaskManagerModel::data(const QModelIndex &index, int role) const
{
    switch(role)
    {
//        case NameRole:
//            return m_data[index.row()]->text();
//        case DeadLineRole:
//            return m_data[index.row()]->text();
//        case ProgressRole:
//            return m_data[index.row()]->text();
//        case Qt::DisplayRole:
//            return m_data[0]->text();
    }
    return QVariant();
}

//int TaskManagerModel::rowCount(const QModelIndex &parent) const
//{
//    if (parent.isValid()) {
//        return 0;
//    }

//    return int(m_data.size());
//}

//QVariant TaskManagerModel::data(const QModelIndex &index, int role) const
//{
//    if (!index.isValid()) {
//        return QVariant();
//    }

//    switch (role) {
//    case ColorRole:
//        return QVariant(index.row() < 2 ? "orange" : "skyblue");
//    case TextRole:
//        return m_data.at(index.row());
//    default:
//        return QVariant();
//    }
//}

//QHash<int, QByteArray> TaskManagerModel::roleNames() const
//{
//    QHash<int, QByteArray> roles = QStandardItemModel::roleNames();
//    roles[ColorRole] = "color";
//    roles[TextRole] = "text";

//    return roles;
//}

void TaskManagerModel::add(QString _name, QString _deadLine, QString _progress)
{
    m_data.append(new QStandardItem(QString(_name)));  // Первая колонка
    m_data.append(new QStandardItem(QString(_deadLine)));                  // Вторая колонка
    m_data.append(new QStandardItem(QString(_progress)));                  // Третья колонка
    this->appendRow(m_data);
    m_data.clear();



//    beginInsertRows(QModelIndex(), int(m_data.size()), int(m_data.size()));
//    m_data.append("new");
//    endInsertRows();

//    m_data[0] = QString("Size: %1").arg(m_data.size());
//    QModelIndex index = createIndex(0, 0, static_cast<void *>(nullptr));
//    emit dataChanged(index, index);
}

//bool TaskManagerModel::setData(const QModelIndex &index, const QVariant &value, int role)
//{
//    if (!index.isValid()) {
//        return false;
//    }

//    switch (role) {
//    case ColorRole:
//        return false;
//    case TextRole:
//        m_data[index.row()] = value.toString();
//        break;
//    default:
//        return false;
//    }

//    emit dataChanged(index, index, QVector<int>() << role);

//    return true;
//}

//Qt::ItemFlags TaskManagerModel::flags(const QModelIndex &index) const
//{
//    if (!index.isValid())
//        return Qt::ItemIsEnabled;

//    return QStandardItemModel::flags(index) | Qt::ItemIsEditable;
//}
