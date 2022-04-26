#include "ResizeObserver.hpp"
// ----------------------------------------------------------------------


// ----------------------------------------------------------------------
ResizeObserver::ResizeObserver(QWidget* pwgt)
    : QLabel(pwgt)
{
    setAlignment(Qt::AlignCenter);
}
// ----------------------------------------------------------------------


// ----------------------------------------------------------------------
void ResizeObserver::resizeEvent(QResizeEvent* pe)
{
    setText(QString("Resized")
            + "\n width() " + QString::number(pe->size().width())
            + "\n height() " + QString::number(pe->size().height())
           );
}
// ----------------------------------------------------------------------
