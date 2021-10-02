#include "HorseChess.h"



void HorseChess::check(board & Board)
{
	if (coordinates.X - 2 >= 2 && Board.nowBoard[coordinates.X - 2][coordinates.Y].chessNum == 0)//��ΤW�L���}
	{
		if (coordinates.X - 4 >= 2 && coordinates.Y - 2 >= 1) {
			if (Board.nowBoard[coordinates.X - 4][coordinates.Y - 2].chessNum != 0)//���W�馳�X�l
			{
				if (isEnemy(coordinates.X - 4, coordinates.Y - 2, Board))
				{
					if (Board.nowBoard[coordinates.X - 4][coordinates.Y - 2].chessNum == 1 || Board.nowBoard[coordinates.X - 4][coordinates.Y - 2].chessNum == 8)
					{
						Board.isKing = true;
					}
				}
			}
		}
		if (coordinates.X - 4 >= 2 && coordinates.Y + 2 <= 17) {
			if (Board.nowBoard[coordinates.X - 4][coordinates.Y + 2].chessNum != 0)//�k�W�馳�X�l
			{
				if (isEnemy(coordinates.X - 4, coordinates.Y + 2, Board))
				{
					if (Board.nowBoard[coordinates.X - 4][coordinates.Y + 2].chessNum == 1 || Board.nowBoard[coordinates.X - 4][coordinates.Y + 2].chessNum == 8)
					{
						Board.isKing = true;
					}
				}
			}
		}
		
	}


	if (coordinates.X + 2 <= 20 && Board.nowBoard[coordinates.X + 2][coordinates.Y].chessNum == 0)
	{
		if (coordinates.X + 4 <= 20 && coordinates.Y - 2 >= 1) {
			if (Board.nowBoard[coordinates.X + 4][coordinates.Y - 2].chessNum != 0)//���U�馳�X�l
			{
				if (isEnemy(coordinates.X + 4, coordinates.Y - 2, Board))
				{
					if (Board.nowBoard[coordinates.X + 4][coordinates.Y - 2].chessNum == 1 || Board.nowBoard[coordinates.X + 4][coordinates.Y - 2].chessNum == 8)
					{
						Board.isKing = true;
					}
				}
			}
		}
		
		if (coordinates.X + 4 <= 20 && coordinates.Y + 2 <= 17) {
			if (Board.nowBoard[coordinates.X + 4][coordinates.Y + 2].chessNum != 0)//�k�U�馳�X�l
			{
				if (isEnemy(coordinates.X + 4, coordinates.Y + 2, Board))
				{
					if (Board.nowBoard[coordinates.X + 4][coordinates.Y + 2].chessNum == 1 || Board.nowBoard[coordinates.X + 4][coordinates.Y + 2].chessNum == 8)
					{
						Board.isKing = true;
					}
				}
			}
		}
		

	}

	if (coordinates.Y - 2 >= 1 && Board.nowBoard[coordinates.X][coordinates.Y - 2].chessNum == 0)//���L���}
	{
		if (coordinates.X - 2 >= 2 && coordinates.Y - 4 >= 1) {
			if (Board.nowBoard[coordinates.X - 2][coordinates.Y - 4].chessNum != 0)//����
			{
				if (isEnemy(coordinates.X - 2, coordinates.Y - 4, Board))
				{
					if (Board.nowBoard[coordinates.X - 2][coordinates.Y - 4].chessNum == 1 || Board.nowBoard[coordinates.X - 2][coordinates.Y - 4].chessNum == 8)
					{
						Board.isKing = true;
					}

				}
			}
		}
		
		if (coordinates.X + 2 <= 20 && coordinates.Y - 4 >= 1) {
			if (Board.nowBoard[coordinates.X + 2][coordinates.Y - 4].chessNum != 0)//����
			{
				if (isEnemy(coordinates.X + 2, coordinates.Y - 4, Board))
				{
					if (Board.nowBoard[coordinates.X + 2][coordinates.Y - 4].chessNum == 1 || Board.nowBoard[coordinates.X + 2][coordinates.Y - 4].chessNum == 8)
					{
						Board.isKing = true;
					}

				}
			}
		}
		
	}

	if (coordinates.Y + 2 <= 17 && Board.nowBoard[coordinates.X][coordinates.Y + 2].chessNum == 0)//�k�L���}
	{
		if (coordinates.X - 2 >= 2 && coordinates.Y + 4 <= 17) {
			if (Board.nowBoard[coordinates.X - 2][coordinates.Y + 4].chessNum != 0)//����
			{
				if (isEnemy(coordinates.X - 2, coordinates.Y + 4, Board))
				{
					if (Board.nowBoard[coordinates.X - 2][coordinates.Y + 4].chessNum == 1 || Board.nowBoard[coordinates.X - 2][coordinates.Y + 4].chessNum == 8)
					{
						Board.isKing = true;
					}
				}
			}
		}
		
		if (coordinates.X + 2 <= 20 && coordinates.Y + 4 <= 17) {
			if (Board.nowBoard[coordinates.X + 2][coordinates.Y + 4].chessNum != 0)//����
			{
				if (isEnemy(coordinates.X + 2, coordinates.Y + 4, Board))
				{
					if (Board.nowBoard[coordinates.X + 2][coordinates.Y + 4].chessNum == 1 || Board.nowBoard[coordinates.X + 2][coordinates.Y + 4].chessNum == 8)
					{
						Board.isKing = true;
					}
				}
			}
		}
		
	}
}

HorseChess::HorseChess(int a, int b, int c) :chess(a, b, c)
{
	identity = a;
	coordinates.X = b;
	coordinates.Y = c;
	exist = 1;
}


HorseChess::~HorseChess()
{
	exist = 0;
}

bool HorseChess::isEnemy(int a, int b, board & Board)
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

void HorseChess::moveColor(board & Board)
{
	//--------------���
	
	if(coordinates.X - 2 >= 2 && Board.nowBoard[coordinates.X - 2][coordinates.Y].chessNum == 0)//��ΤW�L���}
	{
		if (coordinates.X - 4 >= 2 && coordinates.Y - 2 >= 1) {
			if (Board.nowBoard[coordinates.X - 4][coordinates.Y - 2].chessNum != 0)//���W�馳�X�l
			{
				if (isEnemy(coordinates.X - 4, coordinates.Y - 2, Board))
				{
					//����
					Board.nowBoard[coordinates.X - 4][coordinates.Y - 2].colorNum = 5;
				}
			}
			else
			{
				//�Ŧ�
				Board.nowBoard[coordinates.X - 4][coordinates.Y - 2].colorNum = 4;
			}
		}
		
		if (coordinates.X - 4 >= 2 && coordinates.Y + 2 <= 17) {
			if (Board.nowBoard[coordinates.X - 4][coordinates.Y + 2].chessNum != 0)//�k�W�馳�X�l
			{
				if (isEnemy(coordinates.X - 4, coordinates.Y + 2, Board))
				{
					//����
					Board.nowBoard[coordinates.X - 4][coordinates.Y + 2].colorNum = 5;
				}
			}
			else
			{
				//�Ŧ�
				Board.nowBoard[coordinates.X - 4][coordinates.Y + 2].colorNum = 4;
			}
		}
		
	}


	if(coordinates.X + 2 <= 20 && Board.nowBoard[coordinates.X + 2][coordinates.Y].chessNum == 0)
	{
		if (coordinates.X + 4 <= 20 && coordinates.Y - 2 >= 1) {
			if (Board.nowBoard[coordinates.X + 4][coordinates.Y - 2].chessNum != 0)//���U�馳�X�l
			{
				if (isEnemy(coordinates.X + 4, coordinates.Y - 2, Board))
				{
					//����
					Board.nowBoard[coordinates.X + 4][coordinates.Y - 2].colorNum = 5;
				}
			}
			else
			{
				//�Ŧ�
				Board.nowBoard[coordinates.X + 4][coordinates.Y - 2].colorNum = 4;
			}
		}

		if (coordinates.X + 4 <= 20 && coordinates.Y + 2 <= 17) {
			if (Board.nowBoard[coordinates.X + 4][coordinates.Y + 2].chessNum != 0)//�k�U�馳�X�l
			{
				if (isEnemy(coordinates.X + 4, coordinates.Y + 2, Board))
				{
					//����
					Board.nowBoard[coordinates.X + 4][coordinates.Y + 2].colorNum = 5;
				}
			}
			else
			{
				//�Ŧ�
				Board.nowBoard[coordinates.X + 4][coordinates.Y + 2].colorNum = 4;
			}
		}
		
	}

	//�f�f��-----------------------------------
	if (coordinates.Y - 2 >= 1 && Board.nowBoard[coordinates.X][coordinates.Y - 2].chessNum == 0)//���L���}
	{
		if (coordinates.X - 2 >= 2 && coordinates.Y - 4 >= 1) {
			if (Board.nowBoard[coordinates.X - 2][coordinates.Y - 4].chessNum == 0)//���W���B�L��
			{
				//�Ŧ�
				Board.nowBoard[coordinates.X - 2][coordinates.Y - 4].colorNum = 4;
			}
			else//����
			{
				if (isEnemy(coordinates.X - 2, coordinates.Y - 4, Board))
				{
					//����
					Board.nowBoard[coordinates.X - 2][coordinates.Y - 4].colorNum = 5;
				}
			}
		}

		if (coordinates.X + 2 <= 20 && coordinates.Y - 4 >= 1) {
			if (Board.nowBoard[coordinates.X + 2][coordinates.Y - 4].chessNum == 0)//���U���B�L��
			{
				//�Ŧ�
				Board.nowBoard[coordinates.X + 2][coordinates.Y - 4].colorNum = 4;
			}
			else//����
			{
				if (isEnemy(coordinates.X + 2, coordinates.Y - 4, Board))
				{
					//����
					Board.nowBoard[coordinates.X + 2][coordinates.Y - 4].colorNum = 5;
				}
			}
		}
		
	}

	if (coordinates.Y + 2 <= 17 && Board.nowBoard[coordinates.X][coordinates.Y + 2].chessNum == 0)//�k�L���}
	{
		if (coordinates.X - 2 >= 2 && coordinates.Y + 4 <= 17) {
			if (Board.nowBoard[coordinates.X - 2][coordinates.Y + 4].chessNum == 0)//�k�W���B�L��
			{
				//�Ŧ�
				Board.nowBoard[coordinates.X - 2][coordinates.Y + 4].colorNum = 4;
			}
			else//����
			{
				if (isEnemy(coordinates.X - 2, coordinates.Y + 4, Board))
				{
					//����
					Board.nowBoard[coordinates.X - 2][coordinates.Y + 4].colorNum = 5;
				}
			}
		}

		if (coordinates.X + 2 <= 20 && coordinates.Y + 4 <= 17) {
			if (Board.nowBoard[coordinates.X + 2][coordinates.Y + 4].chessNum == 0)//�k�U���B�L��
			{
				//�Ŧ�
				Board.nowBoard[coordinates.X + 2][coordinates.Y + 4].colorNum = 4;
			}
			else//����
			{
				if (isEnemy(coordinates.X + 2, coordinates.Y + 4, Board))
				{
					//����
					Board.nowBoard[coordinates.X + 2][coordinates.Y + 4].colorNum = 5;
				}
			}
		}
		
	}

}

void HorseChess::moveUp(int a, int b, board & Board)
{
	if (a == (coordinates.X - 4) && b == (coordinates.Y - 2))//����
	{
		if (Board.nowBoard[a][b].colorNum == 5)
		{
			coordinates.X = a;
			coordinates.Y = b;
			if (Board.nowBoard[a][b].chessNum == 1 || Board.nowBoard[a][b].chessNum == 8)
			{
				Board.isWin = true;
			}
			//�Y��
		}
		else if (Board.nowBoard[a][b].colorNum == 4)
		{
			coordinates.X = a;
			coordinates.Y = b;
			//����
		}
	}

	if (a == (coordinates.X - 4) && b == (coordinates.Y + 2))//�k��
	{
		if (Board.nowBoard[a][b].colorNum == 5)
		{
			coordinates.X = a;
			coordinates.Y = b;
			if (Board.nowBoard[a][b].chessNum == 1 || Board.nowBoard[a][b].chessNum == 8)
			{
				Board.isWin = true;
			}
			//�Y��
		}
		else if (Board.nowBoard[a][b].colorNum == 4)
		{
			coordinates.X = a;
			coordinates.Y = b;
			//����
		}
	}

	if (a == (coordinates.X - 2) && b == (coordinates.Y - 4))//���f�f
	{
		if (Board.nowBoard[a][b].colorNum == 5)
		{
			coordinates.X = a;
			coordinates.Y = b;
			if (Board.nowBoard[a][b].chessNum == 1 || Board.nowBoard[a][b].chessNum == 8)
			{
				Board.isWin = true;
			}
			//�Y��
		}
		else if (Board.nowBoard[a][b].colorNum == 4)
		{
			coordinates.X = a;
			coordinates.Y = b;
			//����
		}
	}

	if (a == (coordinates.X - 2) && b == (coordinates.Y + 4))
	{
		if (Board.nowBoard[a][b].colorNum == 5)
		{
			coordinates.X = a;
			coordinates.Y = b;
			if (Board.nowBoard[a][b].chessNum == 1 || Board.nowBoard[a][b].chessNum == 8)
			{
				Board.isWin = true;
			}
			//�Y��
		}
		else if (Board.nowBoard[a][b].colorNum == 4)
		{
			coordinates.X = a;
			coordinates.Y = b;
			//����
		}
	}
}

void HorseChess::moveBack(int a, int b, board & Board)
{
	if (a == (coordinates.X + 4) && b == (coordinates.Y - 2))//����
	{
		if (Board.nowBoard[a][b].colorNum == 5)
		{
			coordinates.X = a;
			coordinates.Y = b;
			if (Board.nowBoard[a][b].chessNum == 1 || Board.nowBoard[a][b].chessNum == 8)
			{
				Board.isWin = true;
			}
			//�Y��
		}
		else if (Board.nowBoard[a][b].colorNum == 4)
		{
			coordinates.X = a;
			coordinates.Y = b;
			//����
		}
	}

	if (a == (coordinates.X + 4) && b == (coordinates.Y + 2))//�k��
	{
		if (Board.nowBoard[a][b].colorNum == 5)
		{
			coordinates.X = a;
			coordinates.Y = b;
			if (Board.nowBoard[a][b].chessNum == 1 || Board.nowBoard[a][b].chessNum == 8)
			{
				Board.isWin = true;
			}
			//�Y��
		}
		else if (Board.nowBoard[a][b].colorNum == 4)
		{
			coordinates.X = a;
			coordinates.Y = b;
			//����
		}
	}

	if (a == (coordinates.X + 2) && b == (coordinates.Y - 4))//���f�f
	{
		if (Board.nowBoard[a][b].colorNum == 5)
		{
			coordinates.X = a;
			coordinates.Y = b;
			if (Board.nowBoard[a][b].chessNum == 1 || Board.nowBoard[a][b].chessNum == 8)
			{
				Board.isWin = true;
			}
			//�Y��
		}
		else if (Board.nowBoard[a][b].colorNum == 4)
		{
			coordinates.X = a;
			coordinates.Y = b;
			//����
		}
	}

	if (a == (coordinates.X + 2) && b == (coordinates.Y + 4))
	{
		if (Board.nowBoard[a][b].colorNum == 5)
		{
			coordinates.X = a;
			coordinates.Y = b;
			if (Board.nowBoard[a][b].chessNum == 1 || Board.nowBoard[a][b].chessNum == 8)
			{
				Board.isWin = true;
			}
			//�Y��
		}
		else if (Board.nowBoard[a][b].colorNum == 4)
		{
			coordinates.X = a;
			coordinates.Y = b;
			//����
		}
	}
}