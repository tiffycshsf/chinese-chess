#pragma once
#include"chess.h"
#include"board.h"

//�H�ά�
class ElephentChess : public chess {
public:
	friend class board;

	ElephentChess(int, int, int);
	~ElephentChess();
	void moveColor(board & Board);
	void moveUp(int, int, board & Board); //�W
	void moveBack(int, int, board & Board);//��

private:
	COORD coordinates;
	int identity;
	int exist;
};