#include "stdafx.h"
#include "Pseudomatrix.h"

PseudoMatrix::PseudoMatrix(int rowSize, int columnSize) 
    : m_rowSize(rowSize)
    , m_columnSize(columnSize)
{}

void PseudoMatrix::SetRowSize(int rowSize)
{
    m_rowSize = rowSize;
}

void PseudoMatrix::SetColumnSize(int colSize)
{
    m_columnSize = colSize;
}

int PseudoMatrix::GetElement(int i, int j) const
{
    return i * m_columnSize + j + 1;
}

int PseudoMatrix::GetRowSize() const
{
    return m_rowSize;
}

int PseudoMatrix::GetColumnSize() const
{
    return m_columnSize;
}
