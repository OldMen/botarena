/*
 *
 */

#ifndef BOTARENA_CORE_BOTSCHEDULER_H
#define BOTARENA_CORE_BOTSCHEDULER_H

#include <QObject>
#include "scriptengine.h"

/**
 * @file botscheduler.h
 * @brief Планировщик ботов
 */

namespace botarena
{
namespace core
{

/**
 * @brief Планировщик ботов
 */
class BotScheduler : public QObject
{
	Q_OBJECT
public:
	explicit BotScheduler( QObject *parent = 0 );

	/**
	 * @brief Инсталлировать API в скриптовый движок
	 *
	 * @param eng ссылка на движок
	 */
	virtual	void	installTo( core::ScriptEngine &eng );

signals:
	/**
	 * @brief Сигнал вызывается после выполнению кода очередного бота
	 */
	void			completeBot( const QString &name );
	/**
	 * @brief Сигнал вызывается после выполнению кода всех ботов
	 */
	void			completePass();
	
public slots:
	/**
	 * @brief Добавить бот в очередь планировщика
	 *
	 * @param name имя бота
	 * @param epoint точка входа в функцию бота
	 */
	void			appendBot( const QString &name, const QScriptValue &epoint );
	/**
	 * @brief Удалить бот из очереди планировщика
	 *
	 * @param name имя бота
	 */
	void			removeBot( const QString &name );

	/**
	 * @brief Выполнить код очередного бота
	 */
	void			process();

protected:
	/**
	 * @brief Найти в очереди индекс бота с указанным именем
	 *
	 * @param name имя бота
	 * @return int индекс бота или -1, если бота с таким именем нет в очереди
	 */
	int				indexAt( const QString &name ) const;
	
private:
	struct BotItem
	{
		QString			m_name;
		QScriptValue	m_botEntryPoint;
	};
	typedef	QList<BotItem>	ListBot;
	ListBot				m_bots;					//!< Очередь ботов
	
	size_t				m_cur;					//!< Индекс текущего бота для выполнения
};

}
}

#endif // BOTARENA_CORE_BOTSCHEDULER_H
