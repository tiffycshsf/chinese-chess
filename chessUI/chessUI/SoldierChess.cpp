#include "SoldierChess.h"



SoldierChess::SoldierChess(int a ,int b ,int c) : chess(a,b,c)
{
	identity = a;
	coordinates.X = b;
	coordinates.Y = c;
	exist = 1;
}


SoldierChess::~SoldierChess()
{
	exist = 0;
}

void SoldierChess::check(board & Board)
{
	if (identity > 7)//���� �U��
	{
		//�i���ʨB
		if (coordinates.Y - 2 >= 1) {
			if (Board.nowBoard[coordinates.X][coordinates.Y - 2].chessNum != 0 && coordinates.X < 12)
			{
				if (Board.nowBoard[coordinates.X][coordinates.Y - 2].chessNum <= 7)//���X�l�B���Ĥ�
				{
					//����
					if (Board.nowBoard[coordinates.X][coordinates.Y - 2].chessNum == 1)
					{
						Board.isKing = true;
					}
				}
			}
		}
		
		if (coordinates.Y + 2 <= 17) {
			if (Board.nowBoard[coordinates.X][coordinates.Y + 2].chessNum != 0 && coordinates.X < 12)
			{
				if (Board.nowBoard[coordinates.X][coordinates.Y + 2].chessNum <= 7)//���X�l�B���Ĥ�
				{
					//����
					if (Board.nowBoard[coordinates.X][coordinates.Y + 2].chessNum == 1)
					{
						Board.isKing = true;
					}
				}
			}
		}
		
		if (coordinates.X - 2 >= 2) {
			if (Board.nowBoard[coordinates.X - 2][coordinates.Y].chessNum != 0)//���W
			{
				if (Board.nowBoard[coordinates.X - 2][coordinates.Y].chessNum <= 7)//���X�l�B���Ĥ�
				{
					//����
					if (Board.nowBoard[coordinates.X - 2][coordinates.Y].chessNum == 1)
					{
						Board.isKing = true;
					}
				}

			}
		}
		

	}
	else//�¦�X�l �W��
	{
		if (coordinates.Y - 2 >= 1) {
			if (Board.nowBoard[coordinates.X][coordinates.Y - 2].chessNum != 0 && coordinates.X > 10)//���X�l
			{
				if (Board.nowBoard[coordinates.X][coordinates.Y - 2].chessNum > 7)//����誺��
				{
					//����
					if (Board.nowBoard[coordinates.X][coordinates.Y - 2].chessNum == 1)
					{
						Board.isKing = true;
					}
				}
			}
		}
		
		
		if (coordinates.Y + 2 <= 17) {
			if (Board.nowBoard[coordinates.X][coordinates.Y + 2].chessNum != 0 && coordinates.X > 10)//����
			{
				if (Board.nowBoard[coordinates.X][coordinates.Y + 2].chessNum > 7)//����誺��
				{
					//����
					if (Board.nowBoard[coordinates.X][coordinates.Y + 2].chessNum == 1)
					{
						Board.isKing = true;
					}
				}

			}
		}
		
		if (coordinates.X + 2 <= 20) {
			if (Board.nowBoard[coordinates.X + 2][coordinates.Y].chessNum != 0)
			{
				if (Board.nowBoard[coordinates.X + 2][coordinates.Y].chessNum > 7)//����誺��
				{
					//����
					if (Board.nowBoard[coordinates.X + 2][coordinates.Y].chessNum == 1)
					{
						Board.isKing = true;
					}
				}
			}
		}
		
	}
}

void SoldierChess::moveColor(board & Board)
{
	if (identity > 7)//���� �U��
	{
		
		//�i���ʨB
		if (coordinates.Y - 2 >= 1) {
			if (Board.nowBoard[coordinates.X][coordinates.Y - 2].chessNum != 0 && coordinates.X < 12)
			{
				if (Board.nowBoard[coordinates.X][coordinates.Y - 2].chessNum <= 7)//���X�l�B���Ĥ�
				{
					//����
					Board.nowBoard[coordinates.X][coordinates.Y - 2].colorNum = 5;
				}
			}
			else if (Board.nowBoard[coordinates.X][coordinates.Y - 2].chessNum == 0 && coordinates.X < 12)
			{
				//�Ŧ�
				Board.nowBoard[coordinates.X][coordinates.Y - 2].colorNum = 4;
			}
		}
		
		if (coordinates.Y + 2 <= 17) {
			if (Board.nowBoard[coordinates.X][coordinates.Y + 2].chessNum != 0 && coordinates.X < 12)
			{
				if (Board.nowBoard[coordinates.X][coordinates.Y + 2].chessNum <= 7)//���X�l�B���Ĥ�
				{
					//����
					Board.nowBoard[coordinates.X][coordinates.Y + 2].colorNum = 5;
				}
			}
			else if (Board.nowBoard[coordinates.X][coordinates.Y + 2].chessNum == 0 && coordinates.X < 12)
			{
				//�Ŧ�
				Board.nowBoard[coordinates.X][coordinates.Y + 2].colorNum = 4;
			}
		}

		if (coordinates.X - 2 >= 2) {
			if (Board.nowBoard[coordinates.X - 2][coordinates.Y].chessNum != 0)//���W
			{
				if (Board.nowBoard[coordinates.X - 2][coordinates.Y].chessNum <= 7)//���X�l�B���Ĥ�
				{
					//����
					Board.nowBoard[coordinates.X - 2][coordinates.Y].colorNum = 5;
				}

			}
			else if (Board.nowBoard[coordinates.X - 2][coordinates.Y].chessNum == 0)
			{
				//�Ŧ�
				Board.nowBoard[coordinates.X - 2][coordinates.Y].colorNum = 4;
			}
		}
		
	}
	else//�¦�X�l �W��
	{
		if (coordinates.Y - 2 >= 1) {
			if (Board.nowBoard[coordinates.X][coordinates.Y - 2].chessNum != 0 && coordinates.X > 10)//���X�l
			{
				if (Board.nowBoard[coordinates.X][coordinates.Y - 2].chessNum > 7)//����誺��
				{
					//����
					Board.nowBoard[coordinates.X][coordinates.Y - 2].colorNum = 5;
				}
			}
			else if (Board.nowBoard[coordinates.X][coordinates.Y - 2].chessNum == 0 && coordinates.X > 10)
			{
				//�Ŧ�
				Board.nowBoard[coordinates.X][coordinates.Y - 2].colorNum = 4;
			}
		}

		if (coordinates.Y + 2 <= 17) {
			if (Board.nowBoard[coordinates.X][coordinates.Y + 2].chessNum != 0 && coordinates.X > 10)//����
			{
				if (Board.nowBoard[coordinates.X][coordinates.Y + 2].chessNum > 7)//����誺��
				{
					//����
					Board.nowBoard[coordinates.X][coordinates.Y + 2].colorNum = 5;
				}

			}
			else if (Board.nowBoard[coordinates.X][coordinates.Y + 2].chessNum == 0 && coordinates.X > 10)
			{
				//�Ŧ�
				Board.nowBoard[coordinates.X][coordinates.Y + 2].colorNum = 4;
			}
		}
		
		if (coordinates.X + 2 <= 20) {
			if (Board.nowBoard[coordinates.X + 2][coordinates.Y].chessNum != 0)
			{
				if (Board.nowBoard[coordinates.X + 2][coordinates.Y].chessNum > 7)//����誺��
				{
					//����
					Board.nowBoard[coordinates.X + 2][coordinates.Y].colorNum = 5;
				}
			}
			else if (Board.nowBoard[coordinates.X + 2][coordinates.Y].chessNum == 0)
			{
				//�Ŧ�
				Board.nowBoard[coordinates.X + 2][coordinates.Y].colorNum = 4;
			}
		}
		
	}
}

void SoldierChess::moveUp(int a ,int b, board & Board)
{//����~��
	if (identity > 7)
	{
		if (a == (coordinates.X - 2) && b== coordinates.Y)//�W���@��
		{
			if (Board.nowBoard[a][b].colorNum == 5)
			{
				coordinates.X = a;
				//�Y��
			}
			else if (Board.nowBoard[a][b].colorNum == 4)
			{
				coordinates.X = a;
			}
		}
	}
}
void SoldierChess::moveHorizon(int a, int b, board & Board)
{
	if (a == coordinates.X && abs(b - coordinates.Y) == 2)//���@��Υk�@��
	{
		if (identity > 7 && coordinates.Y < 12)
		{
			if (Board.nowBoard[a][b].colorNum == 5)
			{
				coordinates.Y = b;
			}
			else if (Board.nowBoard[a][b].colorNum == 4)
			{
				coordinates.Y = b;
			}
		}
		else if (identity <= 7 && coordinates.Y > 10)
		{
			if (Board.nowBoard[a][b].colorNum == 5)
			{
				coordinates.Y = b;
			}
			else if (Board.nowBoard[a][b].colorNum == 4)
			{
				coordinates.Y = b;
			}
		}

	}
}


void SoldierChess::moveBack(int a, int b, board & Board)
{
	if (identity <= 7)
	{
		if (a == (coordinates.X - 2) && b == coordinates.Y)//�U���@��
		{
			if (Board.nowBoard[a][b].colorNum == 5)
			{
				coordinates.X = a;
			}
			else if (Board.nowBoard[a][b].colorNum == 4)
			{
				coordinates.X = a;
			}

		}

	}

}
