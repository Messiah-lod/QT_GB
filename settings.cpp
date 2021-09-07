#include "settings.h"

Settings::Settings(QWidget *parent) : QWidget(parent)
{
    mainGrid = new QGridLayout;

    cbDark = new QCheckBox;
    cbLanguage = new QCheckBox;
    lbDark = new QLabel;
    lbLanguage = new QLabel;

    lbOpen = new QLabel;
    leOpen = new QLineEdit;
    lbSave = new QLabel;
    leSave = new QLineEdit;
    lbClear = new QLabel;
    leClear = new QLineEdit;
    lbExit = new QLabel;
    leExit = new QLineEdit;

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

    palette = style()->standardPalette();

    leOpen->setText("Ctrl+O");
    leOpen->setReadOnly(true);
    leSave->setText("Ctrl+S");
    leSave->setReadOnly(true);
    leClear->setText("Ctrl+N");
    leClear->setReadOnly(true);
    leExit->setText("Ctrl+Q");
    leExit->setReadOnly(true);

    QObject::connect(cbDark, SIGNAL(clicked()), this, SLOT(on_cbDark_clicked()));
    QObject::connect(cbLanguage, SIGNAL(clicked()), this, SLOT(on_cbLanguage_clicked()));
    QObject::connect(leOpen,SIGNAL(selectionChanged()),this,SLOT(leOpen_onTextEdit()));
    QObject::connect(leSave,SIGNAL(selectionChanged()),this,SLOT(leSave_onTextEdit()));
    QObject::connect(leClear,SIGNAL(selectionChanged()),this,SLOT(leClear_onTextEdit()));
    QObject::connect(leExit,SIGNAL(selectionChanged()),this,SLOT(leExit_onTextEdit()));

    mainGrid->addWidget(cbDark, 0, 1);
    mainGrid->addWidget(cbLanguage, 1, 1);
    mainGrid->addWidget(lbDark, 0, 0);
    mainGrid->addWidget(lbLanguage, 1, 0);
    mainGrid->addWidget(lbOpen, 2, 0);
    mainGrid->addWidget(leOpen, 2, 1);
    mainGrid->addWidget(lbSave, 3, 0);
    mainGrid->addWidget(leSave, 3, 1);
    mainGrid->addWidget(lbClear, 4, 0);
    mainGrid->addWidget(leClear, 4, 1);
    mainGrid->addWidget(lbExit, 5, 0);
    mainGrid->addWidget(leExit, 5, 1);

    qApp->setPalette(palette);
    this->setStyleSheet(getQss());

    this->setLayout(mainGrid);

    open = Qt::Key_O;
    modifyOpen = Qt::ControlModifier;
    save = Qt::Key_S;
    modifySave = Qt::ControlModifier;
    clear = Qt::Key_N;
    modifyClear = Qt::ControlModifier;
    exit = Qt::Key_Q;
    modifyExit = Qt::ControlModifier;

    retranslateUI();
    redrawUI(qss, palette);
}

QString Settings::getQss()
{
    if (cbDark->isChecked()) return qssDark;
    else return qss;
}

QVector<int> Settings::getHotkey()
{
    QVector<int> hotkeys;
    hotkeys.append(modifyOpen);
    hotkeys.append(open);
    hotkeys.append(modifySave);
    hotkeys.append(save);
    hotkeys.append(modifyClear);
    hotkeys.append(clear);
    hotkeys.append(exit);
    hotkeys.append(modifyExit);
    return hotkeys;
}

void Settings::keyPressEvent(QKeyEvent *event)
{
    modify = event->modifiers();
    key = event->key();
    if(changeOpen){ 
        if(modify!= 0 && modifyOpen == 0) {
            leOpen->setText(QString::number(modify)+ "+");
            modifyOpen = modify;
        }
        else {
            leOpen->setText((modifyOpen!= 0)?(leOpen->text() + QString::number(key)):(QString::number(key)));
            open = key;
            changeOpen = false;
        }
        emit signal_changeOpen(modifyOpen,open);
    } else if(changeSave){
        if(modify!= 0 && modifySave == 0) {
            modifySave = modify;
            leSave->setText(QString::number(modifySave)+ "+");
        }
        else {
            save = key;
            leSave->setText((modifySave!= 0)?(leSave->text() + QString::number(save)):(QString::number(save)));
            changeSave = false;
        }
        emit signal_changeSave(modifySave,save);
    } else if(changeClear){
        if(modify!= 0 && modifyClear == 0) {
            modifyClear = modify;
            leClear->setText(QString::number(modifyClear)+ "+");
        }
        else {
             clear = key;
            leClear->setText((modifyClear!= 0)?(leClear->text() + QString::number(clear)):(QString::number(clear)));
            changeClear = false;
        }
        emit signal_changeSave(modifyClear,clear);
    } else if(changeExit){
        if(modify!= 0 && modifyExit == 0) {
            modifyExit = modify;
            leExit->setText(QString::number(modifyExit)+ "+");
        }
        else {
            exit = key;
            leExit->setText((modifyExit!= 0)?(leExit->text() + QString::number(exit)):(QString::number(exit)));
            changeExit = false;
        }
        emit signal_changeSave(modifyExit,exit);
    }
}

void Settings::on_cbDark_clicked()
{
    if (cbDark->isChecked()){
        // Устанавливаем данную палитру на приложение
        qApp->setPalette(darkPalette);
        emit redraw(qssDark, darkPalette);
    }
    else{
        // Для возврата к светлой палитре достаточно
        // будет установить стандартную палитру из темы оформления
         qApp->setPalette(style()->standardPalette());
         emit redraw(qss, palette);
    }
}

void Settings::on_cbLanguage_clicked() {
    if (cbLanguage->isChecked()){//русский
        translator = new QTranslator;
        static_cast<void>(translator->load(":/translator/RU_tu.qm"));
        qApp->installTranslator(translator);
        emit retranslate();
    }
    else{//английский
        delete translator;
        emit retranslate();
    }
}

void Settings::retranslateUI() {
    lbDark->setText(tr("Dark theme"));
    lbLanguage->setText(tr("Set Russian Language"));
    this->setWindowTitle(tr("Settings"));

    lbOpen->setText(tr("Hot Key \"Open\""));
    lbSave->setText(tr("Hot Key \"Save\""));
    lbClear->setText(tr("Hot Key \"Clear Text Editor\""));
    lbExit->setText(tr("Hot Key \"Exit\""));
}

void Settings::redrawUI(QString _qss, QPalette _palette) {
    this->setStyleSheet(_qss);
    this->setPalette(_palette);
}

void Settings::leOpen_onTextEdit()
{
    modifyOpen = open = 0;
    changeOpen = true;
}

void Settings::leSave_onTextEdit()
{
    modifySave = save = 0;
    changeSave = true;
}

void Settings::leClear_onTextEdit()
{
    modifyClear = clear = 0;
    changeClear = true;
}

void Settings::leExit_onTextEdit()
{
    modifyExit = exit = 0;
    changeExit = true;
}


