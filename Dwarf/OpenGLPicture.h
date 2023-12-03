#pragma once

#include "PictureImplementation.h"

namespace dwarf {
	class OpenGLPicture :public PictureImplementation {
		public: 
			void Bind() override;
			~OpenGLPicture();
		private:
			unsigned int *mTextures;
			int num;
	};
}