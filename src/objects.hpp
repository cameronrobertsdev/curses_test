// objects.hpp
// Cameron Roberts 2026
#pragma once

struct Vector2{
	int x = 0;
	int y = 0;
	Vector2() : x{0}, y{0} {};
	Vector2(int xVal, int yVal) : x{xVal}, y{yVal} {};
};

const Vector2 UP_DIR = Vector2(0,-1);
const Vector2 DOWN_DIR = Vector2(0,1);
const Vector2 LEFT_DIR = Vector2(-1,0);
const Vector2 RIGHT_DIR = Vector2(1,0);

struct Object{
	Vector2 position;
	int layerCount = 6;
	const char* layers[6] = {"  (   )  ",
													" (   . ) ",
													"( .     )",
													" (   . ) ",
													"   \\║    ",
													"    ║    "};

	void Draw();
};

void DrawObjects(Object objs[], int objectCount);

bool IsOverLapping(Object& objA, Object& objB);

bool operator==(const Vector2& lhs, const Vector2& rhs);
