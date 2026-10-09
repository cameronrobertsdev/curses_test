#include <iostream>
#include <string>
#include <stdio.h>
#include <curses.h>
#include <locale.h>
#include "objects.hpp"

//Global Variables


bool gameShouldClose = false;


struct Player{
	Vector2 position;
	const char* face = "(.3)";
	const char* faceU = "(.^.)";
	const char* faceD = "('v')";
	const char* faceR = "(.3)";
	const char* faceL = "(ε.)";
	void Move(Vector2 dir);
};


//struct ObjectList{
	//Object[] objects;
	


void Player::Move(Vector2 dir){
	position.x += dir.x;
	position.y += dir.y;
}

void DrawDialogue(const char* inputStr){
	while(1){
		int screenWidth = 10;
		int screenHeight = 3;
	//getmaxyx(stdscr, screenHeight, screenWidth);
		WINDOW* dialogueBox = newwin(3, screenWidth, 0, 0);
		box(dialogueBox, 0, 0);
		mvwprintw(dialogueBox, 1,1,inputStr);
		wrefresh(dialogueBox);
		int input = getch();
		if(input == KEY_UP) break;
	}
}

int MainLoop(){
	Player plyr;
	Object trees[2];
	trees[0].position = Vector2(7, 8);
	trees[1].position = Vector2(31, 19);

	int input;
	while(!gameShouldClose){
		//game logic
		input = getch();
		if(input == KEY_UP){
			clear();
			plyr.face = plyr.faceU;
			plyr.Move(UP_DIR);
		}
		else if(input == KEY_DOWN){
			clear();
			plyr.face = plyr.faceD;
			plyr.Move(DOWN_DIR);
		}
		else if(input == KEY_RIGHT){
			clear();
			plyr.face = plyr.faceR;
			plyr.Move(RIGHT_DIR);
		}
		else if(input == KEY_LEFT){
			clear();
			plyr.face = plyr.faceL;
			plyr.Move(LEFT_DIR);
		}
		DrawObjects(trees,2);
		mvprintw(plyr.position.y, plyr.position.x, plyr.face);
		refresh();
		//DrawDialogue("TEST");
	}
	return 0;

}

void InitCurses(){
	setlocale(LC_ALL, "");
	initscr();
	cbreak();
	noecho();
	noqiflush();
	nodelay(stdscr, true);
	keypad(stdscr, true);
	curs_set(false);
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

int main(){
	InitCurses();
	DrawDialogue("TEST TEST TEST");
	//MainLoop();
	endwin();
}
