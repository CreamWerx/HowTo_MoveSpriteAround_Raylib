#pragma once
class Types
{
public:
	struct Point
	{
		int x;
		int y;
	};

	struct MovementState
	{
		Vector2 direction = { 0.0f, 0.0f };
		float aimAgle = 0.0f;
	};
};