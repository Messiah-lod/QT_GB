#ifndef PARSEHTML_H
#define PARSEHTML_H

#include <QtWidgets>
#include <QtGui>
#include <QPushButton>
#include <QMessageBox>
#include <QByteArray>
#include <QFile>

class ParseHtml : public QWidget
{
    Q_OBJECT
public:
    explicit ParseHtml(QWidget *parent = nullptr);

private:
    QGridLayout *mainGrid; //создаем грид, который кладем на вкладку
    QPlainTextEdit *planeOne;
    QLabel *desc;
    QLabel *weather;
    QLabel *dollar;
    QLabel *euro;
    QPushButton *openHtml;

    QStringList getParametr(QString _str);
signals:

public slots:
    void on_openHtml_clicked();

};

#endif // PARSEHTML_H
