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


private:
        QGridLayout *mainGrid; //создаем грид, который кладем на вкладку

        QCheckBox *cbDark;
        QCheckBox *cbLanguage;

        // Создаём палитру для тёмной темы оформления
        QPalette darkPalette;

        QString qss;
        QString qssDark;

        QTranslator *translator;
signals:
        void retranslate();

public slots:
        void on_cbDark_clicked();
        void on_cbLanguage_clicked();
        void retranslateUI();
};

#endif // SETTINGS_H
