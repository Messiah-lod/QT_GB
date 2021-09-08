#include "texteditor.h"

TextEditor::TextEditor(QWidget *parent) : QWidget(parent)
{
    mainGrid = new QGridLayout;
    openAct = new QAction;
    openReadAct = new QAction;

    buttonOpen = new QToolButton;
    buttonOpen->setIcon(QIcon(":/Icons/Icons/open.png"));
    buttonOpen->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    buttonOpen->setPopupMode(QToolButton::MenuButtonPopup);
    buttonOpen->addAction(openAct);
    buttonOpen->addAction(openReadAct);
    buttonOpen->setFixedSize(46, 30);

    buttonSave = new QPushButton;
    buttonSave->setIcon(QIcon(":/Icons/Icons/save.png"));
    buttonSave->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);

    buttonHelp = new QPushButton;
    buttonHelp->setIcon(QIcon(":/Icons/Icons/help.png"));
    buttonHelp->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);

    buttonSettings = new QPushButton;
    buttonSettings->setIcon(QIcon(":/Icons/Icons/setings.png"));
    buttonSettings->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);

    editor = new QPlainTextEdit;
 //   keyCombination = new QKeyCombination;

    mainGrid->addWidget(buttonOpen, 0, 0);
    mainGrid->addWidget(buttonSave, 0, 1);
    mainGrid->addWidget(buttonSettings, 0, 4);
    mainGrid->addWidget(buttonHelp, 0, 5);
    mainGrid->addWidget(editor, 1, 0, 1, 6);

    setting = new Settings(this);
    setting->setWindowFlags(Qt::Window | Qt::MSWindowsFixedSizeDialogHint);

    modifyOpen = setting->getHotkey()[0];
    open = static_cast<int>(setting->getHotkey()[1]);
    modifySave = setting->getHotkey()[2];
    save = static_cast<int>(setting->getHotkey()[3]);
    modifyClear = setting->getHotkey()[4];
    clear = static_cast<int>(setting->getHotkey()[5]);
    modifyExit = setting->getHotkey()[6];
    exit = static_cast<int>(setting->getHotkey()[7]);

    this->setLayout(mainGrid);

    QObject::connect(buttonOpen, SIGNAL(clicked()), this, SLOT(on_buttonOpen_clicked()));
    QObject::connect(buttonSave, SIGNAL(clicked()), this, SLOT(on_buttonSave_clicked()));
    QObject::connect(buttonHelp, SIGNAL(clicked()), this, SLOT(on_buttonHelp_clicked()));
    QObject::connect(openAct, SIGNAL(triggered()), this, SLOT(on_buttonOpen_clicked()));
    QObject::connect(openReadAct, SIGNAL(triggered()), this, SLOT(on_buttonOpenOnlyRead_clicked()));
    QObject::connect(buttonSettings, SIGNAL(clicked()), this, SLOT(on_buttonSettings_clicked()));
    QObject::connect(setting, SIGNAL(retranslate()), this, SLOT(retranslateUI()));
    QObject::connect(setting, SIGNAL(redraw(QString, QPalette)), this, SLOT(redrawUI(QString, QPalette)));
    QObject::connect(setting, SIGNAL(signal_changeOpen(unsigned int, int)), this, SLOT(swtHotKeyOpen(unsigned int, int)));
    QObject::connect(setting, SIGNAL(signal_changeSave(unsigned int, int)), this, SLOT(swtHotKeySave(unsigned int, int)));
    QObject::connect(setting, SIGNAL(signal_changeClear(unsigned int, int)), this, SLOT(swtHotKeyClear(unsigned int, int)));
    QObject::connect(setting, SIGNAL(signal_changeExit(unsigned int, int)), this, SLOT(swtHotKeyExit(unsigned int, int)));

    this->setStyleSheet(setting->getQss());

    retranslateUI();
}

void TextEditor::keyPressEvent(QKeyEvent *event)
{
    if( (event->modifiers() == modifyOpen && event->key() == open) ||
            (modifyOpen == 0 && event->key() == open)){
        on_buttonOpen_clicked();
    }
    else if ( ((event->modifiers() ==  modifySave) && event->key() == save) ||
               (modifySave == 0 && event->key() == save)){
        on_buttonSave_clicked();
    }
    else if ( ((event->modifiers() ==  modifyClear) && event->key() == clear) ||
                (modifyClear == 0 && event->key() == clear)){
        editor->clear();
    }
    else if ( ((event->modifiers() == modifyExit) && event->key() == exit) ||
                (modifyExit == 0 && event->key() == exit)){
        qApp->exit();
    }
}

void TextEditor::on_buttonOpen_clicked(){
    editor->setReadOnly(false);
    QString fileName;
        try	{
            fileName = QFileDialog::getOpenFileName(this,
                tr("Open file"), QDir::currentPath(), "Files (*.* ALL)");
        }
        catch (const std::exception&){
                fileName = "";
        }

        if (!fileName.isEmpty()){
            editor->clear();
            QFile file(fileName);
            QByteArray data; // Создаем объект класса QByteArray, куда мы будем считывать данные
            if (!file.open(QIODevice::ReadOnly)) // Проверяем, возможно ли открыть наш файл для чтения
                            return;
            data = file.readAll(); //считываем все данные с файла в объект data
            QString txt(data);
            editor->setPlainText(txt);
        }
}

void TextEditor::on_buttonSave_clicked(){
    QString fileName;
        try	{
            fileName = QFileDialog::getSaveFileName(this,
                tr("Save file"), QDir::currentPath(), "Files (*.txt)");
        }
        catch (const std::exception&){
                fileName = "";
        }

        if (!fileName.isEmpty()){
            QFile file(fileName);
            if (!file.open(QFile::WriteOnly | QFile::NewOnly)) // Проверяем, возможно ли открыть наш файл для записи
                            return;
            QTextStream stream(&file);
            stream << editor->toPlainText();
            file.close();
        }
}

void TextEditor::on_buttonHelp_clicked(){
    QFile file(":/Txt/readme.txt");
    file.open(QIODevice::ReadOnly);
    QString info = file.readAll();

    QMessageBox::information(nullptr, tr("Help"),info);
}

void TextEditor::on_buttonSettings_clicked()
{
    setting->show();
}

void TextEditor::on_buttonOpenOnlyRead_clicked()
{
    on_buttonOpen_clicked();
    editor->setReadOnly(true);
}

void TextEditor::retranslateUI()
{
    this->setWindowTitle(tr("Text editor"));
    openAct->setText(tr("Open"));
    openReadAct->setText(tr("Open Read only"));
    buttonOpen->setToolTip(tr("Open"));
    buttonSave->setToolTip(tr("Save"));
    buttonHelp->setToolTip(tr("Help"));
    buttonSettings->setToolTip(tr("Settings"));

    setting->retranslateUI();
}

void TextEditor::redrawUI(QString _qss, QPalette _palette)
{
    this->setPalette(_palette);
    this->setStyleSheet(_qss);
    setting->redrawUI(_qss, _palette);
}

void TextEditor::swtHotKeyOpen(unsigned int _modify, int _key)
{
    open = _key; modifyOpen = _modify;
}

void TextEditor::swtHotKeySave(unsigned int _modify, int _key)
{
    save = _key; modifySave = _modify;
}

void TextEditor::swtHotKeyClear(unsigned int _modify, int _key)
{
    clear = _key; modifyClear = _modify;
}

void TextEditor::swtHotKeyExit(unsigned int _modify, int _key)
{
    exit = _key; modifyExit = _modify;
}
