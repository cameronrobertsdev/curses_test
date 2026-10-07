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

bool IsOverLapping(Object& objA, Object& objB){
	if(objA.position == objB.position){
		return true;
	}
	return false;
}

bool operator==(const Vector2& lhs, const Vector2& rhs){
	return(lhs.x == rhs.x && lhs.y == rhs.y);
}
