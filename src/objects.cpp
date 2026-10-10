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

void Player::TriggerVolumeCheck(CollisionVolume triggerVolumes[], int volumeCount){
	for(int i = 0; i < volumeCount; i++){
		if(IsOverLapping(position, triggerVolumes[i].bounds)){
			if(triggerVolumes[i].triggerAuto && !triggerVolumes[i].hasBeenTriggered){
					triggerVolumes[i].OnVolumeEntered();
			}
		}
	}
}

void CollisionVolume::OnVolumeEntered(){
	//Show message etc.
}

void TestCollisions(){
	Vector2 posA = Vector2(5, 5);
	Vector2 posB = Vector2(5,5);
	Vector2 posC = Vector2(0,50);
	Bounds boundsA = Bounds(Vector2(0,0),Vector2(30,30));
	Bounds boundsB = Bounds(Vector2(9,9),Vector2(30,30));
	Bounds boundsC = Bounds(Vector2(33,33),Vector2(40,40));

	if(IsOverLapping(posA,posB)) printf("posA and posB are overlapping\n");
	else printf("posA and posB are not overlapping\n");

	if(IsOverLapping(posA, boundsA)) printf("posA is inside boundsA\n");
	else printf("posA is not inside boundsA\n");
	
	if(IsOverLapping(posC, boundsA)) printf("posC is inside boundsA\n");
	else printf("posC is not inside boundsA\n");

	if(IsOverLapping(boundsB, boundsA)) printf("boundsB is overlapping boundsA\n");
	else printf("boundsB is not overlapping boundsA\n");

	if(IsOverLapping(boundsC, boundsA)) printf("boundsC is overlapping boundsA\n");
	else printf("boundsC is not overlapping boundsA\n");
}

void DrawDialog(const char* inputStr){
	bool playerStillReading = true;
	while(playerStillReading){
		int screenWidth = 10;
		int screenHeight = 3;
		getmaxyx(stdscr, screenHeight, screenWidth);
		WINDOW* dialogBox = newwin(3, screenWidth, 0, 0);
		box(dialogBox, 0, 0);
		mvwprintw(dialogBox, 1,1,inputStr);
		wrefresh(dialogBox);
		int input = getch();
		if(input == KEY_UP){
			wclear(dialogBox);
			playerStillReading = false;
		}
	}
}
