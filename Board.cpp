#include "Board.h"

ofstream out("testresult.txt");	
Board::Board(int m)
{
	cout << "Board of: " << m << "*" << m << " created" << endl;
	out << "Board of: " << m << "*" << m << " created" << endl;
	this->m = m;
	n = 0;
}


Board::~Board(void)
{
	m = 0;
	n = 0;
	player.clear();
	position.clear();
}

string Board::toString(int x, int y)
{
	stringstream ss;
	ss << "(" << x << "," << y << ")";
	return ss.str();
}

bool Board::Insert (int id, int x, int y)
{
	string location=toString(x,y);
	cout << endl << "inserting " << id << " at " << location << endl;
	out << endl << "inserting " << id << " at " << location << endl;

	// check if full
	if (n>=m)
	{
		cout << "board full" << endl;
		out << "board full" << endl;
		return false;
	}

	// check if input in board
	if ( x>m || y>m )
	{	
		cout << "input out of bounds" << endl;
		out << "input out of bounds" << endl;
		return false;
	}

	// check if ID used twice
	if (player.find(id)!=player.end())
	{	
		cout << "ID has been used" << endl;
		out << "ID has been used" << endl;
		return false;
	}
	
	// check if Location used twice, only able to delete from moveto
	if (position.find(location)!=position.end())
	{	
		cout << "Location invalid" << endl;
		out << "Location invalid" << endl;
		return false;
	}

	else
	{
		Player tmp(id,x,y);
		player.insert( pair<int, Player> (id, tmp));
		cout << "inserted " << id << " at " << location << endl;
		out << "inserted " << id << " at " << location << endl;

		position.insert(pair<string,int>(location,id));	
		n++;
		return true;
	}

}

bool Board::Remove(int id)
{
	cout << endl << "Removing Player " << id << endl;
	out << endl << "Removing Player " << id << endl;
	map<int,Player>::iterator it;
	it=player.find(id);
	
	// check if the ID exist
	if (it==player.end())
	{	
		cout << "ID invalid" << endl;
		out << "ID invalid" << endl;
		return false;
	}
	else 
	{
		string location=(*it).second.getPosition();

		cout << "Removed Player " << id << " at " << location << endl;
		out << "Removed Player " << id << " at " << location << endl;
		player.erase(it);
		position.erase(location);
		n--; // decrease n by 1
		
		return true;
	}

}

bool Board::Find( int id)
{
	return player.find(id)!=player.end();
}

bool Board::MoveTo(int id, int x2,int y2)
{
	string location=toString(x2,y2);
	cout << endl << "Moving player: " << id << " to " << location << endl;
	out << endl << "Moving player: " << id << " to " << location << endl;
	map<int,Player>::iterator it;
	it=player.find(id);

	// check if input in board
	if(x2>m || y2>m)
	{	
		cout << "Input out of bounds" << endl;
		out << "Input out of bounds" << endl;
		return false;
	}

	// check if ID exist
	if (it==player.end())
	{	
		cout << "ID invalid" << endl;
		out << "ID invalid" << endl;
		return false;
	}
	// check if move legal by checkng if it is in the same x or y or it is in a graient of slope 1 or -1
	else 
	{
		int x1=(*it).second.getX();
		int y1=(*it).second.getY();


		double slope=0;
		if (x1!=x2)
		{
			slope= (double)(y2-y1)/(double)(x2-x1);
		}
		// check if invalid
		if (x1!=x2 && y1!=y2 && slope!=1 && slope!=-1) 
		{	
			cout << "Movement invalid" << endl;
			out << "Movement invalid" << endl;
			return false;
		}

		else
		{
			map<string,int>::iterator it2;
			it2=position.find(location);

			if (it2!=position.end())
			{	
				cout << "A player is in " << location << endl << "Initiating remove" << endl;
				out << "A player is in " << location << endl << "Initiating remove" << endl;
				int id2=(*it2).second;
				Remove (id2);
			}
			Remove(id);
			Insert(id,x2,y2);
			return true;
		}
	}
	
}

void Board::PrintByID()
{
	cout << endl << n << " Players on board: " << endl;
	out << endl << n << " Players on board: " << endl;

	// check the tree from beginning to end and loop
	for (map<int, Player>::iterator it = player.begin(); it != player.end(); it++) {
		cout << (*it).first << " at " << (*it).second.getPosition() << endl;
		out << (*it).first << " at " << (*it).second.getPosition() << endl;
	}
		
}
