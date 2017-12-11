#include "settings.h"
#include "ui_settings.h"
#include "iugram.h"

Settings::Settings(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Settings)
{
    ui->setupUi(this);
}

Settings::~Settings()
{
    delete ui;
}

// ������ ����� - ����� �� ������� �� ��������
void Settings::on_pushButton_2_clicked()
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

// ����� ��������� - ��������� ��������� ���� � ����
void Settings::on_pushButton_clicked()
{
    ip_addres = ui->lineEdit->text();
    port = ui->lineEdit_2->text();
}
