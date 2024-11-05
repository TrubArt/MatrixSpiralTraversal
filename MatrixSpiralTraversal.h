#pragma once
#include <QtWidgets/QMainWindow>
#include "ui_MatrixSpiralTraversal.h"
#include "SpiralTraversalAlgorithm.h"
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
    /**
    * @brief Обработчик генерации матрицы
    */
    void ClickButtonHandler();

    Ui::MatrixSpiralTraversalClass ui;
    PseudoMatrix m_Matrix;
    SpiralTraversalAlgorithm m_Alg;
};
