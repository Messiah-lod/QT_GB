#ifndef FINEDIALOG_H
#define FINEDIALOG_H

#include <QDialog>
#include <QWidget>
#include <QPlainTextEdit>
#include <QGridLayout>
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>

class FineDialog : public QDialog
{
    Q_OBJECT
    Q_PROPERTY(QPlainTextEdit *textEdit WRITE setTextEdit)

    public:
       explicit FineDialog(QWidget *parent = nullptr);
       virtual ~FineDialog() override;
       void setTextEdit(QPlainTextEdit *textEdit);
    signals:

    public slots:
       void findPrev();                  // Сигнал от кнопки Поиск (до курсора или после)
       void findNext();
       void retranslateUI();
    private:
       QPlainTextEdit *textEdit;
       QGridLayout *layout;
       QLabel *label;
       QLineEdit *lineEdit;              // Строка для ввода строки поиска
       QPushButton *findButtons[2];      // 2 кнопки поиска
    signals:
       void setCursorPos(int, int, int); // Сигнал с указанием выделения текста и новой позиции курсора. Начало, длина, новая позиция
};

#endif // FINEDIALOG_H
