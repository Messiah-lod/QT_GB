#ifndef TASKMANAGERMODEL_H
#define TASKMANAGERMODEL_H

#include <QStandardItemModel>
#include <QAbstractItemModel>
#include <QObject>
#include <QString>
#include <QVector>
#include <QVariantList>
#include <QTextCodec>

class TaskManagerModel : public QAbstractTableModel
{
    Q_OBJECT

public:
    explicit TaskManagerModel(QObject *parent = nullptr);

    Q_INVOKABLE QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    Qt::ItemFlags flags(const QModelIndex& index) const override;
    ~TaskManagerModel() override;

    Q_INVOKABLE void addObject(QString _name, QString _deadLine, QString _progress);
    Q_INVOKABLE void addObject(QByteArray _parametr);
    Q_INVOKABLE void delObject(const QModelIndex & index);
    Q_INVOKABLE void delData();

signals:


public slots:

private:
    struct rowData{
      QString nameTask = "";
      QString deadLine = "";
      QString progress = "";
    };

    QVector <rowData> *modelData;
};

#endif // TASKMANAGERMODEL_H
