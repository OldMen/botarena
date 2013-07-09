project( view )

include_directories( ${core_SOURCE_DIR} ${arena_SOURCE_DIR} ${view_SOURCE_DIR} )

set( view_SOURCES view.cpp )
set( view_HEADERS view.h )

add_library( botarena_view SHARED ${view_SOURCES} ${view_HEADERS} )
