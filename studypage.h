#ifndef STUDYPAGE_H
#define STUDYPAGE_H

#include <QMainWindow>
#include "model.h"
#include "play.h"

namespace Ui {
class StudyPage;
}

class StudyPage : public QMainWindow
{
    Q_OBJECT

public:
    explicit StudyPage(Model &model, QWidget *parent = nullptr);
    ~StudyPage();
    void Refresh();

private slots:
    void on_backButton_clicked();
    void DisplayStudyPlay(Play *p);

    void on_leftButton_clicked();

    void on_rightButton_clicked();
    void UpdateNumberLabel(std::string labelText);

signals:
    void BackSignal();
    void NextStudyPlay();
    void PrevStudyPlay();
    void RefreshStudy();

private:
    Ui::StudyPage *ui;
    Play *currPlay;
    void ClearBackgroundLayout();
    void DrawRoutes(DragWidget* bg);
    DragWidget* ResetBackground(DragWidget::RouteType bg);
};

#endif // STUDYPAGE_H
