#include "pch.h"
#include "DwarfApp.h"

namespace dwarf
{
	template <typename T>
	DwarfApp<T>::DwarfApp() {}

	template <typename T>
	void DwarfApp<T>::Init() {
		if (sInstance == nullptr) {
			sInstance = new T;
		}
	}

	template <typename T>
	void DwarfApp<T>::RunInterface() {
		sInstance->Run();
	}

	template <typename T>
	void DwarfApp<T>::Run() {
		mWindow.Create("Game_JL", 1000, 800);

		while (mShouldContinue) {
			OnUpdate();

			mWindow.SwapBuffers();
			mWindow.PollEvents();
		}
	}

	template <typename T>
	void DwarfApp<T>::OnUpdate() {
	}
};