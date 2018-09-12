#ifndef __BOARD_H__
#define __BOARD_H__

#include <ostream>
#include <fstream>
#include <map>

#include "Player.h"


using namespace std;

#pragma once


class Board
{
public:
	Board(int m = 10);
	~Board(void);
	int Size() { return n; };
	string toString(int x,  int y);

	/*Inserting a player with given position
	cannot override existing player or position*/
	bool Insert(int id, int x, int y);

	/*Remove a player by given ID
	throws exception if ID is non-existent*/
	bool Remove(int id);

	/*Find player by ID*/
	bool Find(int id);

	/*Move existing player to given position
	If there is another player in the given position, it deletes the player in position
	uses Remove() and Insert()*/
	bool MoveTo (int id, int x2, int y2);

	/*Print all existing player increasing in ID 
	Also prints how many player is in the board*/
	void PrintByID();
	

private:
	int m;
	int n;

	map<int, Player> player;
	map<string, int> position;

};
#endif