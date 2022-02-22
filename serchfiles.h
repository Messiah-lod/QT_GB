#ifndef SERCHFILES_H
#define SERCHFILES_H

#include <QObject>
#include <QFileInfo>
#include <QDir>
#include <QDirIterator>
#include <QThread>

class SerchFiles : public QObject

{
    Q_OBJECT
public:
    explicit SerchFiles(QObject *parent = nullptr);
    void startSerching(QString path, QString needFiles);

signals:
    void foundFile(QString);

};

#endif // SERCHFILES_H
