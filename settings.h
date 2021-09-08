#ifndef SETTINGS_H
#define SETTINGS_H

#include <QtWidgets>
#include <QtGui>
#include <QPushButton>
#include <QMessageBox>
#include <QDebug>

class Settings : public QWidget
{
    Q_OBJECT
public:
    explicit Settings(QWidget *parent = nullptr);
    QString getQss();
    QVector<unsigned int> getHotkey();

private:
        QGridLayout *mainGrid; //создаем грид, который кладем на вкладку

        QCheckBox *cbDark;
        QCheckBox *cbLanguage;
        QLabel *lbDark;
        QLabel *lbLanguage;

        // Создаём палитру для тёмной темы оформления
        QPalette darkPalette;
        QPalette palette;

        QString qss;
        QString qssDark;

        QTranslator *translator;

        QLabel *lbOpen;
        QLineEdit *leOpen;
        QLabel *lbSave;
        QLineEdit *leSave;
        QLabel *lbClear;
        QLineEdit *leClear;
        QLabel *lbExit;
        QLineEdit *leExit;

        int key, open, save, clear, exit;
        unsigned int modify, modifyOpen, modifySave, modifyClear, modifyExit;
        bool changeOpen, changeSave, changeClear, changeExit;

        QString getNameKey(int _key);

protected:
        virtual void keyPressEvent(QKeyEvent *event) override;
 //       virtual void mousePressEvent(QMouseEvent *event) override;   // событие при нажатии кнопки мыши

signals:
        void retranslate();
        void redraw(QString, QPalette);
        void signal_changeOpen(unsigned int,int);
        void signal_changeSave(unsigned int,int);
        void signal_changeClear(unsigned int,int);
        void signal_changeExit(unsigned int,int);

public slots:
        void on_cbDark_clicked();
        void on_cbLanguage_clicked();
        void retranslateUI();
        void redrawUI(QString _qss, QPalette _palette);
        void leOpen_onTextEdit();
        void leSave_onTextEdit();
        void leClear_onTextEdit();
        void leExit_onTextEdit();
};

#endif // SETTINGS_H
