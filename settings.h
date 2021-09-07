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

private:
        QGridLayout *mainGrid; //создаем грид, который кладем на вкладку

        QCheckBox *cbDark;
        QCheckBox *cbLanguage;

        // Создаём палитру для тёмной темы оформления
        QPalette darkPalette;
        QPalette palette;

        QString qss;
        QString qssDark;

        QTranslator *translator;
signals:
        void retranslate();
        void redraw(QString, QPalette);

public slots:
        void on_cbDark_clicked();
        void on_cbLanguage_clicked();
        void retranslateUI();
        void redrawUI(QString _qss, QPalette _palette);
};

#endif // SETTINGS_H
