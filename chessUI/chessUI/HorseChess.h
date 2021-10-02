#pragma once
#include"chess.h"
#include"board.h"

class HorseChess : public chess
{
public:
	friend class board;

	void check(board & Board);
	bool isEnemy(int, int, board & Board);
	HorseChess(int ,int,int);
	~HorseChess();
	void moveColor(board & Board);
	void moveUp(int, int, board & Board); //дW
	void moveHorizon(int, int, board & Board);//ен
	void moveBack(int, int, board & Board);//лс

private:
	COORD coordinates;
	int identity;
	int exist;
};

