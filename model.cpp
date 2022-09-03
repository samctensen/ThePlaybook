#include "model.h"
#include <QMetaEnum>

/**
 * @brief Sets up the model to control the application
 * @param parent
 */
Model::Model(QObject *parent):
    QObject(parent)
{
    plays.push_back(new Play(DragWidget::BackDropIFormation, DragWidget::currentRoutes));
}

/**
 * @brief Slot to show the homescreen
 */
void Model::HomeScreenButtonClicked() {
    emit ShowHomeScreen();
}

/**
 * @brief Gets the first play in the vector of plays
 * @return
 */
Play* Model::getFirstPlay() {
    return plays.at(0);
}

/**
 * @brief Gets the next play in the vector of plays
 */
void Model::GetNextPlay() {
    playIndex++;
    if(playIndex == (int) plays.size()) {
        Play *currPlay = new Play(DragWidget::BackDropIFormation, DragWidget::currentRoutes);
        currPlay->playName = "Play "+ std::to_string(playIndex + 1);
        plays.push_back(currPlay);
        emit DisplayPlay(currPlay);
    } else {
        emit DisplayPlay(plays.at(playIndex));
    }
    std::string labelText = "Play " + std::to_string(playIndex + 1) + " of " + std::to_string(plays.size());
    emit UpdateLabel(labelText);
}

/**
 * @brief Gets the previous play in the vector of plays
 */
void Model::GetPrevPlay() {
    if (playIndex != 0) {
        playIndex--;
    }
    emit DisplayPlay(plays.at(playIndex));
    std::string labelText = "Play " + std::to_string(playIndex + 1) + " of " + std::to_string(plays.size());
    emit UpdateLabel(labelText);
}

/**
 * @brief Gets the next play for the study page
 */
void Model::GetNextStudyPlay() {
    if (studyPlayIndex != (int) plays.size() - 1) {
        studyPlayIndex++;
    }

    emit DisplayStudyPlay(plays.at(studyPlayIndex));

    std::string labelText = "Play " + std::to_string(studyPlayIndex + 1) + " of " + std::to_string(plays.size());
    emit UpdateStudyLabel(labelText);
}

/**
 * @brief Gets the previous play for the study page
 */
void Model::GetPrevStudyPlay() {
    if (studyPlayIndex != 0) {
        studyPlayIndex--;
    }

    emit DisplayStudyPlay(plays.at(studyPlayIndex));

    std::string labelText = "Play " + std::to_string(studyPlayIndex + 1) + " of " + std::to_string(plays.size());
    emit UpdateStudyLabel(labelText);
}

/**
 * @brief Refreshes the study page
 */
void Model::RefreshStudy() {
    std::string labelText = "Play " + std::to_string(studyPlayIndex + 1) + " of " + std::to_string(plays.size());
    emit UpdateStudyLabel(labelText);
    emit DisplayStudyPlay(plays.at(studyPlayIndex));
}

/**
 * @brief Refreshes the test page
 */
void Model::RefreshTest() {
    emit SendResult("");
    testPlayIndex = rand() % plays.size();
    SendTestChoices();
    emit DisplayTestPlay(plays.at(testPlayIndex));
}

/**
 * @brief Creates choices for the test
 */
void Model::SendTestChoices(){
    if (!addedFake) {
        addFakePlayNames();
    }

    correctOption = 1 + rand() % 4; //rand number 1 to 4

    if ((int) plays.size() < 4) {
        SetOptionsFakeNames();
    }
    else {
        SetOptionsRealNames();
    }
}

/**
 * @brief Creates fake play names
 */
void Model::SetOptionsFakeNames() {
    std::string currPlayname = plays.at(testPlayIndex)->playName;

    std::vector<std::string> options;
    for (int i = 0; i < 3; i++) {
        options.push_back(fakePlayNames.at(rand() % fakePlayNames.size()));
    }
    options.insert(options.begin() + correctOption - 1, currPlayname);

    emit SetOption1(options.at(0));
    emit SetOption2(options.at(1));
    emit SetOption3(options.at(2));
    emit SetOption4(options.at(3));
}

