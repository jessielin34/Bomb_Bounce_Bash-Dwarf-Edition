#pragma once

#include "Dwarf.h"
#include <vector>
#include <random>
#include <iostream>

class Bomb { //similar to ball class but for bombs
public:
	Bomb(const std::string& image, int x, int y);
	void UpdateYCoord(int horizontalY);
	dwarf::Unit& GetUnit();
private:
	dwarf::Unit unit;
};

class BombGenerator {
public:
	BombGenerator();
	std::vector<Bomb> GenerateBombs(size_t count);
private:
	std::mt19937 rand{ std::random_device{}() };
};
