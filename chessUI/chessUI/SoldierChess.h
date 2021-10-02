#pragma once
#include"chess.h"
#include"board.h"
class SoldierChess: public chess
{
public:
	friend class board;

	SoldierChess(int a,int b,int c);
	~SoldierChess();
	void moveColor(board & Board);
	void moveUp(int, int, board & Board);
	void moveBack(int, int, board & Board);
	void moveHorizon(int, int, board & Board);
	void check(board & Board);
private:
	COORD coordinates;
	int identity;
	int exist;
	//int left, right, up, down;
};

