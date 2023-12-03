#include "Dwarf.h" //header file of all the functionality of game
#include <iostream>

class MyGame : public dwarf::DwarfApp<MyGame> { //dwarf is for the namespace name
	public:
		virtual void OnUpdate() override {
			//std::cout << "Dwarf running" << std::endl;
		}
};

DWARF_APPLICATION_START(MyGame);