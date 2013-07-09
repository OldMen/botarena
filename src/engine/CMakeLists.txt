project( engine )

find_package( Qt4 REQUIRED )
set( QT_USE_QTCORE 1 )
set( QT_USE_QTGUI 1 )
set( QT_USE_QTSCRIPT 1 )
set( QT_USE_QTXML 1 )
include( ${QT_USE_FILE} )

add_subdirectory( core )
add_subdirectory( arena )
add_subdirectory( view )
