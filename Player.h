#ifndef _PLAYER_H_
#define _PLAYER_H_

#include <iostream>
#include <exception>
#include <string> 
#include <sstream>

using namespace std;
#pragma once

class Player
{
public:
	Player(int id, int x, int y);

	~Player(void) {};

	
	const int getid() {return id; };
	const int getX() {return x;};
	const int getY() {return y;};
	const string getPosition() {return pos;};

	string toString(int x, int y);
	
private:
	int id;
	int x;
	int y;
	string pos;
};
#endif