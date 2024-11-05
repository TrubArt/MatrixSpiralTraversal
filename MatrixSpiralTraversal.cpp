#include "stdafx.h"
#include "MatrixSpiralTraversal.h"
#include <qfuture.h>
#include <qfuturewatcher.h>
#include <QtConcurrent/qtconcurrentrun.h>

MatrixSpiralTraversal::MatrixSpiralTraversal(QWidget *parent)
    : QMainWindow(parent)
    , m_Matrix()
{
    ui.setupUi(this);
    connect(ui.start, &QPushButton::clicked, this, &MatrixSpiralTraversal::ClickButtonHandler);
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
    // set m_Matrix sizes
    m_Matrix.SetRowSize(ui.rowSize->value());
    m_Matrix.SetColumnSize(ui.columnSize->value());

    DisenableActiveButtons();

    // Thread for optimization of calculations

    auto watcher = new QFutureWatcher<QString>(this);
    connect(watcher, &QFutureWatcher<QString>::finished, this, [this, watcher]()
    {
        ui.plainTextEdit->setPlainText(watcher->result());
        EnableActiveButtons();
        watcher->deleteLater();
    });

    QFuture<QString> future = QtConcurrent::run([this]() -> QString
    {
         return m_Matrix.SpiralTraversal();
    });
    watcher->setFuture(future);
}
