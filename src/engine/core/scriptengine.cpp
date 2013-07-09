/*
 *
 */

#include "scriptengine.h"
#include <QScriptProgram>
#include <QFile>
#include <QDebug>

namespace botarena
{
namespace core
{

ScriptEngine::ScriptEngine( QObject *parent )
	: QObject( parent )
{
}

bool ScriptEngine::execute( const QByteArray &text )
{
	QScriptProgram prg( text );
	
	QScriptValue result = m_engine.evaluate( prg );
	if( m_engine.hasUncaughtException() )
	{
		int line = m_engine.uncaughtExceptionLineNumber();
		qWarning() << "Script uncaught exception at line" << line << ":" << result.toString();
		return false;
	}

	return true;
}

bool ScriptEngine::executeFile( const QString &filename )
{
	QFile src( filename );
	return src.open( QIODevice::ReadOnly ) && execute( src.readAll() );
}

void ScriptEngine::regFunc( const QString &nspace, const QString &nfunc, ScriptFunction func )
{
	QScriptValue ns = m_engine.globalObject().property( nspace );
	if( !ns.isValid() )
	{
		ns = m_engine.newObject();
		m_engine.globalObject().setProperty( nspace, ns );
	}
		
	QScriptValue funcValue = m_engine.newFunction( func );
	ns.setProperty( nfunc, funcValue );
}

void ScriptEngine::regObject( const QString &nobj, QObject *obj )
{
	QScriptValue objValue = m_engine.newQObject( obj );
	m_engine.globalObject().setProperty( nobj, objValue );
}

}
}
