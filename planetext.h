#ifndef PLANETEXT_H
#define PLANETEXT_H

#include <QtWidgets>
#include <QtGui>
#include <QPushButton>
#include <QMessageBox>

class planeText : public QWidget
{
    Q_OBJECT
public:
    explicit planeText(QWidget *parent = nullptr);

    QGridLayout *mainGrid; //создаем грид, который кладем на вкладку
    QPushButton *buttonTextToSecond;
    QPushButton *buttonReplaceTextOne;
    QPushButton *buttonAppendHtmlTextSecond;

    QPlainTextEdit *planeOne;
    QPlainTextEdit *planeTwo;

    QLabel *description;
    QLabel *oneText;
    QLabel *twoText;
signals:

public slots:
    void on_buttonTextToSecond_clicked();
    void on_buttonReplaceTextOne_clicked();
    void on_buttonAppendHtmlTextSecond_clicked();
};

#endif // PLANETEXT_H
