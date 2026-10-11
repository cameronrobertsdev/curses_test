#include <iostream>
#include <string>
#include <stdio.h>
#include <curses.h>
#include <locale.h>
#include "objects.hpp"

//Global Variables
CollisionVolume volumeForTest[1];

Player plyr;

bool gameShouldClose = false;

int MainLoop(){
	Object trees[2];
	trees[0].position = Vector2(50, 8);
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
		DebugDrawCollisionVolumes(plyr.triggerVolumes[0]);
		mvprintw(plyr.position.y, plyr.position.x, plyr.face);
		refresh();
		//DrawDialog("TEST");
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
	//DrawDialog("TEST TEST TEST");
	MainLoop();
	endwin();
}
