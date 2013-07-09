/*
 *
 */

#include "botscheduler.h"
#include <QScriptValue>
#include <QDebug>
#include <stdint.h>

namespace botarena
{
namespace core
{

BotScheduler::BotScheduler( QObject *parent )
	: QObject( parent ), m_cur( 0 )
{
}

void BotScheduler::installTo( ScriptEngine &eng )
{
	eng.regObject( "BotScheduler", this );
}

void BotScheduler::appendBot( const QString &name, const QScriptValue &epoint )
{
	if( indexAt( name ) != -1 )
	{
		qWarning( "[BotScheduler::appendBot] Bot '%s' already append.", qPrintable( name ) );
		return;
	}
	
	BotItem item;
	item.m_name = name;
	item.m_botEntryPoint = epoint;
	m_bots.append( item );
}

void BotScheduler::removeBot( const QString &name )
{
	int idx = indexAt( name );
	if( idx == -1 )
	{
		qWarning( "[BotScheduler::removeBot] Bot '%s' not found.", qPrintable( name ) );
		return;
	}
	m_bots.removeAt( idx );
	
	// Если удалили последний бот в очереди и он должен был исполняться, то сбрасываем указатель на начало очереди
	if( m_cur >= m_bots.size() )
		m_cur = 0;
}

void BotScheduler::process()
{
	if( !m_bots.size() )
		return;
	
	m_bots[ m_cur ].m_botEntryPoint.call();
	emit completeBot( m_bots[ m_cur ].m_name );

	if( ++m_cur == m_bots.size() )
	{
		m_cur = 0;
		emit completePass();
	}
}

int BotScheduler::indexAt( const QString &name ) const
{
	for( int i = 0; i < m_bots.size(); ++i )
	{
		if( m_bots[ i ].m_name == name )
			return i;
	}
	
	return -1;
}

}
}
