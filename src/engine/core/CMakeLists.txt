project( core )

set( core_SOURCES core.cpp )
set( core_HEADERS core.h )

add_library( botarena_core SHARED ${core_SOURCES} ${core_HEADERS} )
