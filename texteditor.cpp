#include "texteditor.h"

TextEditor::TextEditor(QWidget *parent) : QWidget(parent)
{
    mainGrid = new QGridLayout(this);

    this->setStyleSheet(qss);

    buttonOpen = new QPushButton(this);
    buttonOpen->setIcon(QIcon(":/Icons/Icons/open.png"));
    buttonOpen->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    buttonOpen->setToolTip("Открыть");

    buttonSave = new QPushButton(this);
    buttonSave->setIcon(QIcon(":/Icons/Icons/save.png"));
    buttonSave->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    buttonSave->setToolTip("Сохранить");

    buttonHelp = new QPushButton(this);
    buttonHelp->setIcon(QIcon(":/Icons/Icons/help.png"));
    buttonHelp->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    buttonHelp->setToolTip("Справка");

    editor = new QPlainTextEdit(this);
    cbDark = new QCheckBox("Темная тема", this);

    mainGrid->addWidget(buttonOpen, 0, 0);
    mainGrid->addWidget(buttonSave, 0, 1);
    mainGrid->addWidget(buttonHelp, 0, 5);
    mainGrid->addWidget(editor, 1, 0, 1, 6);
    mainGrid->addWidget(cbDark, 2, 0, 1, 6);

    this->setLayout(mainGrid);
    this->setWindowTitle("Текстовый редактор");

    connect(buttonOpen, SIGNAL(clicked()), this, SLOT(on_buttonOpen_clicked()));
    connect(buttonSave, SIGNAL(clicked()), this, SLOT(on_buttonSave_clicked()));
    connect(buttonHelp, SIGNAL(clicked()), this, SLOT(on_buttonHelp_clicked()));
    connect(cbDark, SIGNAL(clicked()), this, SLOT(on_cbDark_clicked()));

}

void TextEditor::on_buttonOpen_clicked(){
    QString fileName;
        try	{
            fileName = QFileDialog::getOpenFileName(this,
                "Открыть файл", QDir::currentPath(), "Files (*.* ALL)");
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
                "Сохранить файл", QDir::currentPath(), "Files (*.txt)");
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
    QMessageBox::information(nullptr, "Справка", info);
}

void TextEditor::on_cbDark_clicked(){
    if (cbDark->isChecked()){
        // Создаём палитру для тёмной темы оформления
        QPalette darkPalette;

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
            // Устанавливаем данную палитру на приложение
        qApp->setPalette(darkPalette);
        this->setStyleSheet(qssDark);
    }
    else{
        // Для возврата к светлой палитре достаточно
        // будет установить стандартную палитру из темы оформления
         qApp->setPalette(style()->standardPalette());
         this->setStyleSheet(qss);
    }

}
