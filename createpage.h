#ifndef CREATEPAGE_H
#define CREATEPAGE_H

#include <QMainWindow>
#include <QTimer>
#include <QGraphicsPixmapItem>
#include "model.h"
#include "dragwidget.h"
#include "play.h"

using namespace std;

namespace Ui {
class CreatePage;
}

class CreatePage : public QMainWindow
{
    Q_OBJECT

public:
    std::vector<QString> backgrounds = {"BackDropIFormation", "BackDropGoalLine", "BackDropWishbone", "BackDropShotgun", "BackDropProSet", "BackDropSpread", "BackDropSingleBack"};
    explicit CreatePage(Model &model, QWidget *parent = nullptr);
    ~CreatePage();

private slots:
    void on_backButton_clicked();

    void on_passButton_clicked();

    void on_runButton_clicked();

    void on_flipButton_clicked();

    void on_hotButton_clicked();

    void on_iButton_clicked();

    void on_goalLineButton_clicked();

    void on_wishboneButton_clicked();

    void on_shotgunButton_clicked();

    void on_proSetButton_clicked();

    void on_spreadButton_clicked();

    void on_singleBackButton_clicked();


    void on_clearButton_clicked();

    void on_nextButton_clicked();

    void on_prevButton_clicked();

    void DisplayPlay(Play *p);
    void UpdatePlayName();
    void UpdateNumberLabel(std::string labelText);


signals:
    void BackSignal();
    void NextPlay();
    void PrevPlay();
    void StartPlay(Play *p);


private:
    Ui::CreatePage *ui;
    vector<QImage> routes;
    vector<QImage> formations;
    Play *currPlay;
    DragWidget* ResetBackground(DragWidget::RouteType bg);
    void SaveRoutes();
    void DrawRoutes(DragWidget* bg);
    void Setup();
    void ClearLayout();
    void AddRoutes();
    void AddHotRoutes();
    void AddFlippedRoutes();
    void AddHotFlippedRoutes();
    void AddRuns();
    void AddHotRuns();
    void AddFlippedRuns();
    void AddHotFlippedRuns();
    void AddFormations();
    void ClearBackgroundLayout();
    bool flipped = false;
    bool passShown = true;
    bool hotShown = false;
};

#endif // CREATEPAGE_H
