set(HEADER_FILES
	include/Dwarf.h
	DwarfApp.h
	Events.h
	Utilities.h
	GameWindow.h
	WindowImplementation.h
	GLFWCode/GLFWImplementation.h
	GLFWCode/OpenGLShader.h
	OpenGLPicture.h
	OpenGLRenderer.h
	Picture.h
	PictureImplementation.h
	Renderer.h
	RendererImplementation.h
	Shader.h
	ShaderImplementation.h
	Unit.h
)
set(SOURCE_FILES
	GameWindow.cpp
	GLFWCode/GLFWImplementation.cpp
	GLFWCode/OpenGLShader.cpp
	Events.cpp
	OpenGLPicture.cpp
	OpenGLRenderer.cpp
	Picture.cpp
	Renderer.cpp
	Shader.cpp
	Unit.cpp
)

add_definitions(-DDC_DEBUG=2)
add_definitions(-DDWARF_LIB)

include_directories(../Dwarf)
include_directories(../glfw/include)
include_directories(../glad/include)
include_directories(../stbi)

add_library(Dwarf SHARED ${HEADER_FILES} ${SOURCE_FILES})

target_precompile_headers(Dwarf PRIVATE pch.h)

target_link_libraries(Dwarf glfw)
target_link_libraries(Dwarf glad)
target_link_libraries(Dwarf stbi)