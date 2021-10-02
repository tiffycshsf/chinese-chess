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
	
	//先判斷同一行往左是否有旗子
	for (int i = coordinates.Y - 2; i >= 1 ; i -= 2)
	{
		if (Board.nowBoard[coordinates.X][i].chessNum != 0)//那個地方有旗子
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
				//同陣營不變色
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
		if (Board.nowBoard[coordinates.X][i].chessNum != 0)//那個地方有旗子
		{
			maxRight = i;
			if (identity <= 7 && Board.nowBoard[coordinates.X][i].chessNum > 7)
			{
				//變成紅色
				Board.nowBoard[coordinates.X][i].colorNum = 5;
			}
			else if (identity > 7 && Board.nowBoard[coordinates.X][i].chessNum <= 7) {
				Board.nowBoard[coordinates.X][i].colorNum = 5;
			}
			else
			{
				//同陣營不變色
			}
			break;
		}
		else
		{
			maxRight = 17;
			Board.nowBoard[coordinates.X][i].colorNum = 4;//變成藍色
		}

	}//同一行變色完畢
	
	for (int i = coordinates.X - 2; i >= 2; i -= 2)//column往上時變色
	{
		if (Board.nowBoard[i][coordinates.Y].chessNum != 0)//那個地方有旗子
		{
			maxUp = i;
			if (identity <= 7 && Board.nowBoard[i][coordinates.Y].chessNum > 7)
			{
				//變成紅色
				Board.nowBoard[i][coordinates.Y].colorNum = 5;
			}
			else if (identity > 7 && Board.nowBoard[i][coordinates.Y].chessNum <= 7) {
				Board.nowBoard[i][coordinates.Y].colorNum = 5;
			}
			else
			{
				//同陣營不變色
			}
			break;
		}
		else
		{
			maxUp = 2;
			Board.nowBoard[i][coordinates.Y].colorNum = 4;//變成藍色
		}

	}
	for (int i = coordinates.X + 2; i <= 20; i += 2)//column往下時變色
	{
		if (Board.nowBoard[i][coordinates.Y].chessNum != 0)//那個地方有旗子
		{
			maxDown = i;
			if (identity <= 7 && Board.nowBoard[i][coordinates.Y].chessNum > 7)
			{
				//變成紅色
				Board.nowBoard[i][coordinates.Y].colorNum = 5;
			}
			else if (identity > 7 && Board.nowBoard[i][coordinates.Y].chessNum <= 7) {
				Board.nowBoard[i][coordinates.Y].colorNum = 5;
			}
			else
			{
				//同陣營不變色
			}
			break;
		}
		else//沒旗子 可以走
		{
			maxDown = 20;
			Board.nowBoard[i][coordinates.Y].colorNum = 4;//變成藍色
		}

	}

}

void RookChess::check(board & Board)
{
	//先判斷同一行往左是否有旗子
	for (int i = coordinates.Y - 2; i >= 1; i -= 2)
	{
		if (Board.nowBoard[coordinates.X][i].chessNum != 0)//那個地方有旗子
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
		if (Board.nowBoard[coordinates.X][i].chessNum != 0)//那個地方有旗子
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

	for (int i = coordinates.X - 2; i >= 2; i -= 2)//column往上時
	{
		if (Board.nowBoard[i][coordinates.Y].chessNum != 0)//那個地方有旗子
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
	for (int i = coordinates.X + 2; i <= 20; i += 2)//column往下時
	{
		if (Board.nowBoard[i][coordinates.Y].chessNum != 0)//那個地方有旗子
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
				//吃棋
			}
			else if (Board.nowBoard[a][b].colorNum == 4)
			{
				coordinates.X = a;
				//移動
			}
			else
			{
				//無效
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
			//吃棋
		}
		else if (Board.nowBoard[a][b].colorNum == 4)
		{
			coordinates.Y = b;
			//移動
		}
		else
		{
			//無效
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
			//吃棋
		}
		else if (Board.nowBoard[a][b].colorNum == 4)
		{
			coordinates.X = a;
			//移動
		}
		else
		{
			//無效
		}
	}
}