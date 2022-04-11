#include <QtWidgets>

int main(int argc, char** argv)
{
    QApplication app(argc, argv);
    QPixmap      pix;
    pix.load("/home/person/Документы/__repo__/languages-playground/C++/Qt-5.10-Max-Shlee/07-chapter/el-of-labels/f4d.jpg");

    QLabel lbl;
    lbl.resize(pix.size());
    lbl.setPixmap(pix);

    lbl.show();

    return app.exec();
}
