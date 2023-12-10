#pragma once

#include "RendererImplementation.h" 

namespace dwarf {
	class OpenGLRenderer : public RendererImplementation {
	public:
		virtual void Init();
		virtual void Draw(int x, int y, Picture& pic) override;
		virtual void Clear() override;
	};
}
