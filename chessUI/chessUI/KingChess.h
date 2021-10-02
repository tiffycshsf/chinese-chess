#pragma once
#include"chess.h"
#include"board.h"

//將或帥
class KingChess : public chess {
public:
	friend class board;

	KingChess(int, int, int);
	~KingChess();
	void moveColor(board & Board);
	void moveUp(int, int, board & Board); //上
	void moveHorizon(int, int, board & Board); //左右
	void moveBack(int, int, board & Board);//後
	void Check(board & Board);

private:
	COORD coordinates;
	int identity;
	int exist;
};
