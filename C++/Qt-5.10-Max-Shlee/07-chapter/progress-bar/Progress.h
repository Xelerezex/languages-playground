#pragma once

#include <QWidget>
// #include <QProgressBar>

class QProgressBar;

class Progress : public QWidget
{
    Q_OBJECT

    private:
        QProgressBar* m_pprb;
        int           m_nStep;

    public:
        Progress(QWidget* pobj = 0);

    public slots:
        void slotStep  ();
        void slotUnStep();
        void slotReset ();
};
