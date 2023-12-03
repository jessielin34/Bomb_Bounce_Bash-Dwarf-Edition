#include "Picture.h"
#include "../glad/include/glad/glad.h"
#include "../glfw/include/GLFW/glfw3.h"
#include "../stbi/stb_image.h"

dwarf::Picture::Picture() {
	//creating texture in picture class
	unsigned int texture;
	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	//loading image
	int width, height, nrChannels;
	stbi_set_flip_vertically_on_load(true);
	unsigned char* data = stbi_load("../Assets/Pictures/test.png", &width, &height, &nrChannels, 0);

	if (data) {
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);
	}
	else {
		DC_ERROR("Failed to load a picture from the file!!!");
	}
	stbi_image_free(data);
}

void dwarf::Picture::Bind() {
	mImplementation->Bind();
}

int dwarf::Picture::GetHeight() const {
	return mImplementation->GetHeight();
}

int dwarf::Picture::GetWidth() const {
	return mImplementation->GetWidth();;
}
