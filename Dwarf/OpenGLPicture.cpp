#include "pch.h"
#include "OpenGLPicture.h"

#include "../glad/include/glad/glad.h"
#include "../glfw/include/GLFW/glfw3.h"
#include "Utilities.h"
#include "../../stbi/stb_image.h"

namespace dwarf {
	OpenGLPicture::OpenGLPicture(const std::string& file)
	{
		glGenTextures(1, &texture);
		glBindTexture(GL_TEXTURE_2D, texture);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		//loading image
		int nrChannels;
		stbi_set_flip_vertically_on_load(true);
		unsigned char* data = stbi_load(file.c_str(), &mWidth, &mHeight, &nrChannels, 0);

		if (data) {
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, mWidth, mHeight, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
			glGenerateMipmap(GL_TEXTURE_2D);
		}
		else {
			DC_ERROR("Failed to load a picture from the file!!!");
		}
		stbi_image_free(data);
	}
	OpenGLPicture::OpenGLPicture(std::string&& file)
	{
		glGenTextures(1, &texture);
		glBindTexture(GL_TEXTURE_2D, texture);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		//loading image
		int nrChannels;
		stbi_set_flip_vertically_on_load(true);
		unsigned char* data = stbi_load(file.c_str(), &mWidth, &mHeight, &nrChannels, 0); 

		if (data) {
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, mWidth, mHeight, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
			glGenerateMipmap(GL_TEXTURE_2D);
		}
		else {
			DC_ERROR("Failed to load a picture from the file!!!");
		}
		stbi_image_free(data);
	}
	void OpenGLPicture::Bind()
	{
		glBindTexture(GL_TEXTURE_2D, texture);
	}
	OpenGLPicture::~OpenGLPicture()
	{
		glDeleteTextures(1, &texture);
	}
	int OpenGLPicture::GetHeight() const
	{
		return mHeight;
	}
	int OpenGLPicture::GetWidth() const
	{
		return mWidth;
	}
}
