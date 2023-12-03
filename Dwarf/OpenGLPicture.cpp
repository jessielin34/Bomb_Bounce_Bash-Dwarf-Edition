#include "pch.h"
#include "OpenGLPicture.h"

#include "../glad/include/glad/glad.h"
#include "../glfw/include/GLFW/glfw3.h"
#include "Utilities.h"

namespace dwarf {
	void OpenGLPicture::Bind() {
		glUseProgram(mTextures); //figure out what to put inside this function
	}
	OpenGLPicture::~OpenGLPicture() {
		glDeleteTextures(num, mTextures);
	}
}