#include "texteditor.h"

TextEditor::TextEditor(QWidget *parent) : QMainWindow(parent)
{
    tabArea = new QTabWidget(this);
    tabArea->setMovable(true);
//    tabArea->setTabShape(QTabWidget::Triangular);
    tabArea->setTabsClosable(true);
    tabArea->setUsesScrollButtons(true);
//    tabArea->setDocumentMode(true); //????? покурить различия

    //Диалог выхода из программы
    messExit = new QMessageBox();
    yes = new QPushButton();
    messExit->addButton(yes, QMessageBox::YesRole);
    no = new QPushButton();
    messExit->addButton(no, QMessageBox::NoRole);


    messTabClose = new QMessageBox();
    yesClose = new QPushButton();
    noClose = new QPushButton();
    messTabClose->addButton(yesClose, QMessageBox::YesRole);
    messTabClose->addButton(noClose, QMessageBox::NoRole);

    mainGrid = new QGridLayout;
    centralWgt = new QWidget;
    openReadAct = new QAction(this);
    actionFileOpen = new QAction(this);

    buttonOpen = new QToolButton;
    buttonOpen->setIcon(QIcon(":/Icons/Icons/open.png"));
    buttonOpen->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    buttonOpen->setPopupMode(QToolButton::MenuButtonPopup);
    buttonOpen->addAction(actionFileOpen);
    buttonOpen->addAction(openReadAct);
    buttonOpen->setFixedSize(46, 30);

    buttonSave = new QPushButton;
    buttonSave->setIcon(QIcon(":/Icons/Icons/save.png"));
    buttonSave->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);

    buttonPrint = new QPushButton;
    buttonPrint->setIcon(QIcon(":/Icons/Icons/print.png"));
    buttonPrint->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);

    buttonHelp = new QPushButton;
    buttonHelp->setIcon(QIcon(":/Icons/Icons/help.png"));
    buttonHelp->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);

    buttonSettings = new QPushButton;
    buttonSettings->setIcon(QIcon(":/Icons/Icons/setings.png"));
    buttonSettings->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);

    mainGrid->addWidget(buttonOpen, 0, 0);
    mainGrid->addWidget(buttonSave, 0, 1);
    mainGrid->addWidget(buttonPrint, 0, 2);
    mainGrid->addWidget(buttonSettings, 0, 4);
    mainGrid->addWidget(buttonHelp, 0, 5);
    mainGrid->addWidget(tabArea, 1, 0, 1, 6);

    setting = new Settings(this);
    setting->setWindowFlags(Qt::Window | Qt::MSWindowsFixedSizeDialogHint);
    find = new FineDialog(this);
    find->setWindowFlags(Qt::Window | Qt::MSWindowsFixedSizeDialogHint);

    modifyOpen = setting->getHotkey()[0];
    open = static_cast<int>(setting->getHotkey()[1]);
    modifySave = setting->getHotkey()[2];
    save = static_cast<int>(setting->getHotkey()[3]);
    modifyClear = setting->getHotkey()[4];
    clear = static_cast<int>(setting->getHotkey()[5]);
    modifyExit = setting->getHotkey()[6];
    exit = static_cast<int>(setting->getHotkey()[7]);

    centralWgt->setLayout(mainGrid);
    this->setCentralWidget(centralWgt);


