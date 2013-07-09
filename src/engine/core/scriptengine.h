/*
 *
 */

#ifndef BOTARENA_CORE_SCRIPT_ENGINE_H
#define BOTARENA_CORE_SCRIPT_ENGINE_H

#include <QObject>
#include <QScriptEngine>

namespace botarena
{
namespace core
{

typedef	QScriptEngine 						ScriptEngineType;
typedef	QScriptEngine::FunctionSignature	ScriptFunction;

class ScriptEngine : public QObject
{
	Q_OBJECT
public:
	explicit ScriptEngine( QObject *parent = 0 );
	
	/**
	 * @brief Выполнить скрипт из буфера
	 * 
	 * @param text буфер с текстом скрипта
	 * @return bool статус завершения
	 */
	bool				execute( const QByteArray &text );
	/**
	 * @brief Выполнить скрипт из файла
	 * 
	 * @param filename имя файла для выполнения
	 * @return bool статус завершения
	 */
	bool				executeFile( const QString &filename );
	
	/**
	 * @brief Регистрация функции в скриптовом окружении
	 * 
	 * @param nspace имя пространства имен
	 * @param nfunc имя функции
	 * @param func указатель на функцию
	 */
	void				regFunc( const QString &nspace, const QString &nfunc, ScriptFunction func );
	
	/**
	 * @brief Регистрация объекта в скриптовом окружении
	 * 
	 * @param nobj имя объекта
	 * @param obj указатель на объект
	 */
	void				regObject( const QString &nobj, QObject *obj );
	
private:
	ScriptEngineType	m_engine;			//!< Нативный скриптовый движек
};

}
}

#endif // BOTARENA_CORE_SCRIPT_ENGINE_H
