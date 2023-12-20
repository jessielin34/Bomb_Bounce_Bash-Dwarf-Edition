#pragma once

#include "Dwarf.h"
#include <vector>
#include <random>
#include <iostream>
#include "Ball.h"
#include "Bomb.h"

class MyGame : public dwarf::DwarfApp<MyGame> { //dwarf is for the namespace name
public:
	MyGame();
	virtual void OnUpdate() override;
private:
	void OnKeyPress(const dwarf::KeyPressed& e);
	void RestartGame(); //function to restart game after game over
	int score{ 0 }; 
	long time{ 0 };
	bool gameEnd{ false };
	bool playAgain{ false };
	bool bombCollision{ false };
	dwarf::Unit dwarfs{ "../Assets/Pictures/dwarf.png", 50, 60 };
	dwarf::Unit background{ "../Assets/Pictures/background.png", 0, 0 };
	dwarf::Unit over{ "../Assets/Pictures/over.png", 320, 250 };
	dwarf::Unit explosion{ "../Assets/Pictures/explosion.png", 300, 250 };
	std::vector<Ball> balls;
	std::vector<Bomb> bombs;
	dwarf::Renderer mRenderer;
};