//Создадим меню основного окна *********
    menubar = new QMenuBar(this);

    fileMenu = new QMenu(menubar);
    editMenu = new QMenu(menubar);
    helpMenu = new QMenu(menubar);

    actionFileCreate = new QAction(this);
    actionFileCreate->setIcon(QIcon(":/Icons/Icons/main.png"));

    actionFileOpen->setIcon(QIcon(":/Icons/Icons/open.png"));
    actionFileSave = new QAction(this);
    actionFileSave->setIcon(QIcon(":/Icons/Icons/save.png"));
    actionFilePrint = new QAction(this);
    actionFilePrint->setIcon(QIcon(":/Icons/Icons/print.png"));
    actionFileExit = new QAction(this);
    actionFileExit->setIcon(QIcon(":/Icons/Icons/cancel.png"));
    actionEditSetings = new QAction(this);
    actionEditSetings->setIcon(QIcon(":/Icons/Icons/setings.png"));
    actionEditFind = new QAction(this);
    actionEditFind->setIcon(QIcon(":/Icons/Icons/find.png"));
    actionHelpAbout = new QAction(this);
    actionHelpAbout->setIcon(QIcon(":/Icons/Icons/help.png"));

    menubar->addAction(fileMenu->menuAction());
    menubar->addAction(editMenu->menuAction());
    menubar->addAction(helpMenu->menuAction());

    fileMenu->addAction(actionFileCreate);
    fileMenu->addAction(actionFileOpen);
    fileMenu->addAction(actionFileSave);
    fileMenu->addAction(actionFilePrint);
    fileMenu->addSeparator();
    fileMenu->addAction(actionFileExit);
    editMenu->addAction(actionEditSetings);
    editMenu->addAction(actionEditFind);
    helpMenu->addAction(actionHelpAbout);

    this->setMenuBar(menubar);
//***************


    QObject::connect(buttonOpen, SIGNAL(clicked()), this, SLOT(on_buttonOpen_clicked()));
    QObject::connect(buttonSave, SIGNAL(clicked()), this, SLOT(on_buttonSave_clicked()));
    QObject::connect(buttonPrint, SIGNAL(clicked()), this, SLOT(on_actionFilePrint_clicked()));
    QObject::connect(buttonHelp, SIGNAL(clicked()), this, SLOT(on_buttonHelp_clicked()));
    QObject::connect(openReadAct, SIGNAL(triggered()), this, SLOT(on_buttonOpenOnlyRead_clicked()));
    QObject::connect(buttonSettings, SIGNAL(clicked()), this, SLOT(on_buttonSettings_clicked()));
    QObject::connect(setting, SIGNAL(retranslate()), this, SLOT(retranslateUI()));
    QObject::connect(setting, SIGNAL(redraw(QString, QPalette)), this, SLOT(redrawUI(QString, QPalette)));
    QObject::connect(setting, SIGNAL(signal_changeOpen(unsigned int, int)), this, SLOT(swtHotKeyOpen(unsigned int, int)));
    QObject::connect(setting, SIGNAL(signal_changeSave(unsigned int, int)), this, SLOT(swtHotKeySave(unsigned int, int)));
    QObject::connect(setting, SIGNAL(signal_changeClear(unsigned int, int)), this, SLOT(swtHotKeyClear(unsigned int, int)));
    QObject::connect(setting, SIGNAL(signal_changeExit(unsigned int, int)), this, SLOT(swtHotKeyExit(unsigned int, int)));

    QObject::connect(actionFileCreate, SIGNAL(triggered(bool)), this, SLOT(on_buttonCreateNew_clicked()));
    QObject::connect(actionFileOpen, SIGNAL(triggered(bool)), this, SLOT(on_buttonOpen_clicked()));
    QObject::connect(actionFileSave, SIGNAL(triggered(bool)), this, SLOT(on_buttonSave_clicked()));
    QObject::connect(actionFilePrint, SIGNAL(triggered(bool)), this, SLOT(on_actionFilePrint_clicked()));
    QObject::connect(actionFileExit, SIGNAL(triggered(bool)), this, SLOT(close()));
    QObject::connect(actionEditSetings, SIGNAL(triggered(bool)), this, SLOT(on_buttonSettings_clicked()));
    QObject::connect(actionEditFind, SIGNAL(triggered(bool)), this, SLOT(findText()));
    QObject::connect(actionHelpAbout, SIGNAL(triggered(bool)), this, SLOT(on_buttonHelp_clicked()));

    QObject::connect(tabArea, SIGNAL(currentChanged(int)), this, SLOT(changeTabArea())); //активна новая вкладка
    QObject::connect(tabArea, SIGNAL(tabCloseRequested(int)), this, SLOT(closeTabArea(int)));//нажата кнопка закрытия вкладки

    retranslateUI();
    redrawUI(setting->getQss(), setting->getPalette());
}

void TextEditor::closeEvent(QCloseEvent *event)
{
        event->ignore();

        messExit->setIcon(QMessageBox::Information);
        messExit->exec();

        if (messExit->clickedButton() == yes) {
            while(tabArea->count() != 0){
                closeTabArea(tabArea->currentIndex());
            }
            event->accept();
        }
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
        on_buttonCreateNew_clicked();
    }
    else if ( ((event->modifiers() == modifyExit) && event->key() == exit) ||
                (modifyExit == 0 && event->key() == exit)){
        qApp->exit();
    }
}

void TextEditor::on_buttonOpen_clicked(){
    QPlainTextEdit *textEdit = new QPlainTextEdit;
    textEdit->setReadOnly(setOnlyReadText);
    textEdit->setPlainText("");
    QObject::connect(textEdit, SIGNAL(textChanged()), this, SLOT(planeTxtChange()));

    //проверка, были ли изменения на старой вкладке, чтобы не ставилась лишняя '*'
    bool isCahngeCurrentTab = false;
    int currentTab = tabArea->currentIndex();
    if(tabArea->tabText(currentTab)[0] == '*') isCahngeCurrentTab = true;

    QString fileName;
        try	{
            fileName = QFileDialog::getOpenFileName(this,
                tr("Open file"), QDir::currentPath(), "Files (*.* ALL)");
        }
        catch (const std::exception&){
                fileName = "";
        }

        if (!fileName.isEmpty()){
            QFile file(fileName);
            QByteArray data; // Создаем объект класса QByteArray, куда мы будем считывать данные
            if (!file.open(QIODevice::ReadOnly)) // Проверяем, возможно ли открыть наш файл для чтения
                            return;
            data = file.readAll(); //считываем все данные с файла в объект data
            textEdit->setPlainText(data);
            QFileInfo fileInfo(fileName);
            int newTab = tabArea->addTab(textEdit, fileInfo.fileName());
            tabArea->setTabToolTip(newTab, fileName);
            tabArea->setCurrentIndex(newTab);
        }
        setOnlyReadText = false;

        if(!isCahngeCurrentTab) //выполним затирание лишнего символа, если не было изменений
            tabArea->setTabText(currentTab, tabArea->tabText(currentTab).remove(0,1));
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
            if (!file.open(QFile::WriteOnly)) return; // Проверяем, возможно ли открыть наш файл для записи
            QTextStream stream(&file);

            QWidget *widg = tabArea->currentWidget();
            if(widg) {
                QPlainTextEdit *textEditor = static_cast<QPlainTextEdit*>(widg);
                stream << textEditor->toPlainText();
                QFileInfo fileInfo(fileName);
                tabArea->setTabToolTip(tabArea->currentIndex(), fileName);
                tabArea->setTabText(tabArea->currentIndex(), fileInfo.fileName());
            }
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
    setOnlyReadText = true;
    on_buttonOpen_clicked();
}

void TextEditor::on_buttonCreateNew_clicked()
{
    QPlainTextEdit *textEdit = new QPlainTextEdit;
    textEdit->setReadOnly(setOnlyReadText);
    textEdit->setPlainText("");
    textEdit->setToolTip("");
    int newTab = tabArea->addTab(textEdit, "*unknown");
    tabArea->setCurrentIndex(newTab);
    QObject::connect(textEdit, SIGNAL(textChanged()), this, SLOT(planeTxtChange()));
}

void TextEditor::retranslateUI()
{
    this->setWindowTitle(tr("Text editor"));
    openReadAct->setText(tr("Open Read only"));
    buttonOpen->setToolTip(tr("Open"));
    buttonSave->setToolTip(tr("Save"));
    buttonHelp->setToolTip(tr("Help"));
    buttonSettings->setToolTip(tr("Settings"));
    buttonPrint->setToolTip(tr("Print"));

    fileMenu->setTitle(tr("File"));
    editMenu->setTitle(tr("Edit"));
    helpMenu->setTitle(tr("Help"));

    actionFileCreate->setText(tr("Create"));
    actionFileOpen->setText(tr("Open"));
    actionFileSave->setText(tr("Save"));
    actionFilePrint->setText(tr("Print"));
    actionFileExit->setText(tr("Exit"));
    actionEditSetings->setText(tr("Setings"));
    actionEditFind->setText(tr("Find..."));
    actionHelpAbout->setText(tr("About"));

    messExit->setWindowTitle(tr("Exit"));
    messExit->setText(tr("To exit the programm?"));
    messTabClose->setWindowTitle(tr("Close tab"));
    messTabClose->setText(tr("Save changes?"));
    yes->setText(tr("Yes"));
    no->setText(tr("No"));
    yesClose->setText(tr("Yes"));
    noClose->setText(tr("No"));

    setting->retranslateUI();
    find->retranslateUI();
}

