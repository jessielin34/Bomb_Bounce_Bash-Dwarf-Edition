#include "pch.h"
#include "Picture.h"
#include "GLFWCode/OpenGLPicture.h"

namespace dwarf {
	Picture::Picture(const std::string& imageFile) {
		#ifdef DWARF_MSCPP
				mImplementation = std::unique_ptr<PictureImplementation>{ new OpenGLPicture(imageFile) };
		#elif DWARF_APPLE
				mImplementation = std::unique_ptr<PictureImplementation>{ new OpenGLPicture(imageFile) };
		#elif DWARF_LINUX
				mImplementation = std::unique_ptr<PictureImplementation>{ new OpenGLPicture(imageFile) };
		#endif
	}

	Picture::Picture(std::string&& imageFile) {
		#ifdef DWARF_MSCPP
				mImplementation = std::unique_ptr<PictureImplementation>{ new OpenGLPicture(std::move(imageFile)) };
		#elif DWARF_APPLE
				mImplementation = std::unique_ptr<PictureImplementation>{ new OpenGLPicture(std::move(imageFile)) };
		#elif DWARF_LINUX
				mImplementation = std::unique_ptr<PictureImplementation>{ new OpenGLPicture(std::move(imageFile)) };
		#endif
	}

	void Picture::Bind() {
		mImplementation->Bind();
	}

	int Picture::GetHeight() const {
		return mImplementation->GetHeight();
	}

	int Picture::GetWidth() const {
		return mImplementation->GetWidth();;
	}
}
