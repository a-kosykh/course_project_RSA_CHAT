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

// Кнопка поиска собеседника - лупа
void SecondWindow::on_pushButton_clicked()
{
    ui->listWidget->addItem("Hello!");
}

// Кнопка выхода - крестик
void SecondWindow::on_pushButton_2_clicked()
{
    IUGram * first_window = new IUGram(this);
    this->close();
    first_window->show();
}
