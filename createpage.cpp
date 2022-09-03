#include "createpage.h"
#include "ui_createpage.h"

/**
 * @brief Sets up the create page for the app
 * @param model
 * @param parent
 */
CreatePage::CreatePage(Model &model, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CreatePage)
{
    ui->setupUi(this);
    QTimer::singleShot(100, this, &CreatePage::Setup);

    connect(this, &CreatePage::BackSignal, &model, &Model::HomeScreenButtonClicked);
    connect(this, &CreatePage::NextPlay, &model, &Model::GetNextPlay);
    connect(this, &CreatePage::PrevPlay, &model, &Model::GetPrevPlay);
    connect(&model, &Model::DisplayPlay, this, &CreatePage::DisplayPlay);
    connect(&model, &Model::UpdateLabel, this, &CreatePage::UpdateNumberLabel);
    connect( &model, &Model::UpdatePlayName, this, &CreatePage::UpdatePlayName);

    ui->spreadButton->setIcon(QIcon(":/Images/Spread.png"));
    ui->spreadButton->setIconSize(QSize(160, 130));

    ui->shotgunButton->setIcon(QIcon(":/Images/Shotgun.png"));
    ui->shotgunButton->setIconSize(QSize(160, 130));

    ui->iButton->setIcon(QIcon(":/Images/I-Formation.png"));
    ui->iButton->setIconSize(QSize(160, 130));

    ui->wishboneButton->setIcon(QIcon(":/Images/Wishbone.png"));
    ui->wishboneButton->setIconSize(QSize(160, 130));

    ui->goalLineButton->setIcon(QIcon(":/Images/GoalLine.png"));
    ui->goalLineButton->setIconSize(QSize(160, 130));

    ui->proSetButton->setIcon(QIcon(":/Images/ProSet.png"));
    ui->proSetButton->setIconSize(QSize(160, 130));

    ui->singleBackButton->setIcon(QIcon(":/Images/SingleBack.png"));
    ui->singleBackButton->setIconSize(QSize(160, 130));

    currPlay = model.getFirstPlay();
}

/**
 * @brief Destructs the create page
 */
CreatePage::~CreatePage()
{
    delete ui;
}

/**
 * @brief Helper method to setup the page
 */
void CreatePage::Setup() {
    ui->formationLabel->setStyleSheet("border: 1px solid black");
    ui->textEdit->clear();
    ui->textEdit->insertPlainText(QString::fromStdString(currPlay->playName));
    QLabel *label1 = new QLabel("", this);
    DragWidget *background = new DragWidget(currPlay->backgroundType, label1);
    ui->verticalLayoutCenter->addWidget(background);

    AddRoutes();
    AddFormations();
}

/**
 * @brief Slot for the back/home button
 */
void CreatePage::on_backButton_clicked()
{
    SaveRoutes();

    emit BackSignal();
}

/**
 * @brief Clears the layout containing the frames.
 */
void CreatePage::ClearLayout() {
    if (ui->routeLayout == NULL)
        return;

    QLayoutItem *item;
    while((item = ui->routeLayout->takeAt(0))) {
        if (item->widget()) {
            delete item->widget();
        }
        delete item;
    }
}

/**
 * @brief Clears the field background
 */
void CreatePage::ClearBackgroundLayout() {
    if (ui->verticalLayoutCenter == NULL)
        return;

    QLayoutItem *item;
    while((item = ui->verticalLayoutCenter->takeAt(0))) {
        if (item->widget()) {
            delete item->widget();
        }
        delete item;
    }
}

/**
 * @brief Adds normal routes to the routes panel
 */
void CreatePage::AddRoutes() {
    flipped = false;
    ClearLayout();

    QLabel *label1 = new QLabel("", this);

    vector<DragWidget::RouteType> passes = {DragWidget::Dig, DragWidget::Corner, DragWidget::Post, DragWidget::Flat, DragWidget::Comeback, DragWidget::Out, DragWidget::Go, DragWidget::Curl, DragWidget::Slant};

    for (auto pass : passes) {
        DragWidget *route = new DragWidget(pass, label1);
        ui->routeLayout->addWidget(route);
    }
}

