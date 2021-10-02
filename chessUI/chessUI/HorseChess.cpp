#include "HorseChess.h"



void HorseChess::check(board & Board)
{
	if (coordinates.X - 2 >= 2 && Board.nowBoard[coordinates.X - 2][coordinates.Y].chessNum == 0)//日形上無馬腳
	{
		if (coordinates.X - 4 >= 2 && coordinates.Y - 2 >= 1) {
			if (Board.nowBoard[coordinates.X - 4][coordinates.Y - 2].chessNum != 0)//左上日有旗子
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
			if (Board.nowBoard[coordinates.X - 4][coordinates.Y + 2].chessNum != 0)//右上日有旗子
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
			if (Board.nowBoard[coordinates.X + 4][coordinates.Y - 2].chessNum != 0)//左下日有旗子
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
			if (Board.nowBoard[coordinates.X + 4][coordinates.Y + 2].chessNum != 0)//右下日有旗子
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

	if (coordinates.Y - 2 >= 1 && Board.nowBoard[coordinates.X][coordinates.Y - 2].chessNum == 0)//左無馬腳
	{
		if (coordinates.X - 2 >= 2 && coordinates.Y - 4 >= 1) {
			if (Board.nowBoard[coordinates.X - 2][coordinates.Y - 4].chessNum != 0)//有棋
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
			if (Board.nowBoard[coordinates.X + 2][coordinates.Y - 4].chessNum != 0)//有棋
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

	if (coordinates.Y + 2 <= 17 && Board.nowBoard[coordinates.X][coordinates.Y + 2].chessNum == 0)//右無馬腳
	{
		if (coordinates.X - 2 >= 2 && coordinates.Y + 4 <= 17) {
			if (Board.nowBoard[coordinates.X - 2][coordinates.Y + 4].chessNum != 0)//有棋
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
			if (Board.nowBoard[coordinates.X + 2][coordinates.Y + 4].chessNum != 0)//有棋
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

void HorseChess::moveColor(board & Board)
{
	//--------------日形
	
	if(coordinates.X - 2 >= 2 && Board.nowBoard[coordinates.X - 2][coordinates.Y].chessNum == 0)//日形上無馬腳
	{
		if (coordinates.X - 4 >= 2 && coordinates.Y - 2 >= 1) {
			if (Board.nowBoard[coordinates.X - 4][coordinates.Y - 2].chessNum != 0)//左上日有旗子
			{
				if (isEnemy(coordinates.X - 4, coordinates.Y - 2, Board))
				{
					//紅色
					Board.nowBoard[coordinates.X - 4][coordinates.Y - 2].colorNum = 5;
				}
			}
			else
			{
				//藍色
				Board.nowBoard[coordinates.X - 4][coordinates.Y - 2].colorNum = 4;
			}
		}
		
		if (coordinates.X - 4 >= 2 && coordinates.Y + 2 <= 17) {
			if (Board.nowBoard[coordinates.X - 4][coordinates.Y + 2].chessNum != 0)//右上日有旗子
			{
				if (isEnemy(coordinates.X - 4, coordinates.Y + 2, Board))
				{
					//紅色
					Board.nowBoard[coordinates.X - 4][coordinates.Y + 2].colorNum = 5;
				}
			}
			else
			{
				//藍色
				Board.nowBoard[coordinates.X - 4][coordinates.Y + 2].colorNum = 4;
			}
		}
		
	}


	if(coordinates.X + 2 <= 20 && Board.nowBoard[coordinates.X + 2][coordinates.Y].chessNum == 0)
	{
		if (coordinates.X + 4 <= 20 && coordinates.Y - 2 >= 1) {
			if (Board.nowBoard[coordinates.X + 4][coordinates.Y - 2].chessNum != 0)//左下日有旗子
			{
				if (isEnemy(coordinates.X + 4, coordinates.Y - 2, Board))
				{
					//紅色
					Board.nowBoard[coordinates.X + 4][coordinates.Y - 2].colorNum = 5;
				}
			}
			else
			{
				//藍色
				Board.nowBoard[coordinates.X + 4][coordinates.Y - 2].colorNum = 4;
			}
		}

		if (coordinates.X + 4 <= 20 && coordinates.Y + 2 <= 17) {
			if (Board.nowBoard[coordinates.X + 4][coordinates.Y + 2].chessNum != 0)//右下日有旗子
			{
				if (isEnemy(coordinates.X + 4, coordinates.Y + 2, Board))
				{
					//紅色
					Board.nowBoard[coordinates.X + 4][coordinates.Y + 2].colorNum = 5;
				}
			}
			else
			{
				//藍色
				Board.nowBoard[coordinates.X + 4][coordinates.Y + 2].colorNum = 4;
			}
		}
		
	}

	//口口型-----------------------------------
	if (coordinates.Y - 2 >= 1 && Board.nowBoard[coordinates.X][coordinates.Y - 2].chessNum == 0)//左無馬腳
	{
		if (coordinates.X - 2 >= 2 && coordinates.Y - 4 >= 1) {
			if (Board.nowBoard[coordinates.X - 2][coordinates.Y - 4].chessNum == 0)//左上此處無棋
			{
				//藍色
				Board.nowBoard[coordinates.X - 2][coordinates.Y - 4].colorNum = 4;
			}
			else//有棋
			{
				if (isEnemy(coordinates.X - 2, coordinates.Y - 4, Board))
				{
					//紅色
					Board.nowBoard[coordinates.X - 2][coordinates.Y - 4].colorNum = 5;
				}
			}
		}

		if (coordinates.X + 2 <= 20 && coordinates.Y - 4 >= 1) {
			if (Board.nowBoard[coordinates.X + 2][coordinates.Y - 4].chessNum == 0)//左下此處無棋
			{
				//藍色
				Board.nowBoard[coordinates.X + 2][coordinates.Y - 4].colorNum = 4;
			}
			else//有棋
			{
				if (isEnemy(coordinates.X + 2, coordinates.Y - 4, Board))
				{
					//紅色
					Board.nowBoard[coordinates.X + 2][coordinates.Y - 4].colorNum = 5;
				}
			}
		}
		
	}

	if (coordinates.Y + 2 <= 17 && Board.nowBoard[coordinates.X][coordinates.Y + 2].chessNum == 0)//右無馬腳
	{
		if (coordinates.X - 2 >= 2 && coordinates.Y + 4 <= 17) {
			if (Board.nowBoard[coordinates.X - 2][coordinates.Y + 4].chessNum == 0)//右上此處無棋
			{
				//藍色
				Board.nowBoard[coordinates.X - 2][coordinates.Y + 4].colorNum = 4;
			}
			else//有棋
			{
				if (isEnemy(coordinates.X - 2, coordinates.Y + 4, Board))
				{
					//紅色
					Board.nowBoard[coordinates.X - 2][coordinates.Y + 4].colorNum = 5;
				}
			}
		}

		if (coordinates.X + 2 <= 20 && coordinates.Y + 4 <= 17) {
			if (Board.nowBoard[coordinates.X + 2][coordinates.Y + 4].chessNum == 0)//右下此處無棋
			{
				//藍色
				Board.nowBoard[coordinates.X + 2][coordinates.Y + 4].colorNum = 4;
			}
			else//有棋
			{
				if (isEnemy(coordinates.X + 2, coordinates.Y + 4, Board))
				{
					//紅色
					Board.nowBoard[coordinates.X + 2][coordinates.Y + 4].colorNum = 5;
				}
			}
		}
		
	}

}

void HorseChess::moveUp(int a, int b, board & Board)
{
	if (a == (coordinates.X - 4) && b == (coordinates.Y - 2))//左日
	{
		if (Board.nowBoard[a][b].colorNum == 5)
		{
			coordinates.X = a;
			coordinates.Y = b;
			if (Board.nowBoard[a][b].chessNum == 1 || Board.nowBoard[a][b].chessNum == 8)
			{
				Board.isWin = true;
			}
			//吃棋
		}
		else if (Board.nowBoard[a][b].colorNum == 4)
		{
			coordinates.X = a;
			coordinates.Y = b;
			//移動
		}
	}

	if (a == (coordinates.X - 4) && b == (coordinates.Y + 2))//右日
	{
		if (Board.nowBoard[a][b].colorNum == 5)
		{
			coordinates.X = a;
			coordinates.Y = b;
			if (Board.nowBoard[a][b].chessNum == 1 || Board.nowBoard[a][b].chessNum == 8)
			{
				Board.isWin = true;
			}
			//吃棋
		}
		else if (Board.nowBoard[a][b].colorNum == 4)
		{
			coordinates.X = a;
			coordinates.Y = b;
			//移動
		}
	}

	if (a == (coordinates.X - 2) && b == (coordinates.Y - 4))//左口口
	{
		if (Board.nowBoard[a][b].colorNum == 5)
		{
			coordinates.X = a;
			coordinates.Y = b;
			if (Board.nowBoard[a][b].chessNum == 1 || Board.nowBoard[a][b].chessNum == 8)
			{
				Board.isWin = true;
			}
			//吃棋
		}
		else if (Board.nowBoard[a][b].colorNum == 4)
		{
			coordinates.X = a;
			coordinates.Y = b;
			//移動
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
			//吃棋
		}
		else if (Board.nowBoard[a][b].colorNum == 4)
		{
			coordinates.X = a;
			coordinates.Y = b;
			//移動
		}
	}
}

void HorseChess::moveBack(int a, int b, board & Board)
{
	if (a == (coordinates.X + 4) && b == (coordinates.Y - 2))//左日
	{
		if (Board.nowBoard[a][b].colorNum == 5)
		{
			coordinates.X = a;
			coordinates.Y = b;
			if (Board.nowBoard[a][b].chessNum == 1 || Board.nowBoard[a][b].chessNum == 8)
			{
				Board.isWin = true;
			}
			//吃棋
		}
		else if (Board.nowBoard[a][b].colorNum == 4)
		{
			coordinates.X = a;
			coordinates.Y = b;
			//移動
		}
	}

	if (a == (coordinates.X + 4) && b == (coordinates.Y + 2))//右日
	{
		if (Board.nowBoard[a][b].colorNum == 5)
		{
			coordinates.X = a;
			coordinates.Y = b;
			if (Board.nowBoard[a][b].chessNum == 1 || Board.nowBoard[a][b].chessNum == 8)
			{
				Board.isWin = true;
			}
			//吃棋
		}
		else if (Board.nowBoard[a][b].colorNum == 4)
		{
			coordinates.X = a;
			coordinates.Y = b;
			//移動
		}
	}

	if (a == (coordinates.X + 2) && b == (coordinates.Y - 4))//左口口
	{
		if (Board.nowBoard[a][b].colorNum == 5)
		{
			coordinates.X = a;
			coordinates.Y = b;
			if (Board.nowBoard[a][b].chessNum == 1 || Board.nowBoard[a][b].chessNum == 8)
			{
				Board.isWin = true;
			}
			//吃棋
		}
		else if (Board.nowBoard[a][b].colorNum == 4)
		{
			coordinates.X = a;
			coordinates.Y = b;
			//移動
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
			//吃棋
		}
		else if (Board.nowBoard[a][b].colorNum == 4)
		{
			coordinates.X = a;
			coordinates.Y = b;
			//移動
		}
	}
}