#
#
#

PROJECT( game )

# =============================================================================================
find_package( Qt4 REQUIRED )
set( QT_USE_QTSCRIPT 1 )
set( QT_USE_QTXML 1 )
include( ${QT_USE_FILE} )

# =============================================================================================

include_directories( ${core_SOURCE_DIR} ${arena_SOURCE_DIR} ${view_SOURCE_DIR} )

set( game_HEADERS  )
set( game_SOURCES main.cpp )
QT4_WRAP_CPP( game_MOC_SOURCES  )

# QT4_ADD_RESOURCES( game_QRC_SOURCES application.qrc )

add_executable( game ${game_SOURCES} ${game_HEADERS} ${game_MOC_SOURCES} ${game_QRC_SOURCES} )
target_link_libraries( game botarena_core botarena_arena botarena_view ${QT_LIBRARIES} )
