/*
 *
 */

#ifndef BOTARENA_ARENA_MODEL_H
#define BOTARENA_ARENA_MODEL_H

#include <QObject>

namespace botarena
{

namespace core
{
class ScriptEngine;
}
	
namespace arena
{

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
