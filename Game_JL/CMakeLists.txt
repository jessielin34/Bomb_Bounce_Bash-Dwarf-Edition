set(HEADER_FILES
)
set(SOURCE_FILES
	main.cpp
)
add_executable(Game_JL ${HEADER_FILES} ${SOURCE_FILES})
target_link_libraries(Game_JL Dwarf)
include_directories(../Dwarf/include)