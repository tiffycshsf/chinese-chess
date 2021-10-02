#include "ElephentChess.h"

ElephentChess::ElephentChess(int a, int b, int c) : chess(a, b, c)
{
	identity = a;
	coordinates.X = b;
	coordinates.Y = c;
	exist = 1;
}

ElephentChess::~ElephentChess()
{
	exist = 0;
}

//�H/�ۨ����d�򤣯�L�e
//���k�O�k�W�СB�k�U�СB���W�СB���U��
//�p�G�k�W�B�k�U�B���W�B���U���Ѥl�h���ਫ

void ElephentChess::moveColor(board & Board)
{
	//��
	if (identity > 7)
	{
		//���W��
		if (coordinates.X >= 16 && coordinates.Y >= 5) {
			if (Board.nowBoard[coordinates.X - 2][coordinates.Y - 2].chessNum == 0) {
				if (Board.nowBoard[coordinates.X - 4][coordinates.Y - 4].chessNum != 0)
				{
					if (Board.nowBoard[coordinates.X - 4][coordinates.Y - 4].chessNum <= 7)//���X�l�B���Ĥ�
					{
						//����
						Board.nowBoard[coordinates.X - 4][coordinates.Y - 4].colorNum = 5;
					}
				}
				else
				{
					//�Ŧ�
					Board.nowBoard[coordinates.X - 4][coordinates.Y - 4].colorNum = 4;
				}
			}
		}
		

		//�k�W��
		if (coordinates.X >= 16 && coordinates.Y <= 13) {
			if (Board.nowBoard[coordinates.X - 2][coordinates.Y + 2].chessNum == 0) {
				if (Board.nowBoard[coordinates.X - 4][coordinates.Y + 4].chessNum != 0)
				{
					if (Board.nowBoard[coordinates.X - 4][coordinates.Y + 4].chessNum <= 7)//���X�l�B���Ĥ�
					{
						//����
						Board.nowBoard[coordinates.X - 4][coordinates.Y + 4].colorNum = 5;
					}
				}
				else
				{
					//�Ŧ�
					Board.nowBoard[coordinates.X - 4][coordinates.Y + 4].colorNum = 4;
				}
			}
		}


		//���U��
		if (coordinates.X <= 16 && coordinates.Y >= 5) {
			if (Board.nowBoard[coordinates.X + 2][coordinates.Y - 2].chessNum == 0) {
				if (Board.nowBoard[coordinates.X + 4][coordinates.Y - 4].chessNum != 0)
				{
					if (Board.nowBoard[coordinates.X + 4][coordinates.Y - 4].chessNum <= 7)//���X�l�B���Ĥ�
					{
						//����
						Board.nowBoard[coordinates.X + 4][coordinates.Y - 4].colorNum = 5;
					}
				}
				else
				{
					//�Ŧ�
					Board.nowBoard[coordinates.X + 4][coordinates.Y - 4].colorNum = 4;
				}
			}
		}


		//�k�U��
		if (coordinates.X <= 16 && coordinates.Y <= 13) {
			if (Board.nowBoard[coordinates.X + 2][coordinates.Y + 2].chessNum == 0) {
				if (Board.nowBoard[coordinates.X + 4][coordinates.Y + 4].chessNum != 0)
				{
					if (Board.nowBoard[coordinates.X + 4][coordinates.Y + 4].chessNum <= 7)//���X�l�B���Ĥ�
					{
						//����
						Board.nowBoard[coordinates.X + 4][coordinates.Y + 4].colorNum = 5;
					}
				}
				else
				{
					//�Ŧ�
					Board.nowBoard[coordinates.X + 4][coordinates.Y + 4].colorNum = 4;
				}
			}
		}

	}

	//��
	else
	{
		//���W��
		if (coordinates.X >= 6 && coordinates.Y >= 5) {
			if (Board.nowBoard[coordinates.X - 2][coordinates.Y - 2].chessNum == 0) {
				if (Board.nowBoard[coordinates.X - 4][coordinates.Y - 4].chessNum != 0)
				{
					if (Board.nowBoard[coordinates.X - 4][coordinates.Y - 4].chessNum > 7)//���X�l�B���Ĥ�
					{
						//����
						Board.nowBoard[coordinates.X - 4][coordinates.Y - 4].colorNum = 5;
					}
				}
				else
				{
					//�Ŧ�
					Board.nowBoard[coordinates.X - 4][coordinates.Y - 4].colorNum = 4;
				}
			}
		}


		//�k�W��
		if (coordinates.X >= 6 && coordinates.Y <= 13) {
			if (Board.nowBoard[coordinates.X - 2][coordinates.Y + 2].chessNum == 0) {
				if (Board.nowBoard[coordinates.X - 4][coordinates.Y + 4].chessNum != 0)
				{
					if (Board.nowBoard[coordinates.X - 4][coordinates.Y + 4].chessNum > 7)//���X�l�B���Ĥ�
					{
						//����
						Board.nowBoard[coordinates.X - 4][coordinates.Y + 4].colorNum = 5;
					}
				}
				else
				{
					//�Ŧ�
					Board.nowBoard[coordinates.X - 4][coordinates.Y + 4].colorNum = 4;
				}
			}
		}


		//���U��
		if (coordinates.X <= 6 && coordinates.Y >= 5) {
			if (Board.nowBoard[coordinates.X + 2][coordinates.Y - 2].chessNum == 0) {
				if (Board.nowBoard[coordinates.X + 4][coordinates.Y - 4].chessNum != 0)
				{
					if (Board.nowBoard[coordinates.X + 4][coordinates.Y - 4].chessNum > 7)//���X�l�B���Ĥ�
					{
						//����
						Board.nowBoard[coordinates.X + 4][coordinates.Y - 4].colorNum = 5;
					}
				}
				else
				{
					//�Ŧ�
					Board.nowBoard[coordinates.X + 4][coordinates.Y - 4].colorNum = 4;
				}
			}
		}


		//�k�U��
		if (coordinates.X <= 6 && coordinates.Y <= 13) {
			if (Board.nowBoard[coordinates.X + 2][coordinates.Y + 2].chessNum == 0) {
				if (Board.nowBoard[coordinates.X + 4][coordinates.Y + 4].chessNum != 0)
				{
					if (Board.nowBoard[coordinates.X + 4][coordinates.Y + 4].chessNum > 7)//���X�l�B���Ĥ�
					{
						//����
						Board.nowBoard[coordinates.X + 4][coordinates.Y + 4].colorNum = 5;
					}
				}
				else
				{
					//�Ŧ�
					Board.nowBoard[coordinates.X + 4][coordinates.Y + 4].colorNum = 4;
				}
			}
		}
	}
}

