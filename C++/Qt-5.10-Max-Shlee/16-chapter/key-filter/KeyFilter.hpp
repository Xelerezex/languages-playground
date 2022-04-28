#pragma once

#include <QtWidgets>

class KeyFilter : public QObject
{
    public:
        KeyFilter(QObject* pobj = nullptr)
            : QObject(pobj)
        {
        }

    protected:
        bool eventFilter(QObject* pobj, QEvent* pe)
        {
            if (pe->type() == QEvent::KeyPress)
            {
                if (((QKeyEvent*)pe)->key() == Qt::Key_Z)
                {
                    QKeyEvent keyEvent (QEvent::KeyPress,
                                        Qt::Key_A,
                                        Qt::NoModifier,
                                        "A");
                    QApplication::sendEvent(pobj, &keyEvent);
                    return true;
                }
            }
            return false;
        }
};
