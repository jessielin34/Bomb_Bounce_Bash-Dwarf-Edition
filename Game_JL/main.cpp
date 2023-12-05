#include "Dwarf.h" //header file of all the functionality of game
#include <iostream>

class MyGame : public dwarf::DwarfApp<MyGame> { //dwarf is for the namespace name
	public:
		MyGame() {
			SetKeyPressedCallback([this](const dwarf::KeyPressed& e) {OnKeyPress(e); });
		}
		virtual void OnUpdate() override {
			//std::cout << "Dwarf running" << std::endl;
			Draw(x, y, mPic);
		}

		void OnKeyPress(const dwarf::KeyPressed& e) {
			if (e.GetKeyCode() == DWARF_KEY_RIGHT) {
				x += 50;
			}
			else if (e.GetKeyCode() == DWARF_KEY_LEFT) {
				x -= 50;
			}
		}
	private:
		dwarf::Picture mPic{ "../Assets/Pictures/test.png" };

		int x{ 100 };
		int y{ 100 };
};

DWARF_APPLICATION_START(MyGame);