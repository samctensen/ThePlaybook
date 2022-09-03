#ifndef TESTPAGE_H
#define TESTPAGE_H

#include <QMainWindow>
#include "model.h"
#include "play.h"

using namespace std;

namespace Ui {
class TestPage;
}

class TestPage : public QMainWindow
{
    Q_OBJECT

public:
    explicit TestPage(Model &model, QWidget *parent = nullptr);
    ~TestPage();
    void Refresh();

private slots:
    void on_backButton_clicked();
    void DisplayTestPlay(Play *p);
    void SetOption1(std::string option1);
    void SetOption2(std::string option2);
    void SetOption3(std::string option3);
    void SetOption4(std::string option4);
    void GetResult(std::string result);
    void on_checkButton_clicked();

signals:
    void BackSignal();
    void RefreshTest();
    void SendAnswer(int ans);


private:
    Ui::TestPage *ui;
    Play *currPlay;
    string currPlayname;
    vector<string> fakePlayNames;
    DragWidget* ResetBackground(DragWidget::RouteType bg);
    void ClearBackgroundLayout();
    void DrawRoutes(DragWidget* bg);
};

#endif // TESTPAGE_H
