#include "Picture.h"
#include "pch.h"
#include "OpenGLPicture.h"

dwarf::Picture::Picture(const std::string& imageFile) {
#ifdef DWARF_MSCPP
	mImplementation = std::unique_ptr<PictureImplementation>{ new OpenGLPicture(imageFile) };
#elif DWARF_APPLE
	mImplementation = std::unique_ptr<PictureImplementation>{ new OpenGLPicture(imageFile) };
#elif DWARF_LINUX
	mImplementation = std::unique_ptr<PictureImplementation>{ new OpenGLPicture(imageFile) };
#endif
	}

dwarf::Picture::Picture(std::string&& imageFile) {
#ifdef DWARF_MSCPP
	mImplementation = std::unique_ptr<PictureImplementation>{ new OpenGLPicture(std::move(imageFile)) };
#elif DWARF_APPLE
	mImplementation = std::unique_ptr<PictureImplementation>{ new OpenGLPicture(std::move(imageFile)) };
#elif DWARF_LINUX
	mImplementation = std::unique_ptr<PictureImplementation>{ new OpenGLPicture(std::move(imageFile)) };
#endif
}

void dwarf::Picture::Bind() {
	return mImplementation->Bind();
}

int dwarf::Picture::GetHeight() const {
	return mImplementation->GetHeight();
}

int dwarf::Picture::GetWidth() const {
	return mImplementation->GetWidth();;
}
