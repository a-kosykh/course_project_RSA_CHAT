#include "iugram.h"
#include "ui_iugram.h"
#include "secondwindow.h"
#include "settings.h"

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

// ������ �����
void IUGram::on_pushButton_clicked()
{
    // ��������� ������ ������������������ ������ (���������� ��������)
    list_of_users.push_back("Alex");
    list_of_users.push_back("Sasha");

    // ���������� username-�
    new_user = ui->lineEdit->text();
    // ���� username ��� ���������������
    if (qFind(list_of_users.begin(), list_of_users.end(), new_user) != list_of_users.end())
    {
        // �������� ������� ���� �� ������� ���������
        SecondWindow * secwnd = new SecondWindow(this);
        QBrush br(Qt::TexturePattern);
        br.setTextureImage(QImage("/storage/emulated/0/DCIM/Camera/secondwindow.png"));
        QPalette plt = secwnd->palette();
        plt.setBrush(QPalette::Background, br);
        secwnd->setPalette(plt);
        this->close();
        secwnd->show();
    }
    else
    {
        // �������� � ���, ��� ���� �� ������, ����� ������������������
        QString temp = "������������ ";
        temp += new_user;
        temp += " �� ����������! ����������, �����������������.";
        QMessageBox::information(this, "��������� ������� �����", temp);
    }
}

// ������ ������������������
void IUGram::on_pushButton_2_clicked()
{
    // ��������� ������ ������������������ ������ (���������� ��������)
    list_of_users.push_back("Alex");
    list_of_users.push_back("Sasha");

    new_user = ui->lineEdit->text();

    if (qFind(list_of_users.begin(), list_of_users.end(), new_user) != list_of_users.end())
    {
        // �������� � ���, ��� ����������� �� ������, ��� ��� ������������ � ����� username-�� ��� ����������
        QString temp = "������������ � username: ";
        temp += new_user;
        temp += " ��� ����������! ����������, ���������� ������ ���.";
        QMessageBox::information(this, "��������� ������� �����������", temp);
        return;
    }

    // ��������� �����������
    list_of_users.push_back(new_user);
    // �������� ������� ���� �� ������� ���������
    SecondWindow * secwnd = new SecondWindow(this);
    QBrush br(Qt::TexturePattern);
    br.setTextureImage(QImage("/storage/emulated/0/DCIM/Camera/secondwindow.png"));
    QPalette plt = secwnd->palette();
    plt.setBrush(QPalette::Background, br);
    secwnd->setPalette(plt);
    this->close();
    secwnd->show();
}

// ������ ��������� - ����������
void IUGram::on_pushButton_3_clicked()
{
    Settings * settingswindow = new Settings(this);
    QBrush br(Qt::TexturePattern);
    br.setTextureImage(QImage("/storage/emulated/0/DCIM/Camera/settingswindow.png"));
    QPalette plt = settingswindow->palette();
    plt.setBrush(QPalette::Background, br);
    settingswindow->setPalette(plt);
    this->close();
    settingswindow->show();
}
