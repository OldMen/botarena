project( view )

set( view_SOURCES view.cpp )
set( view_HEADERS view.h )

add_library( botarena_view SHARED ${view_SOURCES} ${view_HEADERS} )