/**
 * @brief Adds hot routes to the routes panel
 */
void CreatePage::AddHotRoutes() {
    flipped = false;
    ClearLayout();

    QLabel *label1 = new QLabel("", this);

    vector<DragWidget::RouteType> hotPasses = {DragWidget::HotDig, DragWidget::HotCorner, DragWidget::HotPost, DragWidget::HotFlat, DragWidget::HotComeback, DragWidget::HotOut, DragWidget::HotGo, DragWidget::HotCurl, DragWidget::HotSlant};

    for (auto hotPass : hotPasses) {
        DragWidget *route = new DragWidget(hotPass, label1);
        ui->routeLayout->addWidget(route);
    }
}

/**
 * @brief Adds flipped routes to the routes panel
 */
void CreatePage::AddFlippedRoutes() {
    flipped = true;
    ClearLayout();

    QLabel *label1 = new QLabel("Text", this);

    vector<DragWidget::RouteType> passes = {DragWidget::Dig_Flip, DragWidget::Corner_Flip, DragWidget::Post_Flip, DragWidget::Flat_Flip, DragWidget::Comeback_Flip, DragWidget::Out_Flip, DragWidget::Go_Flip, DragWidget::Curl_Flip, DragWidget::Slant_Flip};

    for (auto pass : passes) {
        DragWidget *route = new DragWidget(pass, label1);
        ui->routeLayout->addWidget(route);
    }
}

/**
 * @brief Adds hot routes that have been flipped to the routes panel
 */
void CreatePage::AddHotFlippedRoutes() {
    flipped = true;
    ClearLayout();

    QLabel *label1 = new QLabel("Text", this);

    vector<DragWidget::RouteType> hotPasses = {DragWidget::HotDig_Flip, DragWidget::HotCorner_Flip, DragWidget::HotPost_Flip, DragWidget::HotFlat_Flip, DragWidget::HotComeback_Flip, DragWidget::HotOut_Flip, DragWidget::HotGo_Flip, DragWidget::HotCurl_Flip, DragWidget::HotSlant_Flip};

    for (auto hotPass : hotPasses) {
        DragWidget *route = new DragWidget(hotPass, label1);
        ui->routeLayout->addWidget(route);
    }
}

/**
 * @brief Adds runs to the run panel
 */
void CreatePage::AddRuns() {
    flipped = false;
    ClearLayout();

    QLabel *label1 = new QLabel("Text", this);

    vector<DragWidget::RouteType> runs = {DragWidget::Run1, DragWidget::Run2, DragWidget::Run3, DragWidget::Run4, DragWidget::Run5};

    for (auto run : runs) {
        DragWidget *route = new DragWidget(run, label1);
        ui->routeLayout->addWidget(route);
    }
}

/**
 * @brief Adds hot runs to the run panel
 */
void CreatePage::AddHotRuns() {
    flipped = false;
    ClearLayout();

    QLabel *label1 = new QLabel("Text", this);

    vector<DragWidget::RouteType> hotRuns = {DragWidget::HotRun1, DragWidget::HotRun2, DragWidget::HotRun3, DragWidget::HotRun4, DragWidget::HotRun5};

    for (auto hotRun : hotRuns) {
        DragWidget *route = new DragWidget(hotRun, label1);
        ui->routeLayout->addWidget(route);
    }
}

/**
 * @brief Adds flipped runs to the run panel
 */
void CreatePage::AddFlippedRuns() {
    flipped = true;
    ClearLayout();

    QLabel *label1 = new QLabel("Text", this);

    vector<DragWidget::RouteType> runs = {DragWidget::Run1_Flip, DragWidget::Run2_Flip, DragWidget::Run3_Flip, DragWidget::Run4_Flip, DragWidget::Run5_Flip};

    for (auto run : runs) {
        DragWidget *route = new DragWidget(run, label1);
        ui->routeLayout->addWidget(route);
    }
}

