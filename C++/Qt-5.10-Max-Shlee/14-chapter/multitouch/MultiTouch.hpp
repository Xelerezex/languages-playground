#pragma once

// ----------------------------------------------------------------------
#include <QtWidgets>
// ----------------------------------------------------------------------


// ----------------------------------------------------------------------
class MultiTouch : public QWidget
{
    public:
        MultiTouch (QWidget* pwgt = nullptr);

    protected:
        virtual void paintEvent (QPaintEvent*);
        virtual bool event      (QEvent*     );

    private:
        QList<QColor>                  m_lstCols;
        QList<QTouchEvent::TouchPoint> m_lstTps;
};
// ----------------------------------------------------------------------
