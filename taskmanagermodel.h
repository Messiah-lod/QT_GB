#ifndef TASKMANAGERMODEL_H
#define TASKMANAGERMODEL_H

#include <QStandardItemModel>
#include <QObject>
#include <QString>
#include <QVector>
#include <QVariantList>

class TaskManagerModel : public QStandardItemModel
{
    Q_OBJECT

public:
    enum Roles {
        NameRole = Qt::UserRole + 1,
        DeadLineRole,
        ProgressRole
    };

    TaskManagerModel(QObject *parent = nullptr);

//    virtual int rowCount(const QModelIndex &parent) const override;
//    virtual QVariant data(const QModelIndex &index, int role) const override;
//    virtual QHash<int, QByteArray> roleNames() const override;

//    virtual bool setData(const QModelIndex &index, const QVariant &value, int role) override;
//    virtual Qt::ItemFlags flags(const QModelIndex &index) const override;
    virtual QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    Q_INVOKABLE void add(QString _name, QString _deadLine, QString _progress);

private:
//    QStandardItem _rowData;
    QList<QStandardItem*> m_data;
    QString Name = "Ха-ха", DeadLine = "Хе-хе", Progress = "Ого";
};

#endif // TASKMANAGERMODEL_H
