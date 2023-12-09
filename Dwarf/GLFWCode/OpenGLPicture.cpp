#include "pch.h"
#include "OpenGLPicture.h"

#include "../glad/include/glad/glad.h"
#include "../glfw/include/GLFW/glfw3.h"
#include "Utilities.h"
#include "../../stbi/stb_image.h"

namespace dwarf {
	OpenGLPicture::OpenGLPicture(const std::string& file)
	{
		//unsigned int texture;
		//glGenTextures(1, &texture);
		//glBindTexture(GL_TEXTURE_2D, texture);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		//loading image
		//int width, height, nrChannels;
		int nrChannels;
		stbi_set_flip_vertically_on_load(true);
		unsigned char* data = stbi_load("../Assets/Pictures/test.png", &mWidth, &mHeight, &nrChannels, 0);

		if (data) {
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, mWidth, mHeight, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
			glGenerateMipmap(GL_TEXTURE_2D);
		}
		else {
			DC_ERROR("Failed to load a picture from the file!!!");
		}
		stbi_image_free(data);
		//next part
		//glEnable(GL_BLEND);
		//glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	}
	OpenGLPicture::OpenGLPicture(std::string&& file)
	{
		//unsigned int texture;
		//glGenTextures(1, &texture);
		//glBindTexture(GL_TEXTURE_2D, texture);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		//loading image
		//int width, height, nrChannels;
		int nrChannels;
		stbi_set_flip_vertically_on_load(true);
		unsigned char* data = stbi_load("../Assets/Pictures/test.png", &mWidth, &mHeight, &nrChannels, 0);

		if (data) {
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, mWidth, mHeight, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
			glGenerateMipmap(GL_TEXTURE_2D);
		}
		else {
			DC_ERROR("Failed to load a picture from the file!!!");
		}
		stbi_image_free(data);
		//next part
		//glEnable(GL_BLEND);
		//glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	}
	void OpenGLPicture::Bind() {
		glGenTextures(1, &texture); 
		glBindTexture(GL_TEXTURE_2D, texture); 
		//glUseProgram(texture); figure out what to put inside this function
	}
	OpenGLPicture::~OpenGLPicture() {
		glDeleteTextures(nrChannels, &texture); //ask to see if num is correct
	}
	int OpenGLPicture::GetHeight() const
	{
		return mWidth;
	}
	int OpenGLPicture::GetWidth() const
	{
		return mHeight;
	}
}