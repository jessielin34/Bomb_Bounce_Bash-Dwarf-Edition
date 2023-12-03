#include "pch.h"
#include "Renderer.h"
#include "GLFWCode/OpenGLRenderer.h"

dwarf::Renderer::Renderer() {
#ifdef DWARF_MSCPP
	mImplementation = std::unique_ptr<RendererImplementation>{ new OpenGLRenderer };
#elif DWARF_APPLE
	mImplementation = std::unique_ptr<RendererImplementation>{ new OpenGLRenderer };
#elif DWARF_LINUX
	mImplementation = std::unique_ptr<RendererImplementation>{ new OpenGLRenderer };
#endif
}

void dwarf::Renderer::Init() {
	mImplemnentation->Init();
}

void dwarf::Renderer::Draw(int x, int y, Picture& pic) {
	mImplementation->Draw(x, y, pic);
}

void dwarf::Renderer::Clear() {
	mImplementation->Clear();
}
