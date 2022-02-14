
#include "texteditor.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setStyle(QStyleFactory::create("fusion"));
    a.setWindowIcon(QIcon(":/Icons/Icons/main.png"));

    TextEditor w;
    w.setMinimumHeight(200);
    w.setMinimumWidth(300);
    w.show();

    return a.exec();
}
