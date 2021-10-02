#include "GeneralChess.h"

GeneralChess::GeneralChess(int a, int b, int c) : chess(a, b, c)
{
	identity = a;
	coordinates.X = b;
	coordinates.Y = c;
	exist = 1;
}

GeneralChess::~GeneralChess()
{
	exist = 0;
}

//�h/�K�����d�򤣯�W�L�E�c��
//���k�O�k�W�B�k�U�B���W�B���U

void GeneralChess::moveColor(board & Board)
{
	//��
	if (identity > 7)
	{
		//���W
		if (coordinates.X > 16 && coordinates.Y > 7) {
			if (Board.nowBoard[coordinates.X - 2][coordinates.Y - 2].chessNum != 0)
			{
				if (Board.nowBoard[coordinates.X - 2][coordinates.Y - 2].chessNum <= 7)//���X�l�B���Ĥ�
				{
					//����
					Board.nowBoard[coordinates.X - 2][coordinates.Y - 2].colorNum = 5;
				}
			}
			else
			{
				//�Ŧ�
				Board.nowBoard[coordinates.X - 2][coordinates.Y - 2].colorNum = 4;
			}
		}

		//�k�W
		if (coordinates.X > 16 && coordinates.Y < 11) {
			if (Board.nowBoard[coordinates.X - 2][coordinates.Y + 2].chessNum != 0)
			{
				if (Board.nowBoard[coordinates.X - 2][coordinates.Y + 2].chessNum <= 7)//���X�l�B���Ĥ�
				{
					//����
					Board.nowBoard[coordinates.X - 2][coordinates.Y + 2].colorNum = 5;
				}
			}
			else
			{
				//�Ŧ�
				Board.nowBoard[coordinates.X - 2][coordinates.Y + 2].colorNum = 4;
			}
		}

		//���U
		if (coordinates.X < 20 && coordinates.Y > 7) {
			if (Board.nowBoard[coordinates.X + 2][coordinates.Y - 2].chessNum != 0)
			{
				if (Board.nowBoard[coordinates.X + 2][coordinates.Y - 2].chessNum <= 7)//���X�l�B���Ĥ�
				{
					//����
					Board.nowBoard[coordinates.X + 2][coordinates.Y - 2].colorNum = 5;
				}
			}
			else
			{
				//�Ŧ�
				Board.nowBoard[coordinates.X + 2][coordinates.Y - 2].colorNum = 4;
			}
		}

		//�k�U
		if (coordinates.X < 20 && coordinates.Y < 11) {
			if (Board.nowBoard[coordinates.X + 2][coordinates.Y + 2].chessNum != 0)
			{
				if (Board.nowBoard[coordinates.X + 2][coordinates.Y + 2].chessNum <= 7)//���X�l�B���Ĥ�
				{
					//����
					Board.nowBoard[coordinates.X + 2][coordinates.Y + 2].colorNum = 5;
				}
			}
			else
			{
				//�Ŧ�
				Board.nowBoard[coordinates.X + 2][coordinates.Y + 2].colorNum = 4;
			}
		}
	}

	//��
	else
	{
		//���W
		if (coordinates.X > 2 && coordinates.Y > 7) {
			if (Board.nowBoard[coordinates.X - 2][coordinates.Y - 2].chessNum != 0)
			{
				if (Board.nowBoard[coordinates.X - 2][coordinates.Y - 2].chessNum > 7)//���X�l�B���Ĥ�
				{
					//����
					Board.nowBoard[coordinates.X - 2][coordinates.Y - 2].colorNum = 5;
				}
			}
			else
			{
				//�Ŧ�
				Board.nowBoard[coordinates.X - 2][coordinates.Y - 2].colorNum = 4;
			}
		}


		//�k�W
		if (coordinates.X > 2 && coordinates.Y < 11) {
			if (Board.nowBoard[coordinates.X - 2][coordinates.Y + 2].chessNum != 0)
			{
				if (Board.nowBoard[coordinates.X - 2][coordinates.Y + 2].chessNum > 7)//���X�l�B���Ĥ�
				{
					//����
					Board.nowBoard[coordinates.X - 2][coordinates.Y + 2].colorNum = 5;
				}
			}
			else
			{
				//�Ŧ�
				Board.nowBoard[coordinates.X - 2][coordinates.Y + 2].colorNum = 4;
			}
		}

		//���U
		if (coordinates.X < 6 && coordinates.Y > 7) {
			if (Board.nowBoard[coordinates.X + 2][coordinates.Y - 2].chessNum != 0)
			{
				if (Board.nowBoard[coordinates.X + 2][coordinates.Y - 2].chessNum > 7)//���X�l�B���Ĥ�
				{
					//����
					Board.nowBoard[coordinates.X + 2][coordinates.Y - 2].colorNum = 5;
				}
			}
			else
			{
				//�Ŧ�
				Board.nowBoard[coordinates.X + 2][coordinates.Y - 2].colorNum = 4;
			}
		}

		//�k�U
		if (coordinates.X < 6 && coordinates.Y < 11) {
			if (Board.nowBoard[coordinates.X + 2][coordinates.Y + 2].chessNum != 0)
			{
				if (Board.nowBoard[coordinates.X + 2][coordinates.Y + 2].chessNum > 7)//���X�l�B���Ĥ�
				{
					//����
					Board.nowBoard[coordinates.X + 2][coordinates.Y + 2].colorNum = 5;
				}
			}
			else
			{
				//�Ŧ�
				Board.nowBoard[coordinates.X + 2][coordinates.Y + 2].colorNum = 4;
			}
		}
	}
}

void GeneralChess::moveUp(int a, int b, board & Board)
{
	//��
	if (identity > 7)
	{
		//���W
		if (a >= 16 && b >= 7) {
			if (a == (coordinates.X - 2) && b == (coordinates.Y - 2))
			{
				if (Board.nowBoard[a][b].colorNum == 5)
				{
					coordinates.X = a;
					coordinates.Y = b;
					//�Y��
				}
				else if (Board.nowBoard[a][b].colorNum == 4)
				{
					coordinates.X = a;
					coordinates.Y = b;
				}
			}
		}

		//�k�W
		if (a >= 16 && b <= 11) {
			if (a == (coordinates.X - 2) && b == (coordinates.Y + 2))
			{
				if (Board.nowBoard[a][b].colorNum == 5)
				{
					coordinates.X = a;
					coordinates.Y = b;
					//�Y��
				}
				else if (Board.nowBoard[a][b].colorNum == 4)
				{
					coordinates.X = a;
					coordinates.Y = b;
				}
			}
		}

	}
	//��
	else {
		//���W
		if (a >= 2 && b >= 7) {
			if (a == (coordinates.X - 2) && b == (coordinates.Y - 2))
			{
				if (Board.nowBoard[a][b].colorNum == 5)
				{
					coordinates.X = a;
					coordinates.Y = b;
					//�Y��
				}
				else if (Board.nowBoard[a][b].colorNum == 4)
				{
					coordinates.X = a;
					coordinates.Y = b;
				}
			}
		}
		
		//�k�W
		if (a >= 2 && b <= 11) {
			if (a == (coordinates.Y - 2) && b == (coordinates.Y + 2))
			{
				if (Board.nowBoard[a][b].colorNum == 5)
				{
					coordinates.X = a;
					coordinates.Y = b;
					//�Y��
				}
				else if (Board.nowBoard[a][b].colorNum == 4)
				{
					coordinates.X = a;
					coordinates.Y = b;
				}
			}
		}

	}
}


void GeneralChess::moveBack(int a, int b, board & Board)
{
	//��
	if (identity > 7)
	{
		//���U
		if (a <= 20 && b >= 7) {
			if (a == (coordinates.Y + 2) && b == (coordinates.Y - 2))
			{
				if (Board.nowBoard[a][b].colorNum == 5)
				{
					coordinates.X = a;
					coordinates.Y = b;
					//�Y��
				}
				else if (Board.nowBoard[a][b].colorNum == 4)
				{
					coordinates.X = a;
					coordinates.Y = b;
				}
			}
		}

		//�k�U
		if (a <= 20 && b <= 11) {
			if (a == (coordinates.Y + 2) && b == (coordinates.Y + 2))
			{
				if (Board.nowBoard[a][b].colorNum == 5)
				{
					coordinates.X = a;
					coordinates.Y = b;
					//�Y��
				}
				else if (Board.nowBoard[a][b].colorNum == 4)
				{
					coordinates.X = a;
					coordinates.Y = b;
				}
			}
		}
	}
	//��
	else {
		//���U
		if (a <= 6 && b >= 7) {
			if (a == (coordinates.Y + 2) && b == (coordinates.Y - 2))
			{
				if (Board.nowBoard[a][b].colorNum == 5)
				{
					coordinates.X = a;
					coordinates.Y = b;
					//�Y��
				}
				else if (Board.nowBoard[a][b].colorNum == 4)
				{
					coordinates.X = a;
					coordinates.Y = b;
				}
			}
		}

		//�k�U
		if (a <= 6 && b <= 11) {
			if (a == (coordinates.Y + 2) && b == (coordinates.Y + 2))
			{
				if (Board.nowBoard[a][b].colorNum == 5)
				{
					coordinates.X = a;
					coordinates.Y = b;
					//�Y��
				}
				else if (Board.nowBoard[a][b].colorNum == 4)
				{
					coordinates.X = a;
					coordinates.Y = b;
				}
			}
		}

	}
}
