#include "stdafx.h"
#include "Pseudomatrix.h"

namespace
{
    int maxElementSize(int maxNumber)
    {
        return QString::number(maxNumber).size();
    }
}

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

QString PseudoMatrix::SpiralTraversal() const
{
    int elementsCount = m_rowSize * m_columnSize;
    int spaceCount = 1;
    int stringElementSize = maxElementSize(elementsCount) + spaceCount;

    QString answer;
    answer.reserve(stringElementSize * elementsCount);

    int rowStart = 0;
    int rowEnd = m_columnSize;
    int columnStart = 0;
    int columnEnd = m_rowSize;

    int currentIndex = 0;

    while (rowStart < rowEnd && columnStart < columnEnd)
    {
        for (currentIndex = columnStart; currentIndex < columnEnd; ++currentIndex)
        {
            answer.push_back(QString::number(GetElement(rowStart, currentIndex)) + " ");
        }
        rowStart += 1;

        for (currentIndex = rowStart; currentIndex < rowEnd; ++currentIndex)
        {
            answer.push_back(QString::number(GetElement(currentIndex, columnEnd - 1)) + " ");
        }
        columnEnd -= 1;

        if (rowStart < rowEnd)
        {
            for (currentIndex = columnEnd - 1; currentIndex >= columnStart; --currentIndex)
            {
                answer.push_back(QString::number(GetElement(rowEnd - 1, currentIndex)) + " ");
            }
            rowEnd -= 1;
        }

        if (columnStart < columnEnd)
        {
            for (currentIndex = rowEnd - 1; currentIndex >= rowStart; --currentIndex)
            {
                answer.push_back(QString::number(GetElement(currentIndex, columnStart)) + " ");
            }
            columnStart += 1;
        }
    }
    return answer;
}