void TextEditor::redrawUI(QString _qss, QPalette _palette)
{
    this->setPalette(_palette);
    buttonOpen->setStyleSheet(_qss);
    buttonSave->setStyleSheet(_qss);
    buttonPrint->setStyleSheet(_qss);
    buttonHelp->setStyleSheet(_qss);
    buttonSettings->setStyleSheet(_qss);

    centralWgt->setStyleSheet(_qss);

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

void TextEditor::findText()
{
    QWidget *widg = tabArea->currentWidget();
    QPlainTextEdit *textEditor = static_cast<QPlainTextEdit*>(widg);
    find->setTextEdit(textEditor); //передадим весь текст в поиск
    QObject::connect(find, SIGNAL(setCursorPos(int, int, int)), this, SLOT(setNewPosition(int, int, int)));   // Соединяем сигнал  от диалогового окна к слоту
    find->show();              // Запускаем диалог без блокировки главного окна
}

void TextEditor::setNewPosition(int start, int lenght, int npos)
{                                                          // Если поиск прошел удачно, получаем координаты выделения текста
  QWidget *widg = tabArea->currentWidget();
  QPlainTextEdit *textEditor = static_cast<QPlainTextEdit*>(widg);
  QTextCursor tcursor = textEditor->textCursor();            // Копируем объект QTextCursor
  if (npos > start) {                                      // Если нужно сместить курсор вперед
      tcursor.setPosition(start, QTextCursor::MoveAnchor); // Устанавливаем курсор в начало искомой строки по индексу
      tcursor.setPosition(npos, QTextCursor::KeepAnchor);  // Выделяем текст до новой позиции, которая равна сумме  позиции начала искомой строки  и ее длины
  }
  else {                                                   // Если нужно сместить вперед
      tcursor.setPosition(start + lenght, QTextCursor::MoveAnchor);  // Берем позицию окончания искомой строки
      tcursor.setPosition(start, QTextCursor::KeepAnchor); // Переносим выделение на начало искомой строки
  }
  textEditor->setTextCursor(tcursor);                        // Устанавливаем новые настройки курсора QTextEdit
}

void TextEditor::on_actionFilePrint_clicked()
{
   QPrinter printer;
   QPrintDialog dlg(&printer, this);
   dlg.setWindowTitle("Print");
   if (dlg.exec() != QDialog::Accepted)
       return;
   QWidget *widg = tabArea->currentWidget();
   QPlainTextEdit *textEditor = static_cast<QPlainTextEdit*>(widg);
   textEditor->print(&printer);
}

void TextEditor::changeTabArea()
{
    QWidget *widg = tabArea->currentWidget();
    if(widg) {
        QPlainTextEdit *textEditor = static_cast<QPlainTextEdit*>(widg);
        find->setTextEdit(textEditor);
    }
//    QMessageBox::information(this, "rfrf", "rfrf");
}

void TextEditor::closeTabArea(int _tab)
{
    if(tabArea->tabText(_tab)[0] == '*') {
        messTabClose->setIcon(QMessageBox::Information);
        messTabClose->exec();
        if (messTabClose->clickedButton() == yesClose){
//            QMessageBox::information(this, "rfrf", "rfrf");
            on_buttonSave_clicked(); //если был текст изменне - предложим сохранить
        }
    }
    tabArea->removeTab(_tab);
}

void TextEditor::planeTxtChange()
{
    if(tabArea->tabText(tabArea->currentIndex())[0] != '*')
        tabArea->setTabText(tabArea->currentIndex(), tabArea->tabText(tabArea->currentIndex()).insert(0, '*'));
}
