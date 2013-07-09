/*
 *
 */

#include "timeline.h"
#include <QTimer>

namespace botarena
{
namespace core
{

TimeGenerator::TimeGenerator( QObject *parent )
	: QObject( parent )
{
}

LineTimeGenerator::LineTimeGenerator( int time, QObject *parent )
	: TimeGenerator( parent ),
	  m_timer( new QTimer( this ) )
{
	m_timer->setInterval( time );
	connect( m_timer, SIGNAL( timeout() ), SIGNAL( cycle() ) );
}

void LineTimeGenerator::start()
{
	m_timer->start();
}

void LineTimeGenerator::stop()
{
	m_timer->stop();
}

}
}
