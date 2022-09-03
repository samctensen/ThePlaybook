#include "mainwindow.h"
#include "model.h"

#include <QApplication>

/**
 * @brief Runs the application
 * @param argc
 * @param argv
 * @return
 */
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Model model;
    MainWindow w(model, nullptr);
    return a.exec();
}
