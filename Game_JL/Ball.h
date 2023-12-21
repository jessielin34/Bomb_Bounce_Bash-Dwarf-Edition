#pragma once

#include "Dwarf.h"
#include <vector>
#include <random>
#include <iostream>

class Ball {
public: 
	Ball(const std::string& image, int x, int y); //initializes the ball with image and coordinates
	void UpdateYCoord(int horizontalY); //update vertical position of ball
	dwarf::Unit& GetUnit(); //reference to the dwarf::Unit object
private:
	dwarf::Unit unit;
};

class BallGenerator {
public:
	BallGenerator(); //initializes random numbers
	std::vector<Ball> GenerateBalls(size_t count);
};
