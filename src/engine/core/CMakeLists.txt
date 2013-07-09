project( core )

include_directories( ${core_SOURCE_DIR} ${arena_SOURCE_DIR} ${view_SOURCE_DIR} )

set( core_SOURCES scriptengine.cpp timeline.cpp botscheduler.cpp )
set( core_HEADERS scriptengine.h timeline.h botscheduler.h )
QT4_WRAP_CPP( core_MOC_SOURCES scriptengine.h timeline.h botscheduler.h )

add_library( botarena_core SHARED ${core_SOURCES} ${core_HEADERS} ${core_MOC_SOURCES} ${QT_LIBRARIES} )
