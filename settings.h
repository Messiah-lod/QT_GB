#ifndef SETTINGS_H
#define SETTINGS_H

#include <QtWidgets>
#include <QtGui>
#include <QPushButton>
#include <QMessageBox>

class Settings : public QWidget
{
    Q_OBJECT
public:
    explicit Settings(QWidget *parent = nullptr);
    QString getQss();
    QVector<int> getHotkey();

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

        int key, modify;
        bool changeOpen;
        int open, modifyOpen;
        bool changeSave;
        int save, modifySave;
        bool changeClear;
        int clear, modifyClear;
        bool changeExit;
        int exit, modifyExit;

protected:
        virtual void keyPressEvent(QKeyEvent *event) override;

signals:
        void retranslate();
        void redraw(QString, QPalette);
        void signal_changeOpen(int,int);
        void signal_changeSave(int,int);
        void signal_changeClear(int,int);
        void signal_changeExit(int,int);

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
