#pragma once
#include"chess.h"
#include"board.h"
//�h�ΥK
class GeneralChess : public chess {
public:
	GeneralChess(int, int, int);
	~GeneralChess();
	void moveColor(board & Board);
	void moveUp(int, int, board & Board); //�W
	void moveBack(int, int, board & Board);//��

	friend class board;
private:
	COORD coordinates;
	int identity;
	int exist;
};
