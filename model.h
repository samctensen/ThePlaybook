#ifndef MODEL_H
#define MODEL_H

#include <QObject>
#include <QDebug>
#include <QImage>
#include <QPixmap>
#include <QLabel>
#include <QtWidgets>
#include <iostream>
#include <QPoint>
#include "play.h"
#include "dragwidget.h"


class Model: public QObject{
    Q_OBJECT

private:
    std::vector<Play*> plays;
    std::vector<std::string> fakePlayNames;
    int playIndex = 0;
    int studyPlayIndex = 0;
    int testPlayIndex = 0;
    void addFakePlayNames();
    void SendTestChoices();
    int correctOption;
    bool addedFake = false;
    int Get2ndOption();
    int SecondOption = -1;
    int Get3rdOption();
    int ThirdOption = -1;
    int Get4thOption();
    int FourthOption = -1;;
    void SetOptionsFakeNames();
    void SetOptionsRealNames();
    DragWidget::RouteType GetBackgroundEnum(QString backgroundName);

public:
    Model(QObject *parent = nullptr);
    Play* getFirstPlay();

public slots:
    void HomeScreenButtonClicked();
    void GetNextPlay();
    void GetPrevPlay();
    void GetNextStudyPlay();
    void GetPrevStudyPlay();
    void RefreshStudy();
    void RefreshTest();
    void GetAnswer(int ans);
    void SaveFile(QString filename);
    void OpenFile(QString filename);


signals:
    void ShowHomeScreen();
    void DisplayPlay(Play *p);
    void DisplayStudyPlay(Play *p);
    void DisplayTestPlay(Play *p);
    void UpdateLabel(std::string labelText);
    void UpdateStudyLabel(std::string labelText);
    void SetOption1(std::string option1);
    void SetOption2(std::string option2);
    void SetOption3(std::string option3);
    void SetOption4(std::string option4);
    void SendResult(std::string result);
    void UpdatePlayName();
};

#endif // MODEL_H
