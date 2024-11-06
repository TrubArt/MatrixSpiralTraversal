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

void SpiralTraversalAlgorithm::StopThreadExecution()
{
    m_stopFromOutside = true;
}

bool SpiralTraversalAlgorithm::GetStopStatus() const
{
    return m_stopFromOutside;
}

void SpiralTraversalAlgorithm::Sleep(quint32 milliseconds)
{
    m_Mutex.lock();
    m_WaitCondition.wait(&m_Mutex, milliseconds);
    m_Mutex.unlock();
}

void SpiralTraversalAlgorithm::Wake()
{
    m_Mutex.lock();
    m_WaitCondition.wakeAll();
    m_Mutex.unlock();
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
        Sleep(5000);
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

    m_stopFromOutside = false;

    while (rowStart < rowEnd && columnStart < columnEnd)
    {
        for (int currentIndex = columnStart; currentIndex < columnEnd; ++currentIndex)
        {
            answer.push_back(QString::number(m_Matrix.GetElement(rowStart, currentIndex)) + " ");
        }
        rowStart += 1;

        for (int currentIndex = rowStart; currentIndex < rowEnd; ++currentIndex)
        {
            answer.push_back(QString::number(m_Matrix.GetElement(currentIndex, columnEnd - 1)) + " ");
        }
        columnEnd -= 1;

        if (rowStart < rowEnd)
        {
            for (int currentIndex = columnEnd - 1; currentIndex >= columnStart; --currentIndex)
            {
                answer.push_back(QString::number(m_Matrix.GetElement(rowEnd - 1, currentIndex)) + " ");
            }
            rowEnd -= 1;
        }

        if (columnStart < columnEnd)
        {
            for (int currentIndex = rowEnd - 1; currentIndex >= rowStart; --currentIndex)
            {
                answer.push_back(QString::number(m_Matrix.GetElement(currentIndex, columnStart)) + " ");
            }
            columnStart += 1;
        }

        answer = GetBlockIfIsGood(answer);
        if (m_stopFromOutside)
        {
            return;
        }
    }
    emit goodBlockFound(answer);
}
