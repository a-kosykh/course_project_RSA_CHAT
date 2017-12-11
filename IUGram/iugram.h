#ifndef IUGRAM_H
#define IUGRAM_H

#include <QMainWindow>
#include <QtAlgorithms>
#include <QString>
#include <QLinkedList>
#include <QMessageBox>

static QLinkedList<QString> list_of_users;
static QString ip_addres;
static QString port;

namespace Ui {
    class IUGram;
}

class IUGram : public QMainWindow
{
    Q_OBJECT

public:
    explicit IUGram(QWidget *parent = 0);
    ~IUGram();
//    void read_login(Ui::IUGram *);

public:
    Ui::IUGram* ui;

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
};

#endif // IUGRAM_H
