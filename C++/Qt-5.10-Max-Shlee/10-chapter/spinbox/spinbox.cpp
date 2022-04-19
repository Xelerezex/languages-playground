#include <QtWidgets>

int main(int argc, char** argv)
{
    QApplication app(argc, argv);
    QSpinBox     spb;

    spb.setRange(1, 100);
    spb.setSuffix(" MB");
    spb.setButtonSymbols(QSpinBox::PlusMinus);
    spb.setWrapping(true);
    spb.show();
    spb.resize(100, 30);

    QApplication::setStyle("Ubuntu");
    return app.exec();
}
