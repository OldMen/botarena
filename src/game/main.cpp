#include <QApplication>
#include <QFile>
#include <QDebug>
#include <scriptengine.h>
#include <timeline.h>
#include <botscheduler.h>
#include <model.h>

using namespace botarena;

int main( int argc, char *argv[] )
{
	QApplication app( argc, argv );
	
	core::ScriptEngine eng;

	core::BotScheduler sh;
	qDebug() << "Install botscheduler api to scriptengine.";
	sh.installTo( eng );

	arena::Model mod;
	qDebug() << "Install model api to scriptengine.";
	mod.installTo( eng );
	
	qDebug() << "Load bot-code.";
	if( !eng.executeFile( "bot.js" ) )
	{
		qWarning() << "Error execution script bot.js.";
		return 1;
	}

	qDebug() << "Running...";
	core::LineTimeGenerator gen( 500 );
	QObject::connect( &gen, SIGNAL( cycle() ), &sh, SLOT( process() ) );
	gen.start();
	
	return app.exec();
}
