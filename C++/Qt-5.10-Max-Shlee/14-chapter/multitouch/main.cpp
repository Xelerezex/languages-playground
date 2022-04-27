#include "MultiTouch.hpp"
// ----------------------------------------------------------------------


// ----------------------------------------------------------------------
int main(int argc, char** argv)
{
    QApplication app(argc, argv);
    MultiTouch   wgt;

    wgt.resize(640, 480);
    wgt.show();

    return app.exec();
}
