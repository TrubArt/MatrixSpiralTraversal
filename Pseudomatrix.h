#pragma once
#include <iostream>

class PseudoMatrix
{
public:
	PseudoMatrix() = default;
	PseudoMatrix(int rowSize, int columnSize);

	void SetRowSize(int rowSize);
	void SetColumnSize(int colSize);
	int GetRowSize() const;
	int GetColumnSize() const;
	int GetElement(int i, int j) const;

	QString SpiralTraversal() const;
private:
	int m_rowSize = 0;
	int m_columnSize = 0;
};