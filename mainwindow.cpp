#include "mainwindow.h"
#include "ui_mainwindow.h"

/**
 * @brief Creates the home page
 * @param model
 * @param parent
 */
MainWindow::MainWindow(Model &model, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    Setup(model);

    connect(&model, &Model::ShowHomeScreen, this, &MainWindow::ShowHomeScreen);

    connect(this, &MainWindow::SaveFile, &model, &Model::SaveFile);

    connect(this, &MainWindow::OpenFile, &model, &Model::OpenFile);
}



/**
 * @brief Destrucrts the home page
 */
MainWindow::~MainWindow()
{
    delete ui;
}

/**
 * @brief Sets up the QStacked widgets and the Homescreen
 * @param model
 */
void MainWindow::Setup(Model &model){
    BounceLabel();
    PlaybookLabel();

    //Creating stacked pages
    stackedPages = new QStackedWidget;
    stackedPages->addWidget(this);

    //Adding create page
    CreatePage* createPage = new CreatePage(model, nullptr);
    stackedPages->addWidget(createPage);

    //Adding study page
    studyPage = new StudyPage(model, nullptr);
    stackedPages->addWidget(studyPage);

    //Adding test page
    testPage = new TestPage(model, nullptr);
    stackedPages->addWidget(testPage);

    //Showing stacked pages with mainwindow at front
    stackedPages->show();
}

/**
 * @brief Box2D of a football that bounces around
 */
void MainWindow::BounceLabel() {
    box.continueBounce();
    ui->ballLabel->setGeometry(box.getX(), box.getY(), 100, 100);
    this->repaint();
    QTimer t;
    if (onHomePage) {
        t.singleShot(17, this, SLOT(BounceLabel()));
    }
}

/**
 * @brief Adds effects to the playbook label
 */
void MainWindow::PlaybookLabel() {
    QGraphicsDropShadowEffect *eff = new QGraphicsDropShadowEffect(this);
    eff->setOffset(0, 0);
    eff->setBlurRadius(150.0);
    eff->setColor(Qt::white);
    ui->playbookLabel->setGraphicsEffect(eff);
}

/**
 * @brief Create button clicked
 */
void MainWindow::on_createButton_clicked()
{
    auto* createPage = stackedPages->widget(1);
    stackedPages->setCurrentWidget(createPage);
    onHomePage = false;
}

/**
 * @brief Study button clicked
 */
void MainWindow::on_studyButton_clicked()
{
    auto* studyPageWidget = stackedPages->widget(2);
    studyPage->Refresh();
    stackedPages->setCurrentWidget(studyPageWidget);
    onHomePage = false;
}

/**
 * @brief Test button clicked
 */
void MainWindow::on_testButton_clicked()
{
    auto* testPageWidget = stackedPages->widget(3);
    testPage->Refresh();
    stackedPages->setCurrentWidget(testPageWidget);
    onHomePage = false;
}

/**
 * @brief Save button clicked
 */
void MainWindow::on_saveButton_clicked()
{
    QString filename = QFileDialog::getSaveFileName(this, "", "", "Football Play Book (*.fbpb)");
    emit SaveFile(filename);
}

/**
 * @brief Load button clicked
 */
void MainWindow::on_loadButton_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this, "", "", "Football Play Book (*.fbpb)");
    emit OpenFile(filename);
}

/**
 * @brief Shows the home screen
 */
void MainWindow::ShowHomeScreen(){
    auto* homePage = stackedPages->widget(0);
    stackedPages->setCurrentWidget(homePage);
    onHomePage = true;
    BounceLabel();
}

