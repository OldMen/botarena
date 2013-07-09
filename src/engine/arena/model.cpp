/*
 *
 */

#include "model.h"
#include "scriptengine.h"

namespace botarena
{
namespace arena
{

Model::Model( QObject *parent )
	: QObject( parent )
{
}

bool Model::installTo( core::ScriptEngine &eng )
{
//	eng.scriptEngine();
}

}
}