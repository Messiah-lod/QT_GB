#include "taskmanager.h"

TaskManager::TaskManager(QObject *parent)
    : QObject{parent}
{
    if (!file.exists()) {
        file.setFileName(filename);
      }
}

QByteArray TaskManager::readFile()
{
    QByteArray block;

    if(file.open(QIODevice::ReadOnly | QIODevice::Text))  {
        block = file.readAll();

        file.close();
    }

    return block;
}

void TaskManager::writeFile(QString outputStr)
{
//    if (!file.exists()) return;
    if(file.open(QIODevice::WriteOnly | QIODevice::Append))  {
        QTextStream writeStream(&file); // Создаем объект класса QTextStream
        writeStream << outputStr << "\r\n"; // Посылаем строку в поток для записи

        file.close();
    }
}

const QString &TaskManager::getData() const
{
    return data;
}

void TaskManager::setData(const QString &newData)
{
    data = newData;
    writeFile(data);
}
