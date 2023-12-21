#include "Ball.h"

Ball::Ball(const std::string& image, int x, int y) : unit(image, x, y)
{
}

void Ball::UpdateYCoord(int horizontalY)
{
	unit.UpdateYCoord(horizontalY);
}

dwarf::Unit& Ball::GetUnit()
{
	return unit;
}

BallGenerator::BallGenerator()
{
}
 
std::vector<Ball> BallGenerator::GenerateBalls(size_t count)
{
	int positionY = 900;
	std::vector<Ball> balls;

	for (size_t i = 0; i < count; ++i) {
		int randomX = rand() % 801;
		balls.emplace_back("../Assets/Pictures/ball.png", randomX, positionY);
		positionY += 75;
	}

	return balls;
}
