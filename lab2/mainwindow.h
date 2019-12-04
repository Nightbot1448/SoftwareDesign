#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QList>
#include "FiguresScene.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_chooseObject_currentIndexChanged(int index);

    void on_lineEditText_textChanged(const QString &arg1);
    void on_fontSize_textChanged(const QString &arg1);

    void on_radius_1_textChanged(const QString &arg1);
    void on_radius_2_textChanged(const QString &arg1);

    void on_deleteButton_clicked();
    void on_clearScene_clicked();
    void on_newSceneButton_clicked();
    void on_openAction_triggered();
    void on_saveAction_triggered();

private:

    void setEnabledFields(const std::string &figure);

    Ui::MainWindow *ui;
    FiguresScene* getCurrentScene();
    QList<FiguresScene*> getAllScenes();
};
#endif // MAINWINDOW_H
