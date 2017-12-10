#ifndef IUGRAM_H
#define IUGRAM_H

#include <QMainWindow>
#include <QtAlgorithms>
#include <QString>
#include <QLinkedList>

static QLinkedList<QString> list_of_users;

namespace Ui {
    class IUGram;
}

class IUGram : public QMainWindow
{
    Q_OBJECT

public:
    explicit IUGram(QWidget *parent = 0);
    ~IUGram();

public slots:
    void on_pushButton_clicked();

public:
    Ui::IUGram *ui;
};

#endif // IUGRAM_H