/**
 * @brief Sets real plays as options
 */
void Model::SetOptionsRealNames() {
    std::string currPlayname = plays.at(testPlayIndex)->playName;

    std::vector<std::string> options;
    options.push_back(plays.at(Get2ndOption())->playName);
    options.push_back(plays.at(Get3rdOption())->playName);
    options.push_back(plays.at(Get4thOption())->playName);
    options.insert(options.begin() + correctOption - 1, currPlayname);

    emit SetOption1(options.at(0));
    emit SetOption2(options.at(1));
    emit SetOption3(options.at(2));
    emit SetOption4(options.at(3));
}

/**
 * @brief Gets the second option
 * @return
 */
int Model::Get2ndOption() {
    SecondOption = rand() % plays.size();
    if (SecondOption == testPlayIndex || SecondOption == ThirdOption || SecondOption == FourthOption){
        Get2ndOption();
    }
    return SecondOption;
}

/**
 * @brief Gets the third option
 * @return
 */
int Model::Get3rdOption() {
    ThirdOption = rand() % plays.size();
    if (ThirdOption == testPlayIndex || ThirdOption == SecondOption || ThirdOption == FourthOption){
        Get3rdOption();
    }
    return ThirdOption;
}

/**
 * @brief Gets the fourth option
 * @return
 */
int Model::Get4thOption() {
    FourthOption = rand() % plays.size();
    if (FourthOption == testPlayIndex || FourthOption == SecondOption || FourthOption == ThirdOption){
        Get4thOption();
    }
    return FourthOption;
}

/**
 * @brief Gets the correct answer
 * @param ans
 */
void Model::GetAnswer(int ans){
    if (correctOption == ans) {
        emit SendResult("Good job, you got it right!");
        QTimer::singleShot(3000, this, &Model::RefreshTest);
    }
    else {
        emit SendResult("That is wrong, try again.");
    }
}

/**
 * @brief Adds fake play names to a vector
 */
void Model::addFakePlayNames() {
    addedFake = true;
    std::vector<std::string> fakeNames = {"Sweep", "Quarterback Sneak", "WR Option", "Hitch & Go", "HB Draw", "Screen Pass", "Dagger", "Drag Under", "Vertical TE Out"};
    for (auto name : fakeNames) {
        fakePlayNames.push_back(name);
    }
}

/**
 * @brief Serializes the Playbook into json and saves to a .fbpb file
 */
void Model::SaveFile(QString filename) {
    if (!filename.isEmpty()) {
        QJsonDocument saveDoc;
        QJsonObject saveObject;
        QJsonObject savePlays;
        int playCounter = 0;
        for (Play* nextPlay: plays){
            int routeCounter = 0;
            QJsonObject playSave;
            playSave["playName"] = QString::fromStdString(nextPlay->playName);
            playSave["background"] = nextPlay->backgroundName;
            playSave["hotUsed"] = QVariant(nextPlay->hotRouteUsed).toString();
            QJsonObject routesSave;
            for (std::pair<QPixmap, QPoint> route: nextPlay->routes) {
                QJsonObject routeSave;
                QBuffer buffer;
                buffer.open(QIODevice::WriteOnly);
                route.first.save(&buffer, "PNG");
                auto const encoded = buffer.data().toBase64();
                routeSave["pixmap"] = QLatin1String(encoded);
                QJsonObject pointSave;
                pointSave["x"] = route.second.x();
                pointSave["y"] = route.second.y();
                routeSave["point"] = pointSave;
                routesSave["route" + QString::number(routeCounter)] = routeSave;
                routeCounter++;
            }
            playSave["routes"] = routesSave;
            savePlays["Play" + QString::number(playCounter)] = playSave;
            playCounter++;
        }
        saveObject["plays"] = savePlays;
        saveDoc.setObject(saveObject);
        QByteArray jsonData = saveDoc.toJson();
        QFile output(filename);
        if (output.open(QIODevice::WriteOnly)) {
            output.write(jsonData);
            output.close();
        }
    }
}

