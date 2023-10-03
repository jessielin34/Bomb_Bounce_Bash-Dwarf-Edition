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

if(WIN32)
	add_definitions(-DDWARF_MSCPP)
elseif(LINUX)
	add_definitions(-DDWARF_LINUX)
elseif(APPLE)
	add_definitions(-DDWARF_APPLE)
endif()

add_library(Dwarf SHARED ${HEADER_FILES} ${SOURCE_FILES})

target_precompile_headers(Dwarf PRIVATE pch.h)