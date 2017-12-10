#include "iugram.h"
#include "ui_iugram.h"

QString new_user;

IUGram::IUGram(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::IUGram)
{
    ui->setupUi(this);
    ui->pushButton->setStyleSheet("*{background-color: rgb(141, 252, 175); border: rgb(141, 252, 175);}");
    ui->pushButton_2->setStyleSheet("*{background-color: rgb(141, 252, 175); border: rgb(141, 252, 175);}");
}

IUGram::~IUGram()
{
    delete ui;
}


void IUGram::on_pushButton_clicked() // ������ ����
{
    // ��������� ������ ������������������ ������ (���������� ��������)
    list_of_users.push_back("Alex");
    list_of_users.push_back("Sasha");

    new_user = ui->lineEdit->text();
    if (qFind(list_of_users.begin(), list_of_users.end(), new_user) != list_of_users.end())
    {
        QString temp = "����� ����������,";
        temp += new_user;
        temp += "!";
        ui->lineEdit->setText(temp);
    }
    else
    {
        QString temp = "������������ ";
        temp += new_user;
        temp += " �� ����������!";
        ui->lineEdit->setText(temp);
    }
}
