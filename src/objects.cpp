// objects.cpp
// Cameron Roberts 2026
#include "objects.hpp"
#include <curses.h>

void Object::Draw(){
	for(int i = 0; i < layerCount; i++){
		mvprintw(position.y + i, position.x, layers[i]);
	}
}

void DrawObjects(Object objs[], int objectCount){
	for(int i = 0; i < objectCount; i++){
		objs[i].Draw();
	}
}

void Player::Move(Vector2 dir){
	position.x += dir.x;
	position.y += dir.y;
}

bool IsOverLapping(Vector2& posA, Vector2& posB){
	return posA == posB;
}


bool IsOverLapping(Vector2& pos, Bounds& bounds){
	if(pos.x >= bounds.topLeft.x && pos.x <= bounds.bottomRight.x){
		if(pos.y >= bounds.topLeft.y && pos.y <= bounds.bottomRight.y){
			return true;
		}
	}
	return false;
}

bool IsOverLapping(Bounds& boundsA, Bounds& boundsB){
	return IsOverLapping(boundsA.topLeft, boundsB) || 
		IsOverLapping(boundsA.bottomRight, boundsB);
}

bool operator==(const Vector2& lhs, const Vector2& rhs){
	return(lhs.x == rhs.x && lhs.y == rhs.y);
}