void ElephentChess::moveUp(int a, int b, board & Board)
{
	//��
	if (identity > 7)
	{
		//���W��
		if (a >= 16 && b >= 5) {
			if (a == (coordinates.X - 4) && b == (coordinates.Y - 4))
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

		//�k�W��
		if (a >= 16 && b <= 13) {
			if (a == (coordinates.X - 4) && b == (coordinates.Y + 4))
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
		//���W��
		if (a >= 6 && b >= 5) {
			if (a == (coordinates.X - 4) && b == (coordinates.Y - 4))
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

		//�k�W��
		if (a >= 6 && b <= 13) {
			if (a == (coordinates.X - 4) && b == (coordinates.Y + 4))
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


void ElephentChess::moveBack(int a, int b, board & Board)
{
	//��
	if (identity > 7)
	{
		//���U��

		if (a <= 16 && b >= 5) {
			if (a == (coordinates.X + 4) && b == (coordinates.Y - 4))
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

		//�k�U��
		if (a <= 16 && b <= 13) {
			if (a == (coordinates.X + 4) && b == (coordinates.Y + 4))
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
		//���U��
		if (a <= 6 && b >= 5) {
			if (a == (coordinates.X + 4) && b == (coordinates.Y - 4))
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

		//�k�U��
		if (a <= 6 && b <= 13) {
			if (a == (coordinates.X + 4) && b == (coordinates.Y + 4))
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

