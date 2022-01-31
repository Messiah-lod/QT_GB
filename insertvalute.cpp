#include "insertvalute.h"

insertValute::insertValute(QWidget *parent) : QWidget(parent)
{
    mainGrid = new QGridLayout(this);
    planeOne = new QPlainTextEdit(this);
    parserValute = new ParserValute;
    desc = new QLabel(this);
    desc->setWordWrap(true);
    desc->setText("Заменяет текст, введенный: \n"
                  " #@CR = © — знак охраны авторского права,\n"
                  " #@PRO = ‰ — промилле,\n"
                  " #@RS = ® - знак зарегистрированной торговой марки,\n "
                  " #@EUR = € — евро,\n"
                  " #@RUB = ₽ — рубль");

    mainGrid->addWidget(desc, 0 ,0);
    mainGrid->addWidget(planeOne, 1, 0);

    this->setLayout(mainGrid);
    this->setWindowTitle("Преобразование валют");

    connect(planeOne, SIGNAL(textChanged()), this, SLOT(on_plainTextEdit_textChanged()));
}

void insertValute::on_plainTextEdit_textChanged(){
    if (parserValute->removeQStr(planeOne->toPlainText())){ //без проверки изменений уходим в бесконечный цикл
        planeOne->setPlainText(parserValute->getQStr());
        //поставим курсор в конец после замены
        QTextCursor cursor = planeOne->textCursor();
        cursor.setPosition(int(parserValute->getQStr().size()));
        planeOne->setTextCursor(cursor);
    }
}
