/*
 *
 */

#ifndef BOTARENA_CORE_TIMELINE_H
#define BOTARENA_CORE_TIMELINE_H

#include <QObject>

class QTimer;

namespace botarena
{
namespace core
{

/**
 * @brief Базовый класс для всех генераторов времени
 * 
 */
class TimeGenerator : public QObject
{
	Q_OBJECT
public:
    explicit TimeGenerator( QObject *parent = 0 );

signals:
	/**
	 * @brief Сигнал генератора
	 */
	void				cycle();

public slots:
	/**
	 * @brief Запуск генератора
	 */
	virtual	void		start() = 0;
	/**
	 * @brief Остановка генератора
	 */
	virtual	void		stop() = 0;
};

/**
 * @brief Линейный генератор времени - генерирует такты с постоянным заданным интервалом
 * 
 */
class LineTimeGenerator : public TimeGenerator
{
	Q_OBJECT
public:
	/**
	 * @brief Конструктор генератора с постоянным интервалом
	 * 
	 * @param time интервал генерации тактов
	 * @param parent родительский объект
	 */
	explicit LineTimeGenerator( int time, QObject *parent = 0 );
	
public slots:
	void				start();
	void				stop();
	
private:
	QTimer				*m_timer;
};

}
}

#endif // BOTARENA_CORE_TIMELINE_H
