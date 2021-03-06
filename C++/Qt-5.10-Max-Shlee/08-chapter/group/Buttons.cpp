#include "Buttons.h"
//-----------------------------------------------------------------------------//


//-----------------------------------------------------------------------------//
Buttons::Buttons(QWidget* pwgt)
    : QGroupBox("QGroupBox", pwgt)
{
    resize(100, 150);
    setCheckable(true);

    m_pradRed   = new QRadioButton("&Red");
    m_pradGreen = new QRadioButton("&Green");
    m_pradBlue  = new QRadioButton("&Blue");
    m_pradGreen->setChecked(true);

    connect(m_pradRed, SIGNAL(clicked()),
            this,      SLOT(slotButtonClicked()));
    connect(m_pradGreen, SIGNAL(clicked()),
            this,        SLOT(slotButtonClicked()));
    connect(m_pradBlue, SIGNAL(clicked()),
            this,       SLOT(slotButtonClicked()));

    m_pchk = new QCheckBox("&Light");
    m_pchk->setChecked(true);
    connect(m_pchk, SIGNAL(clicked()),
            this,      SLOT(slotButtonClicked()));


    QPushButton* pcmd = new QPushButton("&Exit");
    connect(pcmd, SIGNAL(clicked()),
            qApp, SLOT(quit()));

    // Layout setup
    QVBoxLayout* pvbxLayout = new QVBoxLayout;
    pvbxLayout->addWidget(m_pradRed);
    pvbxLayout->addWidget(m_pradGreen);
    pvbxLayout->addWidget(m_pradBlue);
    pvbxLayout->addWidget(m_pchk);
    pvbxLayout->addWidget(pcmd);
    setLayout(pvbxLayout);

    slotButtonClicked();
}
//-----------------------------------------------------------------------------//


//-----------------------------------------------------------------------------//
void Buttons::slotButtonClicked()
{
    QPalette pal    = palette();
    int      nLight = m_pchk->isChecked() ? 150 : 80;

    if (m_pradRed->isChecked())
    {
        pal.setColor(backgroundRole(), QColor(Qt::red).light(nLight));
    }
    else if (m_pradGreen->isChecked())
    {
        pal.setColor(backgroundRole(), QColor(Qt::green).light(nLight));
    }
    else
    {
        pal.setColor(backgroundRole(), QColor(Qt::blue).light(nLight));
    }
    setPalette(pal);
}
