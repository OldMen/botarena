project( arena )

set( arena_SOURCES arena.cpp )
set( arena_HEADERS arena.h )

add_library( botarena_arena SHARED ${arena_SOURCES} ${arena_HEADERS} )

