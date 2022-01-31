#ifndef PARSERVALUTE_H
#define PARSERVALUTE_H

#include <QString>

class ParserValute
{
public:
    ParserValute();
    bool removeQStr(QString m_str); //принимает строку в работу
    QString getQStr();
private:
    QString str;
    bool isChange;
    int pos;
    //коллекция для замещения
    static const int SIZE_COLLECTION = 5;
    QString massString[SIZE_COLLECTION] = {"#@CR", "#@PRO", "#@RS", "#@EUR", "#@RUB"};
    QString massSymbol[SIZE_COLLECTION] = {"©", "‰", "®", "€", "₽"};
};

#endif // PARSERVALUTE_H