/**
 * @brief Adds hot flipped runs to the run panel
 */
void CreatePage::AddHotFlippedRuns() {
    flipped = true;
    ClearLayout();

    QLabel *label1 = new QLabel("Text", this);

    vector<DragWidget::RouteType> hotRuns = {DragWidget::HotRun1_Flip, DragWidget::HotRun2_Flip, DragWidget::HotRun3_Flip, DragWidget::HotRun4_Flip, DragWidget::HotRun5_Flip};

    for (auto hotRun : hotRuns) {
        DragWidget *route = new DragWidget(hotRun, label1);
        ui->routeLayout->addWidget(route);
    }
}

/**
 * @brief Adds formations to the formations panel
 */
void CreatePage::AddFormations() {
    formations.clear();

    vector<QImage> formationImages = {QImage(":/Images/GoalLine.png"), QImage(":/Images/I-Formation.png"), QImage(":/Images/ProSet.png"), QImage(":/Images/Shotgun.png"), QImage(":/Images/SingleBack.png"), QImage(":/Images/Spread.png")};

    for (auto img : formationImages) {
        formations.push_back(img);
    }
}

/**
 * @brief Slot for the pass button to show passes
 */
void CreatePage::on_passButton_clicked()
{
    AddRoutes();
    passShown = true;
    ui->hotButton->setText("Hot Pass");
}

/**
 * @brief Slot for the run button to show runs
 */
void CreatePage::on_runButton_clicked()
{
    AddRuns();
    passShown = false;
    ui->hotButton->setText("Hot Run");
}

/**
 * @brief Slot to flip the routes/runs
 */
void CreatePage::on_flipButton_clicked()
{
    if (!hotShown) {
        if(passShown) {
            if (flipped) {
                AddRoutes();
            } else {
                AddFlippedRoutes();
            }
        } else {
            if (flipped) {
                AddRuns();
            } else {
                AddFlippedRuns();
            }
        }
    } else {
        if(passShown) {
            if (flipped) {
                AddHotRoutes();
            } else {
                AddHotFlippedRoutes();
            }
        } else {
            if (flipped) {
                AddHotRuns();
            } else {
                AddHotFlippedRuns();
            }
        }
    }
}

/**
 * @brief Slot to change the routes/runs to hot routes/runs
 */
void CreatePage::on_hotButton_clicked()
{
    if (hotShown) {
        hotShown = false;
        if(passShown) {
            ui->hotButton->setText("Hot Pass");
            if (flipped) {
                AddFlippedRoutes();
            }
            else {
                AddRoutes();
            }
        }
        else {
            if (flipped) {
                AddFlippedRuns();
            }
            else {
                AddRuns();
            }
        }
    }
    else {
        hotShown = true;
        if(passShown) {
            ui->hotButton->setText("Normal Pass");
            if (flipped) {
                AddHotFlippedRoutes();
            }
            else {
                AddHotRoutes();
            }
        }
        else {
            if (flipped) {
                AddHotFlippedRuns();
            }
            else {
                AddHotRuns();
            }
        }
    }
}

/**
 * @brief Slot to set background to I-Formation
 */
void CreatePage::on_iButton_clicked()
{
    currPlay->routes.clear();
    ResetBackground(DragWidget::BackDropIFormation);
    currPlay->backgroundName = backgrounds.at(0);
}

/**
 * @brief Slot to set background to Goal Line formation
 */
void CreatePage::on_goalLineButton_clicked()
{
    currPlay->routes.clear();
    ResetBackground(DragWidget::BackDropGoalLine);
    currPlay->backgroundName = backgrounds.at(1);
}

/**
 * @brief Slot to set background to Wishbone formation
 */
void CreatePage::on_wishboneButton_clicked()
{
    currPlay->routes.clear();
    ResetBackground(DragWidget::BackDropWishbone);
    currPlay->backgroundName = backgrounds.at(2);
}

