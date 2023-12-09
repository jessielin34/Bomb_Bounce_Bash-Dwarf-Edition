#pragma once

#include "pch.h"
#include "Utilities.h"
#include "PictureImplementation.h"

namespace dwarf {
	class DWARF_API Picture {
		public:
			Picture(const std::string& imageFile);
			Picture(std::string&& imageFile);
			void Bind();
			int GetHeight() const;
			int GetWidth() const;
		private:
			std::unique_ptr<PictureImplementation> mImplementation;
	};
}
