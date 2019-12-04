#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "FiguresScene.h"
#include "FiguresSceneMDI.h"

#include <QMdiSubWindow>
#include <QMdiArea>
#include <QGraphicsView>
#include <QFileDialog>

#include <iostream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Лабораторная №2");
    auto newWindow = new FiguresSceneMdi(ui->mdiArea);
    auto newFiguresScene = ui->mdiArea->addSubWindow(newWindow);
    newFiguresScene->setWindowTitle("Сцена");
}

FiguresScene *MainWindow::getCurrentScene() {
    auto currentSubwindow = ui->mdiArea->currentSubWindow();
    if (currentSubwindow) {
        auto currentScene = currentSubwindow->widget();
        auto currentWindow = dynamic_cast<FiguresSceneMdi*>(currentScene);

        return currentWindow->figureScene;
    } else {
        return nullptr;
    }
}
QList<FiguresScene *> MainWindow::getAllScenes() {
    auto scenes = ui->mdiArea->subWindowList();
    QList<FiguresScene*> result;

    for (auto scene : scenes) {
        auto scene_as_widget = scene->widget();
        auto shape_scene_mdi_window = dynamic_cast<FiguresSceneMdi*>(scene_as_widget);

        result.push_back(shape_scene_mdi_window->figureScene);
    }

    return result;
}

MainWindow::~MainWindow()
{
    delete ui;
}

std::string get_figure_type(int index){
    switch (index) {
    case 0:
        return "circle";
    case 1:
        return "ellipse";
    case 2:
        return "text";
    case 3:
        return "textInEllipse";
    }
    throw std::logic_error("unknown object");
}

void MainWindow::setEnabledFields(const std::string &figure) {
    if (figure == std::string("circle"))
    {
        ui->radius_1->setEnabled(true);
        ui->radius_2->setEnabled(false);
        ui->lineEditText->setEnabled(false);
        ui->fontSize->setEnabled(false);
    }
    else if (figure == std::string("ellipse"))
    {
        ui->radius_1->setEnabled(true);
        ui->radius_2->setEnabled(true);
        ui->lineEditText->setEnabled(false);
        ui->fontSize->setEnabled(false);
    }
    else if (figure == std::string("text"))
    {
        ui->radius_1->setEnabled(false);
        ui->radius_2->setEnabled(false);
        ui->lineEditText->setEnabled(true);
        ui->fontSize->setEnabled(true);
    }
    else if (figure == std::string("textInEllipse"))
    {
        ui->radius_1->setEnabled(true);
        ui->radius_2->setEnabled(true);
        ui->lineEditText->setEnabled(true);
        ui->fontSize->setEnabled(true);
    }
    else
        throw std::logic_error("unknown object");

}

void MainWindow::on_chooseObject_currentIndexChanged(int index){

    auto scenes = getAllScenes();
    auto figure = get_figure_type(index);
    setEnabledFields(figure);

    for (auto scene : scenes)
        scene->setFigureType(QString::fromStdString(figure));
}

void MainWindow::on_radius_1_textChanged(const QString &arg1){
    auto scenes = getAllScenes();
    for (auto scene : scenes) {
        scene->setFigureRadius1(arg1.toInt());
    }
}

void MainWindow::on_radius_2_textChanged(const QString &arg1){
    auto scenes = getAllScenes();
    for (auto scene : scenes) {
        scene->setFigureRadius2(arg1.toInt());
    }
}

void MainWindow::on_lineEditText_textChanged(const QString &arg1)
{
    auto scenes = getAllScenes();
    for (auto scene : scenes) {
        scene->setFigureText(arg1);
    }
}

void MainWindow::on_fontSize_textChanged(const QString &arg1){
    auto scenes = getAllScenes();
    for (auto scene : scenes) {
        scene->setFigureFontSize(arg1.toInt());
    }
}

void MainWindow::on_deleteButton_clicked()
{
    auto scene = getCurrentScene();
    scene->popFigure();
}

void MainWindow::on_newSceneButton_clicked()
{
    auto newWindow = new FiguresSceneMdi(ui->mdiArea);
    auto newFiguresScene = ui->mdiArea->addSubWindow(newWindow);
    newFiguresScene->setWindowTitle("Сцена");

    std::string figure = get_figure_type(ui->chooseObject->currentIndex());
    newWindow->figureScene->setFigureType(QString::fromStdString(figure));

    newWindow->figureScene->setFigureRadius1(ui->radius_1->displayText().toInt());
    newWindow->figureScene->setFigureRadius2(ui->radius_2->displayText().toInt());
    newWindow->figureScene->setFigureText(ui->lineEditText->displayText());
    newWindow->figureScene->setFigureFontSize(ui->fontSize->displayText().toInt());
    setEnabledFields(figure);

    newWindow->show();
}

void MainWindow::on_openAction_triggered()
{
    auto currentScene = getCurrentScene();
        if (!currentScene) {
            return;
        }

        auto file_name = QFileDialog::getOpenFileName(this, "Открыть из файла", QString(), "Text File(*.txt)");

        if (file_name.isEmpty()) {
            return;
        }

        QFile file(file_name);

        if (file.open(QIODevice::ReadOnly)) {
            QDataStream input(&file);
            currentScene->deserialize(input);
        }
        file.close();
}

void MainWindow::on_clearScene_clicked(){
    auto currentScene = getCurrentScene();
    currentScene->clearSFiguresScene();
}
void MainWindow::on_saveAction_triggered()
{
    auto currentScene = getCurrentScene();
        if (!currentScene) {
            return;
        }

        auto file_name = QFileDialog::getSaveFileName(this, "Сохранить в файл", QString(), "Text File(*.txt)");

        if (file_name.isEmpty()) {
            return;
        }

        QFile file(file_name);

        if (file.open(QIODevice::WriteOnly)) {
            QDataStream output(&file);
            currentScene->serialize(output);
        }

        file.close();
}
