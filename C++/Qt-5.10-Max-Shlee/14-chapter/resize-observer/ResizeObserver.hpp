#pragma once

// ----------------------------------------------------------------------
#include <QtWidgets>
// ----------------------------------------------------------------------


// ----------------------------------------------------------------------
class ResizeObserver : public QLabel
{
    public:
        ResizeObserver(QWidget* pwgt = nullptr);

    protected:
        virtual void resizeEvent(QResizeEvent* pe);
};
// ----------------------------------------------------------------------
