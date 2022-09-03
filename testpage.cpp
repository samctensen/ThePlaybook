#include "testpage.h"
#include "ui_testpage.h"

/**
 * @brief Sets up the test page
 * @param model
 * @param parent
 */
TestPage::TestPage(Model &model, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::TestPage)
{
    ui->setupUi(this);

    connect(this, &TestPage::BackSignal, &model, &Model::HomeScreenButtonClicked);
    connect(this, &TestPage::RefreshTest, &model, &Model::RefreshTest);
    connect(this, &TestPage::SendAnswer, &model, &Model::GetAnswer);
    connect(&model, &Model::DisplayTestPlay, this, &TestPage::DisplayTestPlay);
    connect(&model, &Model::SendResult, this, &TestPage::GetResult);
    connect(&model, &Model::SetOption1, this, &TestPage::SetOption1);
    connect(&model, &Model::SetOption2, this, &TestPage::SetOption2);
    connect(&model, &Model::SetOption3, this, &TestPage::SetOption3);
    connect(&model, &Model::SetOption4, this, &TestPage::SetOption4);
}

/**
 * @brief Destructs the test page
 */
TestPage::~TestPage()
{
    delete ui;
}

/**
 * @brief Back button clicked
 */
void TestPage::on_backButton_clicked()
{
    emit BackSignal();
}

/**
 * @brief Displays a given play
 * @param Play to be displayed
 */
void TestPage::DisplayTestPlay(Play *p) {
    currPlay = p;
    currPlayname = currPlay->playName;
    DragWidget* bg = ResetBackground(currPlay->backgroundType);
    DrawRoutes(bg);
}

/**
 * @brief Sets option 1 of multiple choice
 * @param Play name
 */
void TestPage::SetOption1(std::string option1){
    ui->option1->setText(QString::fromStdString(option1));
}

/**
 * @brief Sets option 2 of multiple choice
 * @param Play name
 */
void TestPage::SetOption2(std::string option2){
    ui->option2->setText(QString::fromStdString(option2));
}

/**
 * @brief Sets option 3 of multiple choice
 * @param Play name
 */
void TestPage::SetOption3(std::string option3){
    ui->option3->setText(QString::fromStdString(option3));
}

/**
 * @brief Sets option 4 of multiple choice
 * @param Play name
 */
void TestPage::SetOption4(std::string option4){
    ui->option4->setText(QString::fromStdString(option4));
}

/**
 * @brief Resets the background of the play
 * @param Formation to change
 * @return The dragwidget formation
 */
DragWidget* TestPage::ResetBackground(DragWidget::RouteType bg) {
    ClearBackgroundLayout();
    currPlay->backgroundType = bg;
    QLabel *label1 = new QLabel("", this);
    DragWidget *background = new DragWidget(currPlay->backgroundType, label1);
    ui->playLayout->addWidget(background);
    return background;
}

/**
 * @brief Draws the routes on specific formation
 * @param Dragwidget background
 */
void TestPage::DrawRoutes(DragWidget* bg) {
    for (auto pair : currPlay->routes) {
        QLabel *newIcon = new QLabel(bg);
        newIcon->setPixmap(pair.first);
        newIcon->move(pair.second);
        newIcon->show();
        newIcon->setAttribute(Qt::WA_DeleteOnClose);
    }
}

/**
 * @brief Clears the background formation and plays
 */
void TestPage::ClearBackgroundLayout() {
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
 * @brief Refreshes the whole test page
 */
void TestPage::Refresh() {
    emit RefreshTest();
}

/**
 * @brief Send which check button is clicked
 */
void TestPage::on_checkButton_clicked()
{
    int selectedAns = 0;
    if (ui->option1->isChecked())
        selectedAns = 1;
    if (ui->option2->isChecked())
        selectedAns = 2;
    if (ui->option3->isChecked())
        selectedAns = 3;
    if (ui->option4->isChecked())
        selectedAns = 4;
    emit SendAnswer(selectedAns);
}

/**
 * @brief Displays narration
 * @param Narration from model
 */
void TestPage::GetResult(string result){
    ui->narrationLabel->setText(QString::fromStdString(result));

    ui->option1->setCheckable(false);
    ui->option2->setCheckable(false);
    ui->option3->setCheckable(false);
    ui->option4->setCheckable(false);
    ui->option1->setCheckable(true);
    ui->option2->setCheckable(true);
    ui->option3->setCheckable(true);
    ui->option4->setCheckable(true);
}
