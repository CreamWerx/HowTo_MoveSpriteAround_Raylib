#pragma once
#include "GameTypes.hpp"
#include "Ship.hpp"

class Game
{
public:
	
	Vector2 CenterScreenV;
	int screenWidth = 1200;
	int screenHeight = 800;
	// Because / 2 may be a float, not pixel perfect
	Types::Point CenterScreenP = { screenWidth, screenHeight };

	bool paused = false, gameOver = false;
	Ship ship;

	Game() //: screenWidth(width), screenHeight(height)
	{
		
	}

	void DrawGameOver()
	{

	}

	void DrawMain() 
	{
		ship.Draw();
	}

	bool Setup()
	{
		CenterScreenV.x = screenWidth / 2;
		CenterScreenV.y = screenHeight / 2;
		CenterScreenP.x = screenWidth / 2;
		CenterScreenP.y = screenHeight / 2;
		ship.Load(CenterScreenP);

		return ship.image.id > 0;
	}

	void Update()
	{
		ship.Update();
	}

	void ProcessEvents()
	{

	}
};
