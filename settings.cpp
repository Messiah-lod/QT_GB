#include "settings.h"

Settings::Settings(QWidget *parent) : QWidget(parent)
{
    mainGrid = new QGridLayout;

    cbDark = new QCheckBox;
    cbLanguage = new QCheckBox;

    qss =   "QWidget{""background-color: rgb(239, 239, 239);""}"
                           "QPlainTextEdit{""background-color: rgb(255, 255, 255);""border-color: rgb(0, 179, 255);""border: 5px solid rgb(0, 179, 255);""}"
                           "QPushButton{""border-radius: 00px;""background-color: rgb(239, 239, 239);""qproperty-iconSize: 28px 28px;""}"
                           "QPushButton:pressed{"" border-radius: 10px;""background-color: rgb(0, 179, 255);""}"
                           "QToolButton{""border-radius: 00px;""background-color: rgb(239, 239, 239);""qproperty-iconSize: 28px 28px;""}"
                           "QToolButton:pressed{"" border-radius: 10px;""background-color: rgb(0, 179, 255);""}";


    qssDark = "QWidget{""background-color: rgb(53, 53, 53);""text-color: rgb(255, 255, 255);""}"
                              "QPlainTextEdit{""background-color: rgb(25, 25, 25);""border-color: rgb(0, 179, 255);"
                                  "             ""border: 5px solid rgb(0, 179, 255);""text-color: rgb(255, 255, 255);""}"
                              "QPushButton{""border-radius: 00px;""background-color: rgb(53, 53, 53);""qproperty-iconSize: 28px 28px;""}"
                              "QPushButton:pressed{"" border-radius: 10px;""background-color: rgb(0, 179, 255);""}"
                              "QToolButton{""border-radius: 00px;""background-color: rgb(53, 53, 53);""qproperty-iconSize: 28px 28px;""}"
                              "QToolButton:pressed{"" border-radius: 10px;""background-color: rgb(0, 179, 255);""}";




    // Настраиваем палитру для цветовых ролей элементов интерфейса
    darkPalette.setColor(QPalette::Window, QColor(53, 53, 53));
    darkPalette.setColor(QPalette::WindowText, Qt::white);
    darkPalette.setColor(QPalette::Base, QColor(25, 25, 25));
    darkPalette.setColor(QPalette::AlternateBase, QColor(53, 53, 53));
    darkPalette.setColor(QPalette::ToolTipBase, Qt::white);
    darkPalette.setColor(QPalette::ToolTipText, Qt::white);
    darkPalette.setColor(QPalette::Text, Qt::white);
    darkPalette.setColor(QPalette::Button, QColor(53, 53, 53));
    darkPalette.setColor(QPalette::ButtonText, Qt::white);
    darkPalette.setColor(QPalette::BrightText, Qt::red);
    darkPalette.setColor(QPalette::Link, QColor(42, 130, 218));
    darkPalette.setColor(QPalette::Highlight, QColor(42, 130, 218));
    darkPalette.setColor(QPalette::HighlightedText, Qt::black);

    QObject::connect(cbDark, SIGNAL(clicked()), this, SLOT(on_cbDark_clicked()));
    QObject::connect(cbLanguage, SIGNAL(clicked()), this, SLOT(on_cbLanguage_clicked()));

    mainGrid->addWidget(cbDark, 0, 0);
    mainGrid->addWidget(cbLanguage, 1, 0);

    qApp->setPalette(style()->standardPalette());
    qApp->setStyleSheet(qss);

    this->setLayout(mainGrid);

    retranslateUI();

}

void Settings::on_cbDark_clicked()
{
    if (cbDark->isChecked()){
        // Устанавливаем данную палитру на приложение
        qApp->setPalette(darkPalette);
        qApp->setStyleSheet(qssDark);
    }
    else{
        // Для возврата к светлой палитре достаточно
        // будет установить стандартную палитру из темы оформления
         qApp->setPalette(style()->standardPalette());
         qApp->setStyleSheet(qss);
    }
}

void Settings::on_cbLanguage_clicked()
{
    if (cbLanguage->isChecked()){//русский
        translator = new QTranslator;
        translator->load(":/translator/RU_tu.qm");
        qApp->installTranslator(translator);
        emit retranslate();
    }
    else{//английский
        delete translator;
        emit retranslate();
    }
}

void Settings::retranslateUI()
{
    cbDark->setText(tr("Dark theme"));
    cbLanguage->setText(tr("Set Russian Language"));
    this->setWindowTitle(tr("Settings"));
}


