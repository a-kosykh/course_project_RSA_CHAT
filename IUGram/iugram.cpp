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

// Кнопка войти
void IUGram::on_pushButton_clicked()
{
    // Получение списка зарегестрированных юзеров (необходимо допилить)
    list_of_users.push_back("Alex");
    list_of_users.push_back("Sasha");

    // Считывание username-а
    new_user = ui->lineEdit->text();
    // Если username уже зарегистрирован
    if (qFind(list_of_users.begin(), list_of_users.end(), new_user) != list_of_users.end())
    {
        // Создание второго окна со списком сообщений
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
        // Сообение о том, что вход не удался, нужно зарегестрироваться
        QString temp = "Пользователя ";
        temp += new_user;
        temp += " не существует! Пожалуйста, зарегистрируйтесь.";
        QMessageBox::information(this, "Неудачная попытка входа", temp);
    }
}

// Кнопка зарегистрироваться
void IUGram::on_pushButton_2_clicked()
{
    // Получение списка зарегестрированных юзеров (необходимо допилить)
    list_of_users.push_back("Alex");
    list_of_users.push_back("Sasha");

    new_user = ui->lineEdit->text();

    if (qFind(list_of_users.begin(), list_of_users.end(), new_user) != list_of_users.end())
    {
        // Сообение о том, что регистрация не удался, так как пользователь с таким username-ом уже существует
        QString temp = "Пользователь с username: ";
        temp += new_user;
        temp += " уже существует! Пожалуйста, придумайте другое имя.";
        QMessageBox::information(this, "Неудачная попытка регистрации", temp);
        return;
    }

    // Добавляем новогоюзера
    list_of_users.push_back(new_user);
    // Создание второго окна со списком сообщений
    SecondWindow * secwnd = new SecondWindow(this);
    QBrush br(Qt::TexturePattern);
    br.setTextureImage(QImage("/storage/emulated/0/DCIM/Camera/secondwindow.png"));
    QPalette plt = secwnd->palette();
    plt.setBrush(QPalette::Background, br);
    secwnd->setPalette(plt);
    this->close();
    secwnd->show();
}

// Кнопка настройки - шестеренка
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
