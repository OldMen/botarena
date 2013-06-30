#include <QApplication>
#include <QDebug>

int main( int argc, char *argv[] )
{
	QApplication app( argc, argv );
	
	qDebug() << "Hi";
	
	return 0;
}
