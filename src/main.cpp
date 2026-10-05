#include <iostream>
#include <string>
#include <stdio.h>
#include <curses.h>
#include <locale.h>

//Global Variables

bool gameShouldClose = false;

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

struct Player{
	Vector2 position;
	const char* face = "(.3)";
	const char* faceU = "(.^.)";
	const char* faceD = "('v')";
	const char* faceR = "(.3)";
	const char* faceL = "(ε.)";
	void Move(Vector2 dir);
};

struct Tree{
	Vector2 position;
	int layerCount = 6;
	const char* layers[6] = {"  (   )  ",
													" (   . ) ",
													"( .     )",
													" (   . ) ",
													"   \\║    ",
													"    ║    "};

	void DrawTree();
};

void Tree::DrawTree(){
	for(int i = 0; i < layerCount; i++){
		mvprintw(position.y + i, position.x, layers[i]);
	}
}

void Player::Move(Vector2 dir){
	position.x += dir.x;
	position.y += dir.y;
}

int MainLoop(){
	Player plyr;
	Tree tree;
	Tree tree2;
	tree.position = Vector2(7, 8);
	tree2.position = Vector2(31, 19);

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
		tree.DrawTree();
		tree2.DrawTree();
		mvprintw(plyr.position.y, plyr.position.x, plyr.face);
		refresh();
	}
	return 0;

}

int main(){
	setlocale(LC_ALL, "");

	initscr();
	cbreak();
	noecho();
	noqiflush();
	nodelay(stdscr, true);
	keypad(stdscr, true);
	curs_set(false);
	MainLoop();
	endwin();
	
}
