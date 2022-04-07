#include <QtCore>
#include <QtAlgorithms>
#include <QDebug>
#include <QtGlobal>
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

    qDebug() << "\n==================QT Strings===========================";
    {
        {
            QString str = "Lo";
            Q_ASSERT(str == "Lo");
            Q_ASSERT(str != "LO");
        }
        {
            QString str1 = "";
            QString str2;
            Q_ASSERT(str1.isNull() == false);
            Q_ASSERT(str2.isNull() == true);
        }
        {
            QString str1 = "Lo";
            QString str2 = "stris";
            qDebug() << str1 + str2;
        }
        {
            QString str1 = QString::number(178.225858);;
            qDebug() << str1 + " This is string";
        }
    }
    qDebug() << "\n==================QT QVariant===========================";
    {
        QVariant v2(23.03d);
        qDebug() << QVariant::typeToName(v2.type());
    }
}
