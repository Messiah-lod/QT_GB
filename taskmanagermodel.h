#ifndef TASKMANAGERMODEL_H
#define TASKMANAGERMODEL_H

#include <QStandardItemModel>
#include <QAbstractItemModel>
#include <QObject>
#include <QString>
#include <QVector>
#include <QVariantList>
#include <QTextCodec>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlDatabase>
#include <QSqlTableModel>
#include <QSqlError>

class TaskManagerModel : public QSqlTableModel
{
    Q_OBJECT

public:
    explicit TaskManagerModel(QObject *parent = nullptr);
    ~TaskManagerModel() override;

    Q_INVOKABLE void addObject(QString _name, QString _deadLine, QString _progress);
    Q_INVOKABLE void addObjectFromBD();
    Q_INVOKABLE void delObject(const QModelIndex & index);
    Q_INVOKABLE void delData();

signals:


public slots:

private:
    QSqlDatabase database;
};

#endif // TASKMANAGERMODEL_H
