#include "Player.h"

Player::Player(int id, int x, int y)
{
		 this->id = id;
		 this->x = x;
		 this->y = y;
		 this->pos = toString(x, y);
}

string Player::toString(int x, int y)
{
	stringstream input;
	input<<"("<<x<<","<<y<<")";
	return input.str();
}

