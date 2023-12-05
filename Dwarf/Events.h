#pragma once

#include "Utilities.h"

namespace dwarf {
	class DWARF_API KeyPressed {
		public:
			KeyPressed(int kCode);
			int GetKeyCode() const;
		private:
			int mKeyCode;
	};

	class DWARF_API KeyReleased {
		public:
			KeyReleased(int kCode);
			int GetKeyCode() const;
		private:
			int mKeyCode;
	};

	class DWARF_API WindowClosed {

	};
}