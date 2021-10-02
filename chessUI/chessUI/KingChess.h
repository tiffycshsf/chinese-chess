#pragma once
#include"chess.h"
#include"board.h"

//�N�Ϋ�
class KingChess : public chess {
public:
	friend class board;

	KingChess(int, int, int);
	~KingChess();
	void moveColor(board & Board);
	void moveUp(int, int, board & Board); //�W
	void moveHorizon(int, int, board & Board); //���k
	void moveBack(int, int, board & Board);//��
	void Check(board & Board);

private:
	COORD coordinates;
	int identity;
	int exist;
};
