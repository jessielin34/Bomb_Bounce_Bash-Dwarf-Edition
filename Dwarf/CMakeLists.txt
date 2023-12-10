set(HEADER_FILES
	include/Dwarf.h
	DwarfApp.h
	Events.h
	Utilities.h
	GameWindow.h
	WindowImplementation.h
	GLFWCode/GLFWImplementation.h
)
set(SOURCE_FILES
	GameWindow.cpp
	GLFWCode/GLFWImplementation.cpp
)

add_definitions(-DDC_DEBUG=2)
add_definitions(-DDWARF_LIB)

include_directories(../Dwarf)
include_directories(../glfw/include)

add_library(Dwarf SHARED ${HEADER_FILES} ${SOURCE_FILES})

target_precompile_headers(Dwarf PRIVATE pch.h)

target_link_libraries(Dwarf glfw)