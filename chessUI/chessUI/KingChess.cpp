#include "KingChess.h"

KingChess::KingChess(int a, int b, int c) : chess(a, b, c)
{
	identity = a;
	coordinates.X = b;
	coordinates.Y = c;
	exist = 1;
}

KingChess::~KingChess()
{
	/*exist = 0;
	identity = 0;
	coordinates.X = 0;
	coordinates.Y = 0;*/
}

//�N/�Ө����d�򤣯�W�L�E�c��
//���k�O�W�B�U�B���B�k
void KingChess::moveColor(board & Board)
{
	//��
	if (identity > 7)
	{
		//��
		if (Board.nowBoard[coordinates.X][coordinates.Y - 2].chessNum != 0 && coordinates.Y > 7)
		{
			if (Board.nowBoard[coordinates.X][coordinates.Y - 2].chessNum <= 7)//���X�l�B���Ĥ�
			{
				//����
				Board.nowBoard[coordinates.X][coordinates.Y - 2].colorNum = 5;
			}
		}
		else if (Board.nowBoard[coordinates.X][coordinates.Y - 2].chessNum == 0 && coordinates.Y > 7)
		{
			//�Ŧ�
			Board.nowBoard[coordinates.X][coordinates.Y - 2].colorNum = 4;
		}

		//�k
		if (Board.nowBoard[coordinates.X][coordinates.Y + 2].chessNum != 0 && coordinates.Y < 11)
		{
			if (Board.nowBoard[coordinates.X][coordinates.Y + 2].chessNum <= 7)//���X�l�B���Ĥ�
			{
				//����
				Board.nowBoard[coordinates.X][coordinates.Y + 2].colorNum = 5;
			}
		}
		else if (Board.nowBoard[coordinates.X][coordinates.Y + 2].chessNum == 0 && coordinates.Y < 11)
		{
			//�Ŧ�
			Board.nowBoard[coordinates.X][coordinates.Y + 2].colorNum = 4;
		}

		//�W
		if (Board.nowBoard[coordinates.X - 2][coordinates.Y].chessNum != 0 && coordinates.X > 16)
		{
			if (Board.nowBoard[coordinates.X - 2][coordinates.Y].chessNum <= 7)//���X�l�B���Ĥ�
			{
				//����
				Board.nowBoard[coordinates.X - 2][coordinates.Y].colorNum = 5;
			}
		}
		else if (Board.nowBoard[coordinates.X - 2][coordinates.Y].chessNum == 0 && coordinates.X > 16)
		{
			//�Ŧ�
			Board.nowBoard[coordinates.X - 2][coordinates.Y].colorNum = 4;
		}

		//������
		for (int j = coordinates.X - 2; j >= 2; j -= 2)
		{
			if (Board.nowBoard[j][coordinates.Y].chessNum != 0 && Board.nowBoard[j][coordinates.Y].chessNum == 1)
			{
				//����
				Board.nowBoard[j][coordinates.Y].colorNum = 5;
				break;
			}	
		}

		//�U
		if (Board.nowBoard[coordinates.X + 2][coordinates.Y].chessNum != 0 && coordinates.X < 20)
		{
			if (Board.nowBoard[coordinates.X + 2][coordinates.Y].chessNum <= 7)//���X�l�B���Ĥ�
			{
				//����
				Board.nowBoard[coordinates.X + 2][coordinates.Y].colorNum = 5;
			}
		}
		else if (Board.nowBoard[coordinates.X + 2][coordinates.Y].chessNum == 0 && coordinates.X < 20)
		{
			//�Ŧ�
			Board.nowBoard[coordinates.X + 2][coordinates.Y].colorNum = 4;
		}
	}

	//��
	else
	{
		//��
		if (Board.nowBoard[coordinates.X][coordinates.Y - 2].chessNum != 0 && coordinates.Y > 7)
		{
			if (Board.nowBoard[coordinates.X][coordinates.Y - 2].chessNum > 7)//���X�l�B���Ĥ�
			{
				//����
				Board.nowBoard[coordinates.X][coordinates.Y - 2].colorNum = 5;
			}
		}
		else if (Board.nowBoard[coordinates.X][coordinates.Y - 2].chessNum == 0 && coordinates.Y > 7)
		{
			//�Ŧ�
			Board.nowBoard[coordinates.X][coordinates.Y - 2].colorNum = 4;
		}

		//�k
		if (Board.nowBoard[coordinates.X][coordinates.Y + 2].chessNum != 0 && coordinates.Y < 11)
		{
			if (Board.nowBoard[coordinates.X][coordinates.Y + 2].chessNum > 7)//���X�l�B���Ĥ�
			{
				//����
				Board.nowBoard[coordinates.X][coordinates.Y + 2].colorNum = 5;
			}
		}
		else if (Board.nowBoard[coordinates.X][coordinates.Y + 2].chessNum == 0 && coordinates.Y < 11)
		{
			//�Ŧ�
			Board.nowBoard[coordinates.X][coordinates.Y + 2].colorNum = 4;
		}

		//�W
		if (Board.nowBoard[coordinates.X - 2][coordinates.Y].chessNum != 0 && coordinates.X > 2)
		{
			if (Board.nowBoard[coordinates.X - 2][coordinates.Y].chessNum > 7)//���X�l�B���Ĥ�
			{
				//����
				Board.nowBoard[coordinates.X - 2][coordinates.Y].colorNum = 5;
			}
		}
		else if (Board.nowBoard[coordinates.X - 2][coordinates.Y].chessNum == 0 && coordinates.X > 2)
		{
			//�Ŧ�
			Board.nowBoard[coordinates.X - 2][coordinates.Y].colorNum = 4;
		}

		//�U
		if (Board.nowBoard[coordinates.X + 2][coordinates.Y].chessNum != 0 && coordinates.X < 6)
		{
			if (Board.nowBoard[coordinates.X + 2][coordinates.Y].chessNum > 7)//���X�l�B���Ĥ�
			{
				//����
				Board.nowBoard[coordinates.X + 2][coordinates.Y].colorNum = 5;
			}
		}
		else if (Board.nowBoard[coordinates.X + 2][coordinates.Y].chessNum == 0 && coordinates.X < 6)
		{
			//�Ŧ�
			Board.nowBoard[coordinates.X + 2][coordinates.Y].colorNum = 4;
		}

		//������
		for (int j = coordinates.X + 2; j <= 20; j += 2)
		{
			if (Board.nowBoard[j][coordinates.Y].chessNum != 0 && Board.nowBoard[j][coordinates.Y].chessNum == 8)
			{
				//����
				Board.nowBoard[j][coordinates.Y].colorNum = 5;
				break;
			}
		}
	}
}

void KingChess::moveUp(int a, int b, board & Board)
{
	//��
	if (identity > 7)
	{
		if (a == (coordinates.X - 2) && b == coordinates.Y && a >= 16)//�W���@��
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

		//������
		if (b == coordinates.Y)
		{
			for (int a = 6; a >= 2; a - 2)
			{
				if (Board.nowBoard[a][b].colorNum == 5)
				{
					coordinates.X = a;
					//�Y��
				}
			}
		}

	}
	//��
	else {
		if (a == (coordinates.X - 2) && b == coordinates.Y && a >= 2)//�W���@��
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

void KingChess::moveHorizon(int a, int b, board & Board)
{
	//��
	if (a == coordinates.X && b == (coordinates.Y - 2) && b >= 7)//�W���@��
	{
		if (Board.nowBoard[a][b].colorNum == 5)
		{
			coordinates.Y = b;
			//�Y��
		}
		else if (Board.nowBoard[a][b].colorNum == 4)
		{
			coordinates.Y = b;
		}
	}

	//�k
	if (a == coordinates.X && b == (coordinates.Y + 2) && b <= 11)//�W���@��
	{
		if (Board.nowBoard[a][b].colorNum == 5)
		{
			coordinates.Y = b;
			//�Y��
		}
		else if (Board.nowBoard[a][b].colorNum == 4)
		{
			coordinates.Y = b;
		}
	}
}


void KingChess::moveBack(int a, int b, board & Board)
{
	//��
	if (identity > 7)
	{
		if (a == (coordinates.X + 2) && b == coordinates.Y && a <= 20)//�W���@��
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
	//��
	else {
		if (a == (coordinates.X + 2) && b == coordinates.Y && a <= 6)//�W���@��
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

		//������
		if (b == coordinates.Y)
		{
			for (int a = 16; a <= 20; a + 2)
			{
				if (Board.nowBoard[a][b].colorNum == 5)
				{
					coordinates.X = a;
					//�Y��
				}
			}
		}
	}
}

void KingChess::Check(board & Board)
{
	//�u���������~�i�঳�N�x����

	//��
	if (identity > 7) {
		//������
		for (int j = coordinates.X - 2; j >= 2; j -= 2)
		{
			if (Board.nowBoard[j][coordinates.Y].chessNum != 0)
			{
				if (Board.nowBoard[j][coordinates.Y].chessNum == 1) {
					Board.isKing = true;
				}
				break;
			}
		}
		
	}

	//��
	else
	{
		//������
		for (int j = coordinates.X + 2; j <= 20; j += 2)
		{
			if (Board.nowBoard[j][coordinates.Y].chessNum != 0)
			{
				if (Board.nowBoard[j][coordinates.Y].chessNum == 8) {
					Board.isKing = true;
				}

				break;
			}
		}
	}
}
