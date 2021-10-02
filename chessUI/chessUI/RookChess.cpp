#include "RookChess.h"



RookChess::RookChess(int a , int b,int c):chess(a,b,c)
{
	identity = a;
	coordinates.X = b;
	coordinates.Y = c;
	exist = 1;
}


RookChess::~RookChess()
{
	exist = 0;
}

void RookChess::moveColor(board & Board)
{
	
	//���P�_�P�@�橹���O�_���X�l
	for (int i = coordinates.Y - 2; i >= 1 ; i -= 2)
	{
		if (Board.nowBoard[coordinates.X][i].chessNum != 0)//���Ӧa�観�X�l
		{
			maxLeft = i;
			if (identity <= 7 && Board.nowBoard[coordinates.X][i].chessNum > 7)
			{
				Board.nowBoard[coordinates.X][i].colorNum = 5;
			}
			else if (identity > 7 && Board.nowBoard[coordinates.X][i].chessNum <= 7) {
				Board.nowBoard[coordinates.X][i].colorNum = 5;
			}
			else
			{
				//�P�}�礣�ܦ�
			}
			break;
		}
		else
		{
			maxLeft = 1;
			Board.nowBoard[coordinates.X][i].colorNum = 4;
		}
	}
	//right
	for (int i = coordinates.Y + 2; i <= 17; i += 2)
	{
		if (Board.nowBoard[coordinates.X][i].chessNum != 0)//���Ӧa�観�X�l
		{
			maxRight = i;
			if (identity <= 7 && Board.nowBoard[coordinates.X][i].chessNum > 7)
			{
				//�ܦ�����
				Board.nowBoard[coordinates.X][i].colorNum = 5;
			}
			else if (identity > 7 && Board.nowBoard[coordinates.X][i].chessNum <= 7) {
				Board.nowBoard[coordinates.X][i].colorNum = 5;
			}
			else
			{
				//�P�}�礣�ܦ�
			}
			break;
		}
		else
		{
			maxRight = 17;
			Board.nowBoard[coordinates.X][i].colorNum = 4;//�ܦ��Ŧ�
		}

	}//�P�@���ܦ⧹��
	
	for (int i = coordinates.X - 2; i >= 2; i -= 2)//column���W���ܦ�
	{
		if (Board.nowBoard[i][coordinates.Y].chessNum != 0)//���Ӧa�観�X�l
		{
			maxUp = i;
			if (identity <= 7 && Board.nowBoard[i][coordinates.Y].chessNum > 7)
			{
				//�ܦ�����
				Board.nowBoard[i][coordinates.Y].colorNum = 5;
			}
			else if (identity > 7 && Board.nowBoard[i][coordinates.Y].chessNum <= 7) {
				Board.nowBoard[i][coordinates.Y].colorNum = 5;
			}
			else
			{
				//�P�}�礣�ܦ�
			}
			break;
		}
		else
		{
			maxUp = 2;
			Board.nowBoard[i][coordinates.Y].colorNum = 4;//�ܦ��Ŧ�
		}

	}
	for (int i = coordinates.X + 2; i <= 20; i += 2)//column���U���ܦ�
	{
		if (Board.nowBoard[i][coordinates.Y].chessNum != 0)//���Ӧa�観�X�l
		{
			maxDown = i;
			if (identity <= 7 && Board.nowBoard[i][coordinates.Y].chessNum > 7)
			{
				//�ܦ�����
				Board.nowBoard[i][coordinates.Y].colorNum = 5;
			}
			else if (identity > 7 && Board.nowBoard[i][coordinates.Y].chessNum <= 7) {
				Board.nowBoard[i][coordinates.Y].colorNum = 5;
			}
			else
			{
				//�P�}�礣�ܦ�
			}
			break;
		}
		else//�S�X�l �i�H��
		{
			maxDown = 20;
			Board.nowBoard[i][coordinates.Y].colorNum = 4;//�ܦ��Ŧ�
		}

	}

}

void RookChess::check(board & Board)
{
	//���P�_�P�@�橹���O�_���X�l
	for (int i = coordinates.Y - 2; i >= 1; i -= 2)
	{
		if (Board.nowBoard[coordinates.X][i].chessNum != 0)//���Ӧa�観�X�l
		{
			maxLeft = i;
			if (identity <= 7 && Board.nowBoard[coordinates.X][i].chessNum > 7)
			{
				if (Board.nowBoard[coordinates.X][i].chessNum == 1)
				{
					Board.isKing = true;
				}
			}
			else if (identity > 7 && Board.nowBoard[coordinates.X][i].chessNum <= 7) {
				if (Board.nowBoard[coordinates.X][i].chessNum == 8)
				{
					Board.isKing = true;
				}
			}
			
			break;
		}
		
	}
	//right
	for (int i = coordinates.Y + 2; i <= 17; i += 2)
	{
		if (Board.nowBoard[coordinates.X][i].chessNum != 0)//���Ӧa�観�X�l
		{
			maxRight = i;
			if (identity <= 7 && Board.nowBoard[coordinates.X][i].chessNum > 7)
			{
				if (Board.nowBoard[coordinates.X][i].chessNum == 8)
				{
					Board.isKing = true;
				}
			}
			else if (identity > 7 && Board.nowBoard[coordinates.X][i].chessNum <= 7) {
				if (Board.nowBoard[coordinates.X][i].chessNum == 1)
				{
					Board.isKing = true;
				}
			}
			
			break;
		}
		

	}

	for (int i = coordinates.X - 2; i >= 2; i -= 2)//column���W��
	{
		if (Board.nowBoard[i][coordinates.Y].chessNum != 0)//���Ӧa�観�X�l
		{
			maxUp = i;
			if (identity <= 7 && Board.nowBoard[i][coordinates.Y].chessNum > 7)
			{
				if (Board.nowBoard[i][coordinates.Y].chessNum == 8)
				{
					Board.isKing = true;
				}
			}
			else if (identity > 7 && Board.nowBoard[i][coordinates.Y].chessNum <= 7) {
				if (Board.nowBoard[i][coordinates.Y].chessNum == 8)
				{
					Board.isKing = true;
				}
			}
			
			break;
		}

	}
	for (int i = coordinates.X + 2; i <= 20; i += 2)//column���U��
	{
		if (Board.nowBoard[i][coordinates.Y].chessNum != 0)//���Ӧa�観�X�l
		{
			maxDown = i;
			if (identity <= 7 && Board.nowBoard[i][coordinates.Y].chessNum > 7)
			{
				if (Board.nowBoard[i][coordinates.Y].chessNum == 8)
				{
					Board.isKing = true;
				}
			}
			else if (identity > 7 && Board.nowBoard[i][coordinates.Y].chessNum <= 7) {
				if (Board.nowBoard[i][coordinates.Y].chessNum == 1)
				{
					Board.isKing = true;
				}
			}
			
			break;
		}
	
	}
}

void RookChess::moveUp(int a ,int b, board & Board)
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
				//����
			}
			else
			{
				//�L��
			}
		}

	
}

void RookChess::moveHorizon(int a,int b, board & Board)
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
			//����
		}
		else
		{
			//�L��
		}
	}
	
}

void RookChess::moveBack(int a, int b, board & Board)
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
			//����
		}
		else
		{
			//�L��
		}
	}
}