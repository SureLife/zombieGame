#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>
#include <sstream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    gmap.fillMap();
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()),this,SLOT(myfunction()));
    ui->setupUi(this);
    displayRoom();
    roomCheck(gmap.getDoorStates());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::displayRoom()
{
    QPixmap pixmapTarget(":/images/images/Room.png");
    int w = ui->roomPic->width();
    int h = ui->roomPic->height();
    ui->roomPic->setPixmap(pixmapTarget.scaled(w,h,Qt::KeepAspectRatio));

    QPixmap pix1(":/images/images/DoorN.png");
    QIcon icon1(pix1);
    ui->doorN->setIcon(icon1);
    ui->doorN->setIconSize(pix1.size());

    QPixmap pix2(":/images/images/DoorS.png");
    QIcon icon2(pix2);
    ui->doorS->setIcon(icon2);
    ui->doorS->setIconSize(pix2.size());

    QPixmap pix3(":/images/images/DoorW.png");
    QIcon icon3(pix3);
    ui->doorW->setIcon(icon3);
    ui->doorW->setIconSize(pix3.size());

    QPixmap pix4(":/images/images/DoorE.png");
    QIcon icon4(pix4);
    ui->doorE->setIcon(icon4);
    ui->doorE->setIconSize(pix4.size());

    QPixmap pix5(":/images/images/chest1.png");
    QIcon icon5(pix5);
    ui->chest1->setIcon(icon5);
    ui->chest1->setIconSize(pix5.size());

    QPixmap pix6(":/images/images/zombie.png");
    QIcon icon6(pix6);
    ui->zombie->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ui->zombie->setIcon(icon6);
    ui->zombie->setIconSize(pix6.size());

    QPixmap pix7(":/images/images/beans.png");
    QIcon icon7(pix7);
    ui->beans->setIcon(icon7);
    ui->beans->setIconSize(pix7.size());

    QPixmap pix8(":/images/images/water.png");
    QIcon icon8(pix8);
    ui->water->setIcon(icon8);
    ui->water->setIconSize(pix8.size());

    QPixmap pix9(":/images/images/Fist.png");
    QIcon icon9(pix9);
    ui->Fist->setIcon(icon9);
    ui->Fist->setIconSize(pix9.size());

    QPixmap pix10(":/images/images/knife.png");
    QIcon icon10(pix10);
    ui->knife->setIcon(icon10);
    ui->knife->setIconSize(pix10.size());

    QPixmap pix11(":/images/images/pistol.png");
    QIcon icon11(pix11);
    ui->pistol->setIcon(icon11);
    ui->pistol->setIconSize(pix11.size());

    QPixmap pix12(":/images/images/rifle.png");
    QIcon icon12(pix12);
    ui->rifle->setIcon(icon12);
    ui->rifle->setIconSize(pix12.size());

    QPixmap pix13(":/images/images/exitDoor.png");
    QIcon icon13(pix13);
    ui->zombie->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ui->exitDoor->setIcon(icon13);
    ui->exitDoor->setIconSize(pix13.size());

}

void MainWindow::roomCheck(string temp)
{
    //cout << "\n" << temp;
    string doorStates[4];
    int i = 0;
    stringstream ssin(temp);
    while (ssin.good() && i < 4){
        ssin >> doorStates[i];
        ++i;
    }
    if (player.getHealth() > 100)
        player.changeHealth(-(player.getHealth()-100));
    if (player.getHealth() <= 0)
        loseGame = true;

    string health = "Health: " + to_string(player.getHealth());
    ui->health->setText(QString::fromStdString(health + "/100"));

    if (stoi(doorStates[0]) == 1) ui->doorN->setVisible(true);
    else ui->doorN->setVisible(false);
    if (stoi(doorStates[1]) == 1) ui->doorE->setVisible(true);
    else ui->doorE->setVisible(false);
    if (stoi(doorStates[2]) == 1) ui->doorS->setVisible(true);
    else ui->doorS->setVisible(false);
    if (stoi(doorStates[3]) == 1) ui->doorW->setVisible(true);
    else ui->doorW->setVisible(false);
    //cout << gmap.getCurrentRoom()->shortDescription();
    if (gmap.getCurrentRoom()->checkForContainer() == true) ui->chest1->setVisible(true);
    else ui->chest1->setVisible(false);

    if(gmap.getCurrentRoom()->zombieCheck())
    {
        clickable = false;
        ui->zombie->setVisible(true);
    }

    else
    {
        clickable = true;
        ui->zombie->setVisible(false);
    }

    if(player.hasWater())
        ui->noWater->setVisible(false);
    else ui->noWater->setVisible(true);

    if(player.hasBeans())
        ui->nobeans->setVisible(false);
    else ui->nobeans->setVisible(true);

    if(combat)
    {
        ui->Fist->setVisible(true);
        ui->knife->setVisible(true);
        ui->pistol->setVisible(true);
        ui->rifle->setVisible(true);
        if(player.hasKnife())
            ui->noknife->setVisible(false);
        else ui->noknife->setVisible(true);
        if(player.hasPistol())
            ui->nopistol->setVisible(false);
        else ui->nopistol->setVisible(true);
        if(player.hasRifle())
            ui->norifle->setVisible(false);
        else ui->norifle->setVisible(true);
    }
    else
    {
        ui->Fist->setVisible(false);
        ui->knife->setVisible(false);
        ui->pistol->setVisible(false);
        ui->rifle->setVisible(false);
        ui->noknife->setVisible(false);
        ui->nopistol->setVisible(false);
        ui->norifle->setVisible(false);
    }

    if (gmap.getCurrentRoom()->deadZombieCheck())
        ui->deadZombie->setVisible(true);
    else ui->deadZombie->setVisible(false);

    if (gmap.getCurrentRoom()->checkFinalRoom())
        ui->exitDoor->setVisible(true);
    else ui->exitDoor->setVisible(false);

    if(loseGame)
        ui->loseScreen->setVisible(true);
    else ui->loseScreen->setVisible(false);

    if(winGame)
        ui->winScreen->setVisible(true);
    else ui->winScreen->setVisible(false);

}

void MainWindow::on_doorN_clicked()
{
    if(clickable)
    {
        gmap.changeRoom(1);
    }
    else {
        message += "You cannot leave yet. Kill the zombie!";
        timercount = 0;
        timer->start(1000);
    }
    roomCheck(gmap.getDoorStates());
}

void MainWindow::on_doorE_clicked()
{
    if(clickable)
    {
        gmap.changeRoom(2);
    }
    else {
        message += "You cannot leave yet. Kill the zombie!";
        timercount = 0;
        timer->start(1000);
    }
    roomCheck(gmap.getDoorStates());
}

void MainWindow::on_doorS_clicked()
{
    if(clickable)
    {
        gmap.changeRoom(3);
    }
    else {
        message += "You cannot leave yet. Kill the zombie!";
        timercount = 0;
        timer->start(1000);
    }
    roomCheck(gmap.getDoorStates());
}

void MainWindow::on_doorW_clicked()
{
    if(clickable)
    {
        gmap.changeRoom(4);
    }
    else {
        message += "You cannot leave yet. Kill the zombie!";
        timercount = 0;
        timer->start(1000);
    }
    roomCheck(gmap.getDoorStates());
}


void MainWindow::on_chest1_clicked()
{
    vector<Item> temp = gmap.getCurrentRoom()->getContainerContent();
    if(temp.size() == 0) message = "Container empty\n";
    else
        for(int i = 0; i < temp.size(); i++)
        {
            message += "Looted " + temp[i].getShortDescription() + "\n";
            player.addItem(temp[i]);
        }
    timercount = 0;
    timer->start(1000);
    gmap.getCurrentRoom()->clearChest();
    roomCheck(gmap.getDoorStates());

}
void MainWindow::myfunction()
{
    ui->label->setText(QString::fromStdString(message));
    timercount++;
    if (timercount == 6)
    {
        message = "";
        ui->label->setText("");
        timercount = 0;
        timer->stop();
    }
}
void MainWindow::on_water_clicked()
{
    player.changeHealth(5);
    player.useWater();
    roomCheck(gmap.getDoorStates());
}

void MainWindow::on_beans_clicked()
{
    player.changeHealth(15);
    player.useBeans();
    roomCheck(gmap.getDoorStates());
}

void MainWindow::on_Fist_clicked()
{
    clickable = true;
    combat = false;
    player.changeHealth(-45);
    gmap.getCurrentRoom()->clearZombie();
    gmap.getCurrentRoom()->setDeadZombie(true);
    roomCheck(gmap.getDoorStates());
}

void MainWindow::on_knife_clicked()
{
    clickable = true;
    combat = false;
    player.changeHealth(-25);
    player.useKnife();
    gmap.getCurrentRoom()->clearZombie();
    gmap.getCurrentRoom()->setDeadZombie(true);
    roomCheck(gmap.getDoorStates());
}

void MainWindow::on_pistol_clicked()
{
    clickable = true;
    combat = false;
    player.changeHealth(-5);
    player.usePistol();
    gmap.getCurrentRoom()->clearZombie();
    gmap.getCurrentRoom()->setDeadZombie(true);
    roomCheck(gmap.getDoorStates());
}

void MainWindow::on_zombie_clicked()
{
    combat = true;
    roomCheck(gmap.getDoorStates());
}

void MainWindow::on_exitDoor_clicked()
{
    winGame = true;
    roomCheck(gmap.getDoorStates());
}

void MainWindow::on_rifle_clicked()
{
    clickable = true;
    combat = false;
    player.useRifle();
    gmap.getCurrentRoom()->clearZombie();
    gmap.getCurrentRoom()->setDeadZombie(true);
    roomCheck(gmap.getDoorStates());
}
