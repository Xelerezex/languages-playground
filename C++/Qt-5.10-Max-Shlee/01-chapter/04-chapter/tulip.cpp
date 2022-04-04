#include <QtCore>
#include <QtAlgorithms>
#include <algorithm>

int main()
{
    qDebug() << "\n===============Java-styled iterators===================";
    {
        {
            QList<QString> list;
            list << "Within Temptation" << "Anubis" << "Mantus";

            // it -> [*][first elem] (before first)
            QListIterator<QString> it(list);                      // Non-Mutable
            while (it.hasNext())
            {
                qDebug() << "Element:" << it.next();
            }
        }

        qDebug() << "=======================================================";
        {
            QList<QString> list;
            list << "Beatles" << "ABBA" << "Boney M";
            QMutableListIterator<QString> it(list);
            while (it.hasNext())
            {
                if (it.next() == "Boney M")
                {
                    it.setValue("Rolling Stones");
                }
                qDebug() << "Element:" << it.peekPrevious();
            }
        }
    }

    qDebug() << "\n================STL-styled iterators===================";
    {
        {
            QVector<QString> vec;
            vec << "In Extremo" << "Blackmore's Night" << "Cultus Ferox";
            QVector<QString>::iterator it = vec.begin();

            for (; it != vec.end(); ++it)
            {
                qDebug() << "Element:" << *it;
            }

            qDebug() << "=======================================================";
            QVector<QString>::iterator it2 = vec.end();

            for (; it2 != vec.begin(); )
            {
                --it2;
                qDebug() << "Element:" << *it2;
            }
        }

        qDebug() << "=======================================================";
        {
            QVector<QString> vec;
            vec << "In Extremo" << "Blackmore's Night" << "Cultus Ferox";
            QVector<QString>::const_iterator it = vec.constBegin();

            for (; it != vec.constEnd(); ++it)
            {
                qDebug() << "Element:" << *it;
            }
        }
    }

    qDebug() << "\n================STL Algorithms=========================";
    {
        QVector<QString> vec;
        vec << "In Extremo" << "Blackmore's Night" << "Cultus Ferox";
        std::sort(vec.begin(), vec.end());

        qDebug() << vec;
    }

    qDebug() << "\n==================foreach==============================";
    {
        QList<QString> list;
        list << "Subway to sally" << "Rammstein" << "After Forever";
        foreach(QString str, list)      // Always copying container, there'll be no chanchings
        {
            qDebug() << "Element: " << str;
        }
    }
}
