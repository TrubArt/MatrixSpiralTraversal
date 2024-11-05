#include "stdafx.h"
#include "SpiralTraversalAlgorithm.h"

namespace
{
    int maxElementSize(int maxNumber)
    {
        return QString::number(maxNumber).size();
    }
}

SpiralTraversalAlgorithm::SpiralTraversalAlgorithm(QObject* parent)
	: QThread(parent)
	, m_Matrix()
{}

void SpiralTraversalAlgorithm::SetMatrix(const PseudoMatrix& matrix)
{
    m_Matrix = matrix;
}

bool SpiralTraversalAlgorithm::IsNewBlockGood(const QString& answer) const
{
    if (answer.size() >= 500)
        return true;
    return false;
}

QString SpiralTraversalAlgorithm::GetBlockIfIsGood(const QString& answer)
{
    QString newAnswer = answer;
    if (IsNewBlockGood(newAnswer))
    {
        emit goodBlockFound(newAnswer);
        newAnswer.clear();
    }
    return newAnswer;
}

void SpiralTraversalAlgorithm::run()
{
    int elementsCount = m_Matrix.GetColumnSize() * m_Matrix.GetRowSize();
    int spaceCount = 1;
    int stringElementSize = maxElementSize(elementsCount) + spaceCount;

    QString answer;
    answer.reserve(stringElementSize * elementsCount);

    int rowStart = 0;
    int rowEnd = m_Matrix.GetColumnSize();
    int columnStart = 0;
    int columnEnd = m_Matrix.GetRowSize();

    int currentIndex = 0;
    int startMessageIndex = 0;

    while (rowStart < rowEnd && columnStart < columnEnd)
    {
        for (currentIndex = columnStart; currentIndex < columnEnd; ++currentIndex)
        {
            answer.push_back(QString::number(m_Matrix.GetElement(rowStart, currentIndex)) + " ");
        }
        rowStart += 1;
        answer = GetBlockIfIsGood(answer);

        for (currentIndex = rowStart; currentIndex < rowEnd; ++currentIndex)
        {
            answer.push_back(QString::number(m_Matrix.GetElement(currentIndex, columnEnd - 1)) + " ");
        }
        columnEnd -= 1;
        answer = GetBlockIfIsGood(answer);

        if (rowStart < rowEnd)
        {
            for (currentIndex = columnEnd - 1; currentIndex >= columnStart; --currentIndex)
            {
                answer.push_back(QString::number(m_Matrix.GetElement(rowEnd - 1, currentIndex)) + " ");
            }
            rowEnd -= 1;
            answer = GetBlockIfIsGood(answer);
        }

        if (columnStart < columnEnd)
        {
            for (currentIndex = rowEnd - 1; currentIndex >= rowStart; --currentIndex)
            {
                answer.push_back(QString::number(m_Matrix.GetElement(currentIndex, columnStart)) + " ");
            }
            columnStart += 1;
            answer = GetBlockIfIsGood(answer);
        }
    }
    emit goodBlockFound(answer);
}