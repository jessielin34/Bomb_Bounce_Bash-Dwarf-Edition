#pragma once

#include "Utilities.h"
#include "GameWindow.h"
#include "Renderer.h"
#include "Picture.h"
#include "Unit.h"


namespace dwarf {
	constexpr int FPS{ 60 };

	template <typename T>
	class DwarfApp {
		public:
			//DwarfApp(); //constructor
			static void Init();
			static void RunInterface();
			void Run(); //starts the game
			virtual void OnUpdate(); //pure virtual; abstract
			void Draw(int x, int y, Picture& pic);
			void Draw(Unit& item);
			void SetKeyPressedCallback(std::function<void(const KeyPressed&)> callbackFunc);
			void SetKeyReleasedCallback(std::function<void(const KeyReleased&)> callbackFunc);
			void SetWindowCloseCallback(std::function<void()> callbackFunc);
			void DefaultWindowCloseHandler();
			friend typename T;
		private:
			DwarfApp(); //constructor
			inline static DwarfApp* sInstance{ nullptr };
			GameWindow mWindow;
			Renderer mRenderer;
			bool mShouldContinue{ true };

			std::chrono::milliseconds mFrameDuration{ std::chrono::milliseconds{1000} / FPS };
			std::chrono::steady_clock::time_point mNextFrameTime;
	};
}

#include "DwarfApp.cpp"