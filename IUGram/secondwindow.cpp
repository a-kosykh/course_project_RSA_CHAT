#include "secondwindow.h"
#include "ui_secondwindow.h"
#include "iugram.h"

SecondWindow::SecondWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SecondWindow)
{
    ui->setupUi(this);
}

SecondWindow::~SecondWindow()
{
    delete ui;
}

// Кнопка IUGram на втором экране, которая ведет на страницу входа
void SecondWindow::on_pushButton_2_clicked()
{
    IUGram * firstwindow_ = new IUGram(this);
    QBrush br(Qt::TexturePattern);
    br.setTextureImage(QImage("/storage/emulated/0/DCIM/Camera/firstwindow.png"));
    QPalette plt = firstwindow_->palette();
    plt.setBrush(QPalette::Background, br);
    firstwindow_->setPalette(plt);
    this->close();
    firstwindow_->show();
}

// Кнопка найти - лупа
void SecondWindow::on_pushButton_clicked()
{

}
