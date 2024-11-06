#pragma once
#include "Pseudomatrix.h"

#include <QThread>
#include <QString>
#include <QMutex>
#include <QWaitCondition>

class SpiralTraversalAlgorithm : public QThread
{
	Q_OBJECT

public:
	explicit SpiralTraversalAlgorithm(QObject* parent = nullptr);
	void SetMatrix(const PseudoMatrix& matrix);
	void StopThreadExecution();
	bool GetStopStatus() const;

	/**
	* @brief �������� ������� ����� �� milleseconds �����������.
	* @param milliseconds ����� ���.
	*/
	void Sleep(quint32 milliseconds);

	/**
	* @brief ���������� ������� ����� �� ������� ������.
	*/
	void Wake();

signals:
	void goodBlockFound(const QString& string);

private:
	void run() override;

	/**
	* @brief ���������� true, ���� ���������� ���� answer �����������
	(����� ����������� �����), ����� false.
	* @param answer ������������ ��� ���������� ����.
	*/
	bool IsNewBlockGood(const QString& answer) const;

	/**
	* @brief �������� ������ goodBlockFound, ������� ������� ���� ��� ���������.
	���������� ������ ������, ���� ���� ���������,
	����� ���������� answer. 
	* @param answer ������������ ��� �������� ����.
	*/
	QString GetBlockIfIsGood(const QString& answer);

	bool m_stopFromOutside = false;
	PseudoMatrix m_Matrix;
	QMutex m_Mutex;
	QWaitCondition m_WaitCondition;
};

