// objects.hpp
// Cameron Roberts 2026
#pragma once

struct Vector2{
	int x = 0;
	int y = 0;
	Vector2() : x{0}, y{0} {};
	Vector2(int xVal, int yVal) : x{xVal}, y{yVal} {};
};

struct Bounds{
	Vector2 topLeft;
	Vector2 bottomRight;
	Bounds(Vector2 tL, Vector2 bR) : topLeft{tL}, bottomRight{bR} {};
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

struct Player{
	Vector2 position;
	const char* face = "(.3)";
	const char* faceU = "(.^.)";
	const char* faceD = "('v')";
	const char* faceR = "(.3)";
	const char* faceL = "(ε.)";
	void Move(Vector2 dir);
};


void DrawObjects(Object objs[], int objectCount);

bool IsOverLapping(Vector2& posA, Vector2& posB);

bool IsOverLapping(Vector2& pos, Bounds& bounds);

bool IsOverLapping(Bounds& boundsA, Bounds& boundsB);

bool operator==(const Vector2& lhs, const Vector2& rhs);
