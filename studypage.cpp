#include "studypage.h"
#include "ui_studypage.h"

/**
 * @brief Sets up the study page
 * @param model
 * @param parent
 */
StudyPage::StudyPage(Model &model, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::StudyPage)
{
    ui->setupUi(this);

    connect(this, &StudyPage::BackSignal, &model, &Model::HomeScreenButtonClicked);
    connect(this, &StudyPage::NextStudyPlay, &model, &Model::GetNextStudyPlay);
    connect(this, &StudyPage::PrevStudyPlay, &model, &Model::GetPrevStudyPlay);
    connect(this, &StudyPage::RefreshStudy, &model, &Model::RefreshStudy);
    connect(&model, &Model::DisplayStudyPlay, this, &StudyPage::DisplayStudyPlay);
    connect(&model, &Model::UpdateStudyLabel, this, &StudyPage::UpdateNumberLabel);
}

/**
 * @brief Destructs the study page
 */
StudyPage::~StudyPage()
{
    delete ui;
}

/**
 * @brief Backbutton is clicked, takes back to home screen
 */
void StudyPage::on_backButton_clicked()
{
    emit BackSignal();
}

/**
 * @brief Displays a play
 * @param Play to be displayed
 */
void StudyPage::DisplayStudyPlay(Play *p) {
    currPlay = p;
    ui->playNameLabel->setText(QString::fromStdString(currPlay->playName));

    DragWidget* bg = ResetBackground(currPlay->backgroundType);
    DrawRoutes(bg);
}

/**
 * @brief Resets the background of the play
 * @param The background dragwidget
 * @return the finished background
 */
DragWidget* StudyPage::ResetBackground(DragWidget::RouteType bg) {
    ClearBackgroundLayout();
    currPlay->backgroundType = bg;
    QLabel *label1 = new QLabel("", this);
    DragWidget *background = new DragWidget(currPlay->backgroundType, label1);
    ui->playLayout->addWidget(background);
    return background;
}

/**
 * @brief Clears the background play
 */
void StudyPage::ClearBackgroundLayout() {
    if (ui->playLayout == NULL)
        return;

    QLayoutItem *item;
    while((item = ui->playLayout->takeAt(0))) {
        if (item->widget()) {
            delete item->widget();
        }
        delete item;
    }
}

/**
 * @brief Draws the routes on background
 * @param Background to draw on
 */
void StudyPage::DrawRoutes(DragWidget* bg) {
    for (auto pair : currPlay->routes) {
        QLabel *newIcon = new QLabel(bg);
        newIcon->setPixmap(pair.first);
        newIcon->move(pair.second);
        newIcon->show();
        newIcon->setAttribute(Qt::WA_DeleteOnClose);
    }
}

/**
 * @brief Left button clicked
 */
void StudyPage::on_leftButton_clicked()
{
    emit PrevStudyPlay();
}

/**
 * @brief Right button clicked
 */
void StudyPage::on_rightButton_clicked()
{
    emit NextStudyPlay();
}

/**
 * @brief Refreshes the study page
 */
void StudyPage::Refresh() {
    emit RefreshStudy();
}

/**
 * @brief Updates the number label
 * @param Label to display
 */
void StudyPage::UpdateNumberLabel(std::string labelText) {
    ui->playsLabel->setText(QString::fromStdString(labelText));
}

