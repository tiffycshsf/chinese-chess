#pragma once
#include"chess.h"
#include"board.h"
class RookChess : public chess
{
public:
	friend class board;
	
	RookChess(int,int,int);
	~RookChess();
	void moveUp(int,int, board & Board); //�W
	void moveHorizon( int,int, board & Board);//��
	void moveBack(int,int, board & Board);//��
	void moveColor(board & Board);
	void check(board & Board);

private:
	int maxLeft, maxRight, maxUp, maxDown;
	COORD coordinates;
	int identity;
	int exist;
};

