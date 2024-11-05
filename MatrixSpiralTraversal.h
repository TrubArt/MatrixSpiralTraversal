#pragma once
#include <QtWidgets/QMainWindow>
#include "ui_MatrixSpiralTraversal.h"
#include "Pseudomatrix.h"

class MatrixSpiralTraversal : public QMainWindow
{
    Q_OBJECT

public:
    explicit MatrixSpiralTraversal(QWidget *parent = nullptr);
    ~MatrixSpiralTraversal();

private:
    void DisenableActiveButtons();
    void EnableActiveButtons();
    void ClickButtonHandler();

    Ui::MatrixSpiralTraversalClass ui;
    PseudoMatrix m_Matrix;
};
