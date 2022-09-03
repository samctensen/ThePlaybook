#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QStackedWidget>
#include <QSizePolicy>
#include <QGraphicsDropShadowEffect>
#include "createpage.h"
#include "testpage.h"
#include "studypage.h"
#include "box.h"
#include "model.h"
#include <iostream>

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(Model &model, QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_createButton_clicked();

    void on_testButton_clicked();

    void on_studyButton_clicked();

    void on_saveButton_clicked();

    void on_loadButton_clicked();

    void ShowHomeScreen();

    void BounceLabel();

signals:
    void SaveFile(QString filename);

    void OpenFile(QString filename);
private:
    bool onHomePage = true;
    QStackedWidget* stackedPages;
    void Setup(Model &model);
    void PlaybookLabel();
    StudyPage* studyPage;
    TestPage* testPage;
    Ui::MainWindow *ui;
    Box box;

};
#endif // MAINWINDOW_H
