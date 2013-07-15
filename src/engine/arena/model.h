/*
 *
 */

#ifndef BOTARENA_ARENA_MODEL_H
#define BOTARENA_ARENA_MODEL_H

#include <QObject>

/**
 * @file model.h
 * @brief Базовая модель арены
 */

namespace botarena
{

namespace core
{
class ScriptEngine;
}
	
/*!
 * @namespace botarena::arena
 * @brief Арена ботов
 *
 * Содержит классы арены ботов.
 */
namespace arena
{

/**
 * @brief Базовый класс для всех моделей арены
 */
class Model : public QObject
{
	Q_OBJECT
public:
	explicit Model( QObject *parent = 0 );

	virtual	bool	installTo( core::ScriptEngine &eng );
	
protected:
};

}
}

#endif // BOTARENA_ARENA_MODEL_H
