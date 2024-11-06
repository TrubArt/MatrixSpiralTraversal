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
	* @brief Усыпляет текущий поток на milleseconds миллисекунд.
	* @param milliseconds Время сна.
	*/
	void Sleep(quint32 milliseconds);

	/**
	* @brief Пробуждает целевой поток из другого потока.
	*/
	void Wake();

signals:
	void goodBlockFound(const QString& string);

private:
	void run() override;

	/**
	* @brief Возвращает true, если полученный блок answer сформирован
	(имеет достаточную длину), иначе false.
	* @param answer передаваемый для оценивания блок.
	*/
	bool IsNewBlockGood(const QString& answer) const;

	/**
	* @brief Вызывает сигнал goodBlockFound, который передаёт блок для отрисовки.
	Возвращает пустую строку, если блок оправился,
	иначе возвращает answer. 
	* @param answer передаваемый для отправки блок.
	*/
	QString GetBlockIfIsGood(const QString& answer);

	bool m_stopFromOutside = false;
	PseudoMatrix m_Matrix;
	QMutex m_Mutex;
	QWaitCondition m_WaitCondition;
};