/**
 * @brief Slot to set background to Shotgun formation
 */
void CreatePage::on_shotgunButton_clicked()
{
    currPlay->routes.clear();
    ResetBackground(DragWidget::BackDropShotgun);
    currPlay->backgroundName = backgrounds.at(3);
}

/**
 * @brief Slot to set background to Pro Set formation
 */
void CreatePage::on_proSetButton_clicked()
{
    currPlay->routes.clear();
    ResetBackground(DragWidget::BackDropProSet);
    currPlay->backgroundName = backgrounds.at(4);
}

/**
 * @brief Slot to set background to Spread formation
 */
void CreatePage::on_spreadButton_clicked()
{
    currPlay->routes.clear();
    ResetBackground(DragWidget::BackDropSpread);
    currPlay->backgroundName = backgrounds.at(5);
}

/**
 * @brief Slot to set background to Single Back formation
 */
void CreatePage::on_singleBackButton_clicked()
{
    currPlay->routes.clear();
    ResetBackground(DragWidget::BackDropSingleBack);
    currPlay->backgroundName = backgrounds.at(6);
}

/**
 * @brief Resets the background according to the given type
 * @param bg
 * @return
 */
DragWidget* CreatePage::ResetBackground(DragWidget::RouteType bg) {
    ClearBackgroundLayout();
    DragWidget::currentRoutes.clear();
    DragWidget::hotUsed = false;
    currPlay->backgroundType = bg;
    QLabel *label1 = new QLabel("Text", this);
    DragWidget *background = new DragWidget(currPlay->backgroundType, label1);
    ui->verticalLayoutCenter->addWidget(background);
    return background;
}

/**
 * @brief Clears and sets everything back to its original state
 */
void CreatePage::on_clearButton_clicked()
{
    currPlay->routes.clear();
    ResetBackground(currPlay->backgroundType);
    ui->hotButton->setEnabled(true);
    hotShown = false;
}

/**
 * @brief Saves routes
 */
void CreatePage::SaveRoutes() {
    currPlay->SaveRoutes();
    currPlay->playName = ui->textEdit->toPlainText().toStdString();
    DragWidget::hotUsed = currPlay->hotRouteUsed;
}

/**
 * @brief Draws routes on the background
 * @param bg
 */
void CreatePage::DrawRoutes(DragWidget* bg) {
    for (auto pair : currPlay->routes) {
        QLabel *newIcon = new QLabel(bg);
        newIcon->setPixmap(pair.first);
        newIcon->move(pair.second);
        newIcon->show();
        newIcon->setAttribute(Qt::WA_DeleteOnClose);
    }

    DragWidget::hotUsed = currPlay->hotRouteUsed;
}

/**
 * @brief Creates/goes to a next play
 */
void CreatePage::on_nextButton_clicked()
{
    SaveRoutes();

    emit NextPlay();
    ui->textEdit->clear();
    ui->textEdit->insertPlainText(QString::fromStdString(currPlay->playName));
}

/**
 * @brief Goes to the previous play
 */
void CreatePage::on_prevButton_clicked()
{
    SaveRoutes();

    emit PrevPlay();
    ui->textEdit->clear();
    ui->textEdit->insertPlainText(QString::fromStdString(currPlay->playName));
}

/**
 * @brief Displays the given play
 * @param p
 */
void CreatePage::DisplayPlay(Play *p) {
    currPlay = p;

    DragWidget* bg = ResetBackground(currPlay->backgroundType);
    DrawRoutes(bg);
}

/**
 * @brief Updates the play label name
 * @param labelText
 */
void CreatePage::UpdateNumberLabel(std::string labelText) {
    ui->playsLabel->setText(QString::fromStdString(labelText));
}

/**
 * @brief Updates the playname label
 */
void CreatePage::UpdatePlayName() {
    ui->textEdit->clear();
    ui->textEdit->insertPlainText(QString::fromStdString(currPlay->playName));
}
