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
	if (Board.nowBoard[a][b].chessNum != 0)//有旗子
	{
		if (c == 1)//前面已經有棋子
		{
			c = 2;
			if (isEnemy(a, b, Board))
			{
				if (Board.nowBoard[a][b].chessNum == 1|| Board.nowBoard[a][b].chessNum == 8)
				{
					Board.isKing = true;
				}
				//紅色
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
	for (int i = coordinates.Y - 2; i >= 1; i -= 2)//往左
	{
		left = checkColor(coordinates.X, i, left, Board);
		if (left == 2)
		{
			break;
		}
	}

	for (int i = coordinates.Y + 2; i <= 17; i += 2)//往右
	{
		right = checkColor(coordinates.X, i, right, Board);
		if (right == 2)
		{
			break;
		}
	}

	for (int i = coordinates.X - 2; i >= 2; i -= 2)//往上
	{
		up = checkColor(i, coordinates.Y, up, Board);
		if (up == 2)
		{
			break;
		}
	}

	for (int i = coordinates.X + 2; i <= 20; i += 2)//往下
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
			return 1;//步同陣營
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
		//藍色
		Board.nowBoard[a][b].colorNum = 4;
	}
	else if(Board.nowBoard[a][b].chessNum != 0)//有旗子
	{
		if (c==1)//前面已經有棋子
		{
			c = 2;
			if (isEnemy(a,b, Board))
			{
				//紅色
				Board.nowBoard[a][b].colorNum = 5;
			}
			else
			{
				//無效
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
	for (int i = coordinates.Y - 2; i >= 1; i -= 2)//往左
	{
		left = setColor(coordinates.X, i,left, Board);
		if (left==2)
		{
			break;
		}
	}

	for (int i = coordinates.Y + 2; i <= 17; i += 2)//往右
	{
		right = setColor(coordinates.X, i, right, Board);
		if (right == 2)
		{
			break;
		}
	}

	for (int i = coordinates.X - 2; i >= 2; i -= 2)//往上
	{
		up = setColor(i, coordinates.Y, up, Board);
		if (up == 2)
		{
			break;
		}
	}

	for (int i = coordinates.X + 2; i <= 20; i += 2)//往下
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
			//吃棋
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
			//吃棋
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
			//吃棋
		}
		else if (Board.nowBoard[a][b].colorNum == 4)
		{
			coordinates.X = a;
		}
	}
}
