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
	int screenWidth = 10;
	int screenHeight = 3;
	//getmaxyx(stdscr, screenHeight, screenWidth);
	WINDOW* dialogueBox = newwin(3, screenWidth, 0, 0);
	box(dialogueBox, 0, 0);
	wrefresh(dialogueBox);
	while(1){
		int input = getch();
		if(input == KEY_ENTER) break;
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

int main(){
	InitCurses();
	MainLoop();
	endwin();
	
}
