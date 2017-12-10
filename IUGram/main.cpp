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
    IUGram firstwindow;
    // Первое окно с регистрацией/входом
    QApplication a(argc, argv);
    QBrush br(Qt::TexturePattern);
    // Кладем фото в background (допилить так, чтобы фото можно было предварительно не загружать на телефон)
    br.setTextureImage(QImage("/storage/emulated/0/DCIM/Camera/firstwindow.png"));
    QPalette plt = firstwindow.palette();
    plt.setBrush(QPalette::Background, br);
    firstwindow.setPalette(plt);

#if defined(Q_WS_S60)
    firstwindow.showMaximized();
#else
    firstwindow.show();
#endif

    return a.exec();
}
