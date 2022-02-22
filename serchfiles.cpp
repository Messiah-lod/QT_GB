#include "serchfiles.h"

SerchFiles::SerchFiles(QObject *parent) : QObject(parent)
{

}

void SerchFiles::startSerching(QString path, QString needFiles)
{
    QDirIterator it(path,  QDirIterator::Subdirectories);
    while (it.hasNext()) {
        QFile file(it.next());
        QFileInfo item(file);
        if( (item.isFile() || item.isDir() ) && item.fileName().contains(needFiles, Qt::CaseInsensitive) )
        {
            QString findFile = item.absoluteFilePath();
            emit foundFile(findFile);
        }
    }
}
