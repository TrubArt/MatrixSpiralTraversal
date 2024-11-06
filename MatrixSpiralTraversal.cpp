#include "stdafx.h"
#include "MatrixSpiralTraversal.h"

MatrixSpiralTraversal::MatrixSpiralTraversal(QWidget *parent)
    : QMainWindow(parent)
    , m_Matrix()
    , m_Alg()
{
    ui.setupUi(this);
    connect(ui.start, &QPushButton::clicked, this, &MatrixSpiralTraversal::ClickButtonHandler);
    connect(ui.cancel, &QPushButton::clicked, &m_Alg, &SpiralTraversalAlgorithm::StopThreadExecution);
    connect(&m_Alg, &SpiralTraversalAlgorithm::goodBlockFound, this, [this](const QString& string)
        {
            ui.plainTextEdit->appendPlainText(string);
        });
    connect(ui.plainTextEdit, &QPlainTextEdit::textChanged, this, [this]()
        {
            m_Alg.Wake();
        });
    connect(&m_Alg, &SpiralTraversalAlgorithm::finished, this, [this]()
        {
            if (m_Alg.GetStopStatus() == true)
            {
                ui.plainTextEdit->clear();
                ui.plainTextEdit->appendPlainText("Execution was stopped");
            }
            EnableActiveButtons();
        });
}

MatrixSpiralTraversal::~MatrixSpiralTraversal()
{}

void MatrixSpiralTraversal::DisenableActiveButtons()
{
    ui.start->setDisabled(true);
    ui.rowSize->setDisabled(true);
    ui.columnSize->setDisabled(true);
}

void MatrixSpiralTraversal::EnableActiveButtons()
{
    ui.start->setDisabled(false);
    ui.rowSize->setDisabled(false);
    ui.columnSize->setDisabled(false);
}

void MatrixSpiralTraversal::ClickButtonHandler()
{
    ui.plainTextEdit->clear();

    // set m_Matrix sizes
    m_Matrix.SetRowSize(ui.rowSize->value());
    m_Matrix.SetColumnSize(ui.columnSize->value());
    
    m_Alg.SetMatrix(m_Matrix);
    DisenableActiveButtons();
    m_Alg.start();
}