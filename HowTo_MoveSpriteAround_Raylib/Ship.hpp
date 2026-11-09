#pragma once

#include <format>
#include <math.h>
#include <raylib.h>
#include "GameTypes.hpp"

class Ship
{
private:
	std::string textRotation = "0.00";
	std::string textPropulsion = "0.00";

	float rotation = 0.00;
	float rotationSpeed = 100.0f;
	Rectangle source;
	Rectangle dest;
	float direction = 0.0f;
public:
	Texture2D image;
	Types::Point currentPosition;
	Vector2 imageCenter;
	Vector2 mouseWheelMoveV;

	float speed = 200.0f;

	Ship()
	{

	}
	~Ship()
	{
		UnloadTexture(image);
	}

	void Load(Types::Point& centerScreen)
	{
		currentPosition = centerScreen;
		imageCenter.x = (float)currentPosition.x;
		imageCenter.y = (float)currentPosition.y;
		image = LoadTexture("ships/voyagertiny.png");
		textRotation = std::format("{:.2f}", rotation);
		source = { 0.0f, 0.0f, (float)image.width, (float)image.height };
		dest = { (float)currentPosition.x, (float)currentPosition.y, (float)image.width, (float)image.height };
	}

	void Update()
	{
		currentPosition.x = GetMouseX() - (image.width / 2);
		currentPosition.y = GetMouseY() - (image.height / 2);
		imageCenter.x = (float)currentPosition.x;
		imageCenter.y = (float)currentPosition.y;
		mouseWheelMoveV = GetMouseWheelMoveV();

#pragma region Rotation
		rotation += mouseWheelMoveV.x;
		if (rotation >= 360.0f) rotation -= 360.0f;
		if (rotation < 0.0f)    rotation += 360.0f;
#pragma endregion
#pragma region Propulsion
		if (mouseWheelMoveV.y > 0.0f)
		{
			direction = -1.0f;
		}
		else if (mouseWheelMoveV.y < 0.0f)
		{
			direction = 1.0f;
		}
		else
		{
			direction = 0.0f;
		}

		if (direction != 0.0f)
		{

			float radians = (rotation -90.0f) * DEG2RAD;

			float dirX = cosf(radians);
			float dirY = sinf(radians);

			dest.x += dirX * speed * direction * GetFrameTime();
			dest.y += dirY * speed * direction * GetFrameTime();
		}

		if (IsKeyPressed(KEY_SPACE))
		{
			rotation = 0.0f;
		}
		textRotation = std::format("{:.2f}", rotation);
		textPropulsion = std::format("{:.2f}", direction);
#pragma endregion
	}

	void Draw()
	{
		Vector2 origin = { image.width / 2.0f, image.height / 2.0f };
		DrawText(textRotation.c_str(), 10, 10, 30, RAYWHITE);
		DrawText(textPropulsion.c_str(), 10, 50, 30, RAYWHITE);

		DrawTexturePro(image, source, dest, origin, rotation, WHITE);
	}
};