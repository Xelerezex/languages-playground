#include <QtWidgets>
#include "Progress.h"
//-----------------------------------------------------------------------------//


//-----------------------------------------------------------------------------//
Progress::Progress(QWidget* pwgt /*= 0*/)
    : QWidget(pwgt)
    , m_nStep(0)
{
    m_pprb = new QProgressBar;
    m_pprb->setRange(0, 5);
    m_pprb->setMinimumWidth(200);
    m_pprb->setAlignment(Qt::AlignCenter);

    QPushButton* pcmdStep  = new QPushButton("&Step");
    QPushButton* pcmdUnStep  = new QPushButton("&UnStep");
    QPushButton* pcmdReset = new QPushButton("&Reset");

    QObject::connect(pcmdStep, SIGNAL(clicked()), SLOT(slotStep()));
    QObject::connect(pcmdUnStep, SIGNAL(clicked()), SLOT(slotUnStep()));
    QObject::connect(pcmdReset, SIGNAL(clicked()), SLOT(slotReset()));

    QHBoxLayout* phbxLayout = new QHBoxLayout;
    phbxLayout->addWidget(m_pprb);
    phbxLayout->addWidget(pcmdStep);
    phbxLayout->addWidget(pcmdUnStep);
    phbxLayout->addWidget(pcmdReset);
    setLayout(phbxLayout);
}
//-----------------------------------------------------------------------------//


//-----------------------------------------------------------------------------//
void Progress::slotStep()
{
    m_pprb->setValue(++m_nStep);
}
//-----------------------------------------------------------------------------//


//-----------------------------------------------------------------------------//
void Progress::slotUnStep()
{
    m_pprb->setValue(--m_nStep);
}
//-----------------------------------------------------------------------------//


//-----------------------------------------------------------------------------//
void Progress::slotReset()
{
    m_nStep = 0;
    m_pprb->reset();
}
//-----------------------------------------------------------------------------//
