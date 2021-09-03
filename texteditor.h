#ifndef TEXTEDITOR_H
#define TEXTEDITOR_H

#include <QtWidgets>
#include <QtGui>
#include <QPushButton>
#include <QMessageBox>

#include "settings.h"

class TextEditor : public QWidget
{
    Q_OBJECT
public:
    explicit TextEditor(QWidget *parent = nullptr);

private:
    QGridLayout *mainGrid; //создаем грид, который кладем на вкладку

    QToolButton *buttonOpen;
    QAction *openAct;
    QAction *openReadAct;

    QPushButton *buttonSave;
    QPushButton *buttonHelp;
    QPushButton *buttonSettings;

    QPlainTextEdit *editor;

    Settings *setting;

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
    void retranslateUI();
};

#endif // TEXTEDITOR_H
