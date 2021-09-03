#include "parsehtml.h"

ParseHtml::ParseHtml(QWidget *parent) : QWidget(parent)
{
    mainGrid = new QGridLayout;
    planeOne = new QPlainTextEdit;
    desc = new QLabel;
    desc->setWordWrap(true);
    desc->setText("Выполняет поиск погоды и курса валют в представленно html файле, ориентрован на mail.ru");

    weather = new QLabel;
    weather->setText("Погода");
    dollar = new QLabel;
    dollar->setText("Доллар");
    euro = new QLabel;
    euro->setText("Евро");
    openHtml = new QPushButton;
    openHtml->setText("Открыть HTML");

    mainGrid->addWidget(desc, 0 ,0 , 1 , 2);
    mainGrid->addWidget(planeOne, 1, 0, 4, 1);
    mainGrid->addWidget(weather, 1, 1);
    mainGrid->addWidget(dollar, 2, 1);
    mainGrid->addWidget(euro, 3, 1);
    mainGrid->addWidget(openHtml, 4, 1);

    this->setLayout(mainGrid);
    this->setWindowTitle("Парсер HTML");

    QObject::connect(openHtml, SIGNAL(clicked()), this, SLOT(on_openHtml_clicked()));
}

void ParseHtml::on_openHtml_clicked() {
    QString fileName;
    try	{
        fileName = QFileDialog::getOpenFileName(nullptr,
            tr("Open file"), QDir::currentPath(), tr("Data Files (*.html)"));
    }
    catch (const std::exception&){
            fileName = "";
    }

    dollar->clear();
    euro->clear();
    weather->clear();

    if (!fileName.isEmpty()){
        QFile file(fileName);
        QByteArray data; // Создаем объект класса QByteArray, куда мы будем считывать данные
        if (!file.open(QIODevice::ReadOnly)) // Проверяем, возможно ли открыть наш файл для чтения
                        return;
        data = file.readAll(); //считываем все данные с файла в объект data
        QString txtHtml(data);
        planeOne->setPlainText(txtHtml);
        QStringList list = getParametr(txtHtml);
        dollar->setText(list[0]);
        euro->setText(list[1]);
        weather->setText(list[2]);
    } else {
       planeOne->setPlainText("Ошибка!");
    }
}

QStringList ParseHtml::getParametr(QString _str){ 
    //Найлем курс доллара
    QString strSearch = "https://news.mail.ru/currency/src/MOEX/charcode/USD/\",\"type\":\"USD\",\"rate\":";
    auto index = _str.indexOf(strSearch);
    auto indexLast = _str.indexOf(",", index + strSearch.size());
    QString dol = "$ " + _str.mid(index + strSearch.size(), indexLast - index - strSearch.size());

    //Найдем курс евро
    strSearch = "https://news.mail.ru/currency/src/MOEX/charcode/EUR/\",\"type\":\"EUR\",\"rate\":";
    index = _str.indexOf(strSearch);
    indexLast = _str.indexOf(",", index + strSearch.size());
    QString eur = "E " + _str.mid(index + strSearch.size(),indexLast - index - strSearch.size());

    //Узнаем город и погоду в нем
    strSearch = "https://pogoda.mail.ru/prognoz/" ;
    index = _str.indexOf(strSearch);
    indexLast = _str.indexOf("/", index + strSearch.size());
    QString city = _str.mid(index + strSearch.size(), indexLast - index - strSearch.size());
    strSearch = "https://pogoda.mail.ru/prognoz/" + city + "/\",\"now\":{\"temp\":\"";
    index = _str.indexOf(strSearch);
    indexLast = _str.indexOf("\"", index + strSearch.size());
    QString weat = _str.mid(index + strSearch.size(), indexLast - index - strSearch.size());

    return QStringList() << dol << eur << city + ": " + weat;
}
