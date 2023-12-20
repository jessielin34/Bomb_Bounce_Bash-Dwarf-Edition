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

	std::uniform_int_distribution<int> distance(0, 927);

	for (size_t i = 0; i < count; ++i) {
		int randomX = distance(rand);
		balls.emplace_back("../Assets/Pictures/ball.png", randomX, positionY);
		positionY += 75;
	}

	return balls;
}
