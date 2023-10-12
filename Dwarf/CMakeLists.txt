set(HEADER_FILES
	include/Dwarf.h
	DwarfApp.h
	Utilities.h
)
set(SOURCE_FILES
	placeholder.cpp
)

add_definitions(-DDC_DEBUG=2)
add_definitions(-DDWARF_LIB)

include_directories(../glfw/include)

add_library(Dwarf SHARED ${HEADER_FILES} ${SOURCE_FILES})

target_precompile_headers(Dwarf PRIVATE pch.h)

target_link_libraries(Dwarf glfw)