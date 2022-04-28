#pragma once

// ----------------------------------------------------------------------
#include <QObject>
#include <QtWidgets>
// ----------------------------------------------------------------------


// ----------------------------------------------------------------------
class MouseFilter : public QObject
{
    protected:
        virtual bool eventFilter(QObject*, QEvent*);

    public:
        MouseFilter(QObject* pobj = nullptr);
};
// ----------------------------------------------------------------------
