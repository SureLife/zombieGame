#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QObject>
#include <QTimer>
#include "Character.h"
#include <string>
#include "zombieGame.h"
#include "gameMap.h"
using namespace std;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void displayRoom();
    gameMap gmap;

private slots:

    void on_doorE_clicked();

    void on_doorS_clicked();

    void on_doorW_clicked();

    void on_doorN_clicked();

    void on_chest1_clicked();

    void myfunction();

    void on_water_clicked();

    void on_beans_clicked();

    void on_knife_clicked();

    void on_pistol_clicked();

    void on_zombie_clicked();

    void on_Fist_clicked();

    void on_exitDoor_clicked();

    void on_rifle_clicked();

private:
    Character player;

    Ui::MainWindow *ui;
    void roomCheck(string);
    bool clickable = true;
    QTimer *timer;
    string message;
    int timercount = 0;
    bool combat = false;
    bool winGame = false;
    bool loseGame = false;
};

#endif // MAINWINDOW_H
