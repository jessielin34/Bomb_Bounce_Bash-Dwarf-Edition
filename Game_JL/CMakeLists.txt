set(HEADER_FILES
	Ball.h
	Bomb.h
	MyGame.h
)
set(SOURCE_FILES
	Ball.cpp
	Bomb.cpp
	MyGame.cpp
	main.cpp
)
add_executable(Game_JL ${HEADER_FILES} ${SOURCE_FILES})
target_link_libraries(Game_JL Dwarf)
include_directories(../Dwarf/include)