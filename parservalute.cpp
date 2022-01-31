#include "parservalute.h"
#include <QMessageBox>

ParserValute::ParserValute()
{
    str = "";
}

bool ParserValute::removeQStr(QString m_str){
    str = m_str;
    isChange = false;
    for (int i = 0; i < SIZE_COLLECTION; i++) {
        pos = int(str.indexOf(massString[i], 0));
        if(pos != -1){
            str.replace(pos,massString[i].size(),massSymbol[i]);
            isChange = true;
        }
    }
    return isChange;
}

QString ParserValute::getQStr(){
    return str;
}
