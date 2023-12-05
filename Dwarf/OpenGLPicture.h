#pragma once

#include "pch.h"
#include "PictureImplementation.h"

namespace dwarf {
	class OpenGLPicture :public PictureImplementation {
	public: 
			OpenGLPicture(const std::string& file);
			OpenGLPicture(std::string&& file);
			void Bind() override;
			~OpenGLPicture();
			virtual int GetHeight() const override;
			virtual int GetWidth() const override;
		private:
			unsigned int VAO;
			unsigned int VBO;
			unsigned int EBO;
			unsigned int texture;
			int num;
			int mWidth{ 0 };
			int mHeight{ 0 };
	};
}