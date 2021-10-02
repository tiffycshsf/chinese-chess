#pragma once
#include"chess.h"
#include"board.h"

class CannonChess : public chess

{
public:
	friend class board;

	int checkColor(int a, int b, int c, board & Board);
	void check(board & Board);
	bool isEnemy(int, int, board & Board);
	CannonChess(int, int, int);
	~CannonChess();
	void moveColor(board & Board);
	void moveUp(int, int, board & Board); //дW
	void moveHorizon(int, int, board & Board);//ен
	void moveBack(int, int, board & Board);//лс
	int setColor(int a, int b,int c, board & Board);

private:
	COORD coordinates;
	int identity;
	int exist;
	int left, up, down, right;
};

