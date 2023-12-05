#include "pch.h"
#include "Events.h"

namespace dwarf {
	KeyPressed::KeyPressed(int kCode) {
	}
	int KeyPressed::GetKeyCode() const
	{
		return mKeyCode;
	}
	KeyReleased::KeyReleased(int kCode) {
	}
	int KeyReleased::GetKeyCode() const
	{
		return mKeyCode;
	}
}