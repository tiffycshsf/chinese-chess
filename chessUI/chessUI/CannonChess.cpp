#include "CannonChess.h"



CannonChess::CannonChess(int a ,int b,int c):chess(a,b,c)
{
	left = 0;
	up = 0;
	down = 0;
	right = 0;
	identity = a;
	coordinates.X = b;
	coordinates.Y = c;
	exist = 1;
}


CannonChess::~CannonChess()
{
	exist = 0;
}


int CannonChess::checkColor(int a, int b, int c, board & Board)
{
	if (Board.nowBoard[a][b].chessNum != 0)//���X�l
	{
		if (c == 1)//�e���w�g���Ѥl
		{
			c = 2;
			if (isEnemy(a, b, Board))
			{
				if (Board.nowBoard[a][b].chessNum == 1|| Board.nowBoard[a][b].chessNum == 8)
				{
					Board.isKing = true;
				}
				//����
			}
		}
		if (c == 0)
		{
			c = 1;
		}

	}
	return c;
}

void CannonChess::check(board & Board)
{
	for (int i = coordinates.Y - 2; i >= 1; i -= 2)//����
	{
		left = checkColor(coordinates.X, i, left, Board);
		if (left == 2)
		{
			break;
		}
	}

	for (int i = coordinates.Y + 2; i <= 17; i += 2)//���k
	{
		right = checkColor(coordinates.X, i, right, Board);
		if (right == 2)
		{
			break;
		}
	}

	for (int i = coordinates.X - 2; i >= 2; i -= 2)//���W
	{
		up = checkColor(i, coordinates.Y, up, Board);
		if (up == 2)
		{
			break;
		}
	}

	for (int i = coordinates.X + 2; i <= 20; i += 2)//���U
	{
		down = checkColor(i, coordinates.Y, down, Board);
		if (down == 2)
		{
			break;
		}
	}
}

bool CannonChess::isEnemy(int a, int b, board & Board)
{
	if (identity > 7)
	{
		if (Board.nowBoard[a][b].chessNum <= 7)
		{
			return 1;//�B�P�}��
		}
		else
		{
			return 0;
		}
	}
	else
	{
		if (Board.nowBoard[a][b].chessNum > 7)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
}

int CannonChess::setColor(int a, int b,int c, board & Board)
{
	
	if (Board.nowBoard[a][b].chessNum == 0 && c == 0)
	{
		//�Ŧ�
		Board.nowBoard[a][b].colorNum = 4;
	}
	else if(Board.nowBoard[a][b].chessNum != 0)//���X�l
	{
		if (c==1)//�e���w�g���Ѥl
		{
			c = 2;
			if (isEnemy(a,b, Board))
			{
				//����
				Board.nowBoard[a][b].colorNum = 5;
			}
			else
			{
				//�L��
			}
		}
		if (c==0)
		{
			c = 1;
		}

	}
	return c;
}

void CannonChess::moveColor(board & Board)
{
	for (int i = coordinates.Y - 2; i >= 1; i -= 2)//����
	{
		left = setColor(coordinates.X, i,left, Board);
		if (left==2)
		{
			break;
		}
	}

	for (int i = coordinates.Y + 2; i <= 17; i += 2)//���k
	{
		right = setColor(coordinates.X, i, right, Board);
		if (right == 2)
		{
			break;
		}
	}

	for (int i = coordinates.X - 2; i >= 2; i -= 2)//���W
	{
		up = setColor(i, coordinates.Y, up, Board);
		if (up == 2)
		{
			break;
		}
	}

	for (int i = coordinates.X + 2; i <= 20; i += 2)//���U
	{
		down = setColor(i, coordinates.Y, down, Board);
		if (down == 2)
		{
			break;
		}
	}
}

void CannonChess::moveUp(int a, int b, board & Board)
{
	if (a < coordinates.X && b == coordinates.Y)
	{
		if (Board.nowBoard[a][b].colorNum == 5)
		{
			coordinates.X = a;
			if (Board.nowBoard[a][b].chessNum == 1 || Board.nowBoard[a][b].chessNum == 8)
			{
				Board.isWin = true;
			}
			//�Y��
		}
		else if (Board.nowBoard[a][b].colorNum == 4)
		{
			coordinates.X = a;
		}
	}
}

void CannonChess::moveHorizon(int a, int b, board & Board)
{
	if (a == coordinates.X)
	{
		if (Board.nowBoard[a][b].colorNum == 5)
		{
			coordinates.Y = b;
			if (Board.nowBoard[a][b].chessNum == 1 || Board.nowBoard[a][b].chessNum == 8)
			{
				Board.isWin = true;
			}
			//�Y��
		}
		else if (Board.nowBoard[a][b].colorNum == 4)
		{
			coordinates.Y = b;
		}
	}
}

void CannonChess::moveBack(int a, int b, board & Board)
{
	if (a > coordinates.X && b == coordinates.Y)
	{
		if (Board.nowBoard[a][b].colorNum == 5)
		{
			coordinates.X = a;
			if (Board.nowBoard[a][b].chessNum == 1 || Board.nowBoard[a][b].chessNum == 8)
			{
				Board.isWin = true;
			}
			//�Y��
		}
		else if (Board.nowBoard[a][b].colorNum == 4)
		{
			coordinates.X = a;
		}
	}
}
