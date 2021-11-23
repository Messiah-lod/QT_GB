#ifndef TEXTEDITOR_H
#define TEXTEDITOR_H

#include <QtWidgets>
#include <QtGui>
#include <QPushButton>
#include <QMessageBox>
#include <QMainWindow>
#include <QPrinter>
#include <QPrintDialog>
#include <QMdiArea>

#include "settings.h"
#include "finedialog.h"

class TextEditor : public QMainWindow
{
    Q_OBJECT
public:
    explicit TextEditor(QWidget *parent = nullptr);

private:
    void closeEvent(QCloseEvent * event) override;
    void inline createButton();
    void inline createMenu();

    QWidget *centralWgt;
    QGridLayout *mainGrid; //создаем грид, который кладем на вкладку

    QToolButton *buttonOpen;
    QAction *openReadAct;

    QPushButton *buttonSave;
    QPushButton *buttonPrint;
    QPushButton *buttonHelp;
    QPushButton *buttonSettings;
    QPushButton *actionTextSelect;
    QPushButton *actionTextFormat;
    QPushButton *actionTextLeft;
    QPushButton *actionTextCentre;
    QPushButton *actionTextRight;

    Settings *setting;
    FineDialog *find;

    QMenuBar *menubar;
    QMenu *fileMenu;
    QMenu *editMenu;
    QMenu *helpMenu;
    QToolBar *fileToolBar;
    QToolBar *formatTextToolBar;
    QToolBar *aboutToolBar;
    QAction *actionFileCreate;
    QAction *actionFileOpen;
    QAction *actionFileSave;
    QAction *actionFilePrint;
    QAction *actionFileExit;
    QAction *actionEditFind;
    QAction *actionEditSetings;
    QAction *actionEditDateTime;
    QAction *actionHelpAbout;

    unsigned int modifyOpen , modifySave, modifyClear, modifyExit;
    int open, save, clear, exit;

    QTabWidget *tabArea;

    bool setOnlyReadText = false;

    QMessageBox *messExit;
    QPushButton *yes;
    QPushButton *no;
    QMessageBox *messTabClose;
    QPushButton *yesClose;
    QPushButton *noClose;

    QFont m_font;
    QTextCharFormat m_fmt;
    bool isCopyTextFormat = false;
    bool processSelected = false;

protected:
//    virtual void mousePressEvent(QMouseEvent *event) override;   // событие при нажатии кнопки мыши
 //   virtual void mouseReleaseEvent(QMouseEvent *event) override; // событие при отжатии кнопки мыши
//    virtual void mouseMoveEvent(QMouseEvent *event) override;    // событие при перемещении курсора
    virtual void keyPressEvent(QKeyEvent *event) override;       // событие при нажатии клавиши клавиатуры
//    virtual void keyReleaseEvent(QKeyEvent *event) override;     // событие при отжатии клавиши клавиатуры

signals:

public slots:
    void on_buttonOpen_clicked();
    void on_buttonSave_clicked();
    void on_buttonHelp_clicked();
    void on_buttonSettings_clicked();
    void on_buttonOpenOnlyRead_clicked();
    void on_buttonCreateNew_clicked();
    void on_buttonInsertDateTime_clicked();

    void retranslateUI();
    void redrawUI(QString _qss, QPalette _palette);

    void swtHotKeyOpen(unsigned int _modify, int _key);
    void swtHotKeySave(unsigned int _modify, int _key);
    void swtHotKeyClear(unsigned int _modify, int _key);
    void swtHotKeyExit(unsigned int _modify, int _key);
    void findText();                    // Слот вызова поиска
    void setNewPosition(int, int, int); // Слот на обработку выделения текста и установки указателя
    void on_actionFilePrint_clicked();
    void changeTabArea();
    void closeTabArea(int _tab);

    void planeTxtChange();
    void planeSelectionChange(bool select);
    void planeMoveCursor();

    void on_actionTextSelect_clicked();
    void on_actionTextFormat_clicked();
    void on_actionTextLeft_clicked();
    void on_actionTextCentre_clicked();
    void on_actionTextRight_clicked();
};

#endif // TEXTEDITOR_H
