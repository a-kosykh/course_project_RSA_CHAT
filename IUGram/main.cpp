#include <QtGui/QApplication>
#include <QtGui>
#include "iugram.h"
#include <QTextCodec>

int main(int argc, char *argv[])
{
    // Смена кодировки для чтения не только латинских, но и русских букв
    QTextCodec *cyrillicCodec = QTextCodec::codecForName("Windows-1251");
    QTextCodec::setCodecForTr(cyrillicCodec);
    QTextCodec::setCodecForLocale(cyrillicCodec);
    QTextCodec::setCodecForCStrings(cyrillicCodec);
    // Первое окно с регистрацией/входом
    QApplication a(argc, argv);
    IUGram firstwindow;
    QBrush br(Qt::TexturePattern);
    // Кладем фото в background (допилить так, чтобы фото можно было предварительно не загружать на телефон)
    br.setTextureImage(QImage("/storage/emulated/0/DCIM/Camera/firstwindow.png"));
    QPalette plt = firstwindow.palette();
    plt.setBrush(QPalette::Background, br);
    firstwindow.setPalette(plt);

#if defined(Q_WS_S60)
    firstwindow.showMaximized();
#else
    // example of adding background image in Qt 5.10.1 (can't check in older versions)
    // 1. project --> add file --> Qt Resources
    // 2. add any prefix
    // 3. click add file and choose file in source directory
    // 4. now you can access to file with prefix
    // 5. file will be also compiled into APK after build

    // firstwindow.setStyleSheet("background-image:url(:/resources/images/back.png)");

    firstwindow.show();
#endif

    return a.exec();
}
