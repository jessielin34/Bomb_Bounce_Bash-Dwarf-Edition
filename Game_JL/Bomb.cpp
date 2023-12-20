#include "Bomb.h"

Bomb::Bomb(const std::string& image, int x, int y) : unit(image, x, y)
{
}

void Bomb::UpdateYCoord(int horizontalY)
{
	unit.UpdateYCoord(horizontalY);
}

dwarf::Unit& Bomb::GetUnit()
{
	return unit;
}

BombGenerator::BombGenerator()
{
}

//make x of bombs and return them in a vector
std::vector<Bomb> BombGenerator::GenerateBombs(size_t count)
{
	int positionY = 900; //initial vertical position for first bomb
	std::vector<Bomb> bombs; //vector to store the generated bomb

	std::uniform_int_distribution<int> distance(0, 927); //uniform distribution

	for (size_t i = 0; i < count; ++i) {
		int randomX = distance(rand);
		bombs.emplace_back("../Assets/Pictures/bomb.png", randomX, positionY); //create and add bomb to vector
		positionY += 75;
	}

	return bombs;
}
