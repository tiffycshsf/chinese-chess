#pragma once
#include"chess.h"
#include"board.h"
//士或仕
class GeneralChess : public chess {
public:
	GeneralChess(int, int, int);
	~GeneralChess();
	void moveColor(board & Board);
	void moveUp(int, int, board & Board); //上
	void moveBack(int, int, board & Board);//後

	friend class board;
private:
	COORD coordinates;
	int identity;
	int exist;
};
