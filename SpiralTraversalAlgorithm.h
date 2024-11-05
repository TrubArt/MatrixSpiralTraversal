#pragma once
#include "Pseudomatrix.h"
#include "qthread.h"
#include <QString>

class SpiralTraversalAlgorithm : public QThread
{
	Q_OBJECT

public:
	explicit SpiralTraversalAlgorithm(QObject* parent = nullptr);
	void SetMatrix(const PseudoMatrix& matrix);

signals:
	void goodBlockFound(const QString& string);

private:
	void run() override;

	bool IsNewBlockGood(const QString& answer) const;
	QString GetBlockIfIsGood(const QString& answer);

	PseudoMatrix m_Matrix;
};

