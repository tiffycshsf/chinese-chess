#pragma once
#include"chess.h"
#include"board.h"

//象或相
class ElephentChess : public chess {
public:
	friend class board;

	ElephentChess(int, int, int);
	~ElephentChess();
	void moveColor(board & Board);
	void moveUp(int, int, board & Board); //上
	void moveBack(int, int, board & Board);//後

private:
	COORD coordinates;
	int identity;
	int exist;
};