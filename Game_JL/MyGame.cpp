#include "MyGame.h"

MyGame::MyGame()
{
	SetKeyPressedCallback([this](const dwarf::KeyPressed& e) {OnKeyPress(e); });
	mRenderer.Init();
	BallGenerator ballGenerator;
	balls = ballGenerator.GenerateBalls(500); //Generate x balls
	BombGenerator bombGenerator; 
	bombs = bombGenerator.GenerateBombs(50);
}

void MyGame::OnUpdate()
{
	mRenderer.Clear(); 
	Draw(background);

	if (gameEnd) {
		if (bombCollision) { //if character touches bomb then display a bomb image
			Draw(explosion);
		}
		else{ //otherwise, draw game over
			over.SetCoords(300, 250); 
			Draw(over); 
		}

		return;
	}

	time++;

	for (size_t i = 0; i < balls.size(); i++) {
		if (time > (i * 100)) {
			int ballSpeed = 3;
			balls[i].UpdateYCoord(-ballSpeed);

			if (dwarf::UnitsOverlap(dwarfs, balls[i].GetUnit())) {
				balls.erase(balls.begin() + i);
				score += 1;
			}

			if (balls[i].GetUnit().GetYCoord() < 0) {
				gameEnd = true;
				playAgain = true;
				break;
			}
		}
	}

	for (size_t i = 0; i < bombs.size(); i++) {
		if (time > (i * 150)) {
			int bombspeed = 2;
			bombs[i].UpdateYCoord(-bombspeed);
			if (dwarf::UnitsOverlap(dwarfs, bombs[i].GetUnit())) {
				gameEnd = true;
				playAgain = true;
				bombCollision = true;
				break;
			}
		}
	}

	if (!gameEnd) {
		Draw(dwarfs); 
		for (auto& b : balls) {
			dwarf::Unit& ballUnit = b.GetUnit();
			Draw(ballUnit);
		}
		for (auto& b : bombs) {
			dwarf::Unit& bombUnit = b.GetUnit();
			Draw(bombUnit);
		}
		std::cout << "Score: " << score << std::endl;
	}
}

void MyGame::OnKeyPress(const dwarf::KeyPressed& e)
{
	if (!gameEnd) {
		if (e.GetKeyCode() == DWARF_KEY_RIGHT) {
			if (dwarfs.GetXCoord() + 25 < 925) {
				dwarfs.UpdateXCoord(50);
			}
		}
		else if (e.GetKeyCode() == DWARF_KEY_LEFT) {
			if (dwarfs.GetXCoord() - 25 > 0) {
				dwarfs.UpdateXCoord(-50);
			}
		}
	}
	if (playAgain && e.GetKeyCode() == DWARF_KEY_SPACE) {
		RestartGame();
	}
}

void MyGame::RestartGame()
{
	time = 0;
	gameEnd = false;
	playAgain = false;
	bombCollision = false;
	score = 0;
	dwarfs.SetCoords(50, 60);
	balls.clear();
	bombs.clear();
	BallGenerator ballGenerator;
	balls = ballGenerator.GenerateBalls(500); //Generate x balls
	BombGenerator bombGenerator; 
	bombs = bombGenerator.GenerateBombs(50); 
}
