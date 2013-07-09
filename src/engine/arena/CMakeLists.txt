project( arena )

include_directories( ${core_SOURCE_DIR} ${arena_SOURCE_DIR} ${view_SOURCE_DIR} )

set( arena_SOURCES model.cpp )
set( arena_HEADERS model.h )
QT4_WRAP_CPP( arena_MOC_SOURCES model.h )

add_library( botarena_arena SHARED ${arena_SOURCES} ${arena_HEADERS} ${arena_MOC_SOURCES} )