/**
 * @brief Deserializes the JSON .fbpb file and loads the plays from the file to the screen
 */
void Model::OpenFile(QString filename) {
    std::vector<Play*> newPlays;
    if (!filename.isEmpty()) {
        QJsonDocument loadDoc;
        QJsonObject loadObject;
        QByteArray jsonData;
        QFile loadFile(filename);
        if (loadFile.open(QIODevice::ReadOnly)) {
            jsonData = loadFile.readAll();
            loadDoc = loadDoc.fromJson(jsonData);
            loadObject = loadDoc.object();
            QJsonObject loadPlays = loadObject["plays"].toObject();
            std::vector<Play*> newPlays;
            for (int playIndex = 0; playIndex < loadPlays.size(); playIndex++) {
                QJsonObject play = loadPlays["Play" + QString::number(playIndex)].toObject();
                QString playName = play["playName"].toString();
                QString background = play["background"].toString();
                bool hotUsed = QVariant(play["hotUsed"].toString()).toBool();
                DragWidget::RouteType backgroundType = GetBackgroundEnum(background);
                QJsonObject routesObject = play["routes"].toObject();
                std::vector<std::pair<QPixmap, QPoint>> routes;
                for (int routeIndex = 0; routeIndex < routesObject.size(); routeIndex++) {
                    QJsonObject route = routesObject["route" + QString::number(routeIndex)].toObject();
                    QJsonValue pixmapJSON = route["pixmap"];
                    auto const encoded = pixmapJSON.toString().toLatin1();
                    QPixmap pixmap;
                    pixmap.loadFromData(QByteArray::fromBase64(encoded), "PNG");
                    QJsonObject pointObject = route["point"].toObject();
                    int x = pointObject["x"].toInt();
                    int y = pointObject["y"].toInt();
                    QPoint point(x,y);
                    std::pair<QPixmap, QPoint> pair(pixmap, point);
                    routes.push_back(pair);
                }
                Play* newPlay = new Play(backgroundType, routes);
                newPlay->playName = playName.toStdString();
                newPlay->hotRouteUsed = hotUsed;
                newPlays.push_back(newPlay);
            }
            plays = newPlays;
            playIndex = 0;
            for (Play* play : plays) {
                emit DisplayPlay(play);
                if (play != plays.at(plays.size() - 1)) {
                    GetNextPlay();
                }
            }
            emit DisplayPlay(plays.at(0));
            playIndex = 0;
            studyPlayIndex = 0;
            testPlayIndex = 0;
            emit UpdatePlayName();
            std::string labelText = "Play " + std::to_string(playIndex + 1) + " of " + std::to_string(plays.size());
            emit UpdateLabel(labelText);
        }
    }
}

/**
 * @brief Returns the right DragWidget RouteType for the background given the string name
 */
DragWidget::RouteType Model::GetBackgroundEnum(QString backgroundName){
    if (backgroundName == "BackDropGoalLine") {
        return DragWidget::RouteType::BackDropGoalLine;
    }
    if (backgroundName == "BackDropWishbone") {
        return DragWidget::RouteType::BackDropWishbone;
    }
    if (backgroundName == "BackDropShotgun") {
        return DragWidget::RouteType::BackDropShotgun;
    }
    if (backgroundName == "BackDropProSet") {
        return DragWidget::RouteType::BackDropProSet;
    }
    if (backgroundName == "BackDropSpread") {
        return DragWidget::RouteType::BackDropSpread;
    }
    if (backgroundName == "BackDropSingleBack") {
        return DragWidget::RouteType::BackDropSingleBack;
    }
    else {
        return DragWidget::RouteType::BackDropIFormation;
    }
}
