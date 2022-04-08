#include <QtWidgets>

int main(int argc, char** argv)
{
    QApplication app(argc, argv);
    QWidget      wgt;

    QPushButton* pcmdA = new QPushButton("A");
    QPushButton* pcmdB = new QPushButton("B");
    QPushButton* pcmdC = new QPushButton("C");
    QPushButton* pcmdD = new QPushButton("D");


    QHBoxLayout* phbxLayout = new QHBoxLayout;
    QVBoxLayout* pvbxLayout = new QVBoxLayout;

    phbxLayout->setContentsMargins(5, 5, 5, 5);
    phbxLayout->setSpacing(15);
    phbxLayout->addWidget(pcmdC);
    phbxLayout->addWidget(pcmdD);

    pvbxLayout->setContentsMargins(5, 5, 5, 5);
    pvbxLayout->setSpacing(15);
    pvbxLayout->addWidget(pcmdA);
    pvbxLayout->addWidget(pcmdB);
    pvbxLayout->addLayout(phbxLayout);

    wgt.setLayout(pvbxLayout);

    wgt.resize(450, 40);
    wgt.show();

    return app.exec();
}
