#include <QtWidgets>

int main(int argc, char** argv)
{
    QApplication app(argc, argv);
    QWidget      wgt;

    QWidget* pwgt1 = new QWidget(&wgt);
    QPalette pal1;

    pal1.setColor(pwgt1->backgroundRole(), Qt::red);

    pwgt1->setPalette(pal1);
    pwgt1->resize(150, 150);
    pwgt1->move(5, 5);
    pwgt1->setAutoFillBackground(true);

    QWidget* pwgt2 = new QWidget(&wgt);
    QPalette pal2;


    QPixmap pic("/home/person/Документы/__repo__/languages-playground/C++/Qt-5.10-Max-Shlee/05-chapter/upper-widget/f4d.jpg");
    pal2.setBrush(pwgt2->backgroundRole(), QBrush(pic));

    pwgt2->setPalette(pal2);
    // pwgt2->setPixmap(pic(150, 150, Qt::KeepAspectRatio));
    pwgt2->resize(150, 150);
    pwgt2->move(30, 30);
    pwgt2->setAutoFillBackground(true);

    pwgt2->setCursor(QCursor(Qt::ForbiddenCursor));

    wgt.resize(200, 200);
    wgt.show();

    return app.exec();
}
