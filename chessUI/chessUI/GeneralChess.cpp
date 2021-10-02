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

//士/仕走的範圍不能超過九宮格
//走法是右上、右下、左上、左下

void GeneralChess::moveColor(board & Board)
{
	//紅
	if (identity > 7)
	{
		//左上
		if (coordinates.X > 16 && coordinates.Y > 7) {
			if (Board.nowBoard[coordinates.X - 2][coordinates.Y - 2].chessNum != 0)
			{
				if (Board.nowBoard[coordinates.X - 2][coordinates.Y - 2].chessNum <= 7)//有旗子且為敵方
				{
					//紅色
					Board.nowBoard[coordinates.X - 2][coordinates.Y - 2].colorNum = 5;
				}
			}
			else
			{
				//藍色
				Board.nowBoard[coordinates.X - 2][coordinates.Y - 2].colorNum = 4;
			}
		}

		//右上
		if (coordinates.X > 16 && coordinates.Y < 11) {
			if (Board.nowBoard[coordinates.X - 2][coordinates.Y + 2].chessNum != 0)
			{
				if (Board.nowBoard[coordinates.X - 2][coordinates.Y + 2].chessNum <= 7)//有旗子且為敵方
				{
					//紅色
					Board.nowBoard[coordinates.X - 2][coordinates.Y + 2].colorNum = 5;
				}
			}
			else
			{
				//藍色
				Board.nowBoard[coordinates.X - 2][coordinates.Y + 2].colorNum = 4;
			}
		}

		//左下
		if (coordinates.X < 20 && coordinates.Y > 7) {
			if (Board.nowBoard[coordinates.X + 2][coordinates.Y - 2].chessNum != 0)
			{
				if (Board.nowBoard[coordinates.X + 2][coordinates.Y - 2].chessNum <= 7)//有旗子且為敵方
				{
					//紅色
					Board.nowBoard[coordinates.X + 2][coordinates.Y - 2].colorNum = 5;
				}
			}
			else
			{
				//藍色
				Board.nowBoard[coordinates.X + 2][coordinates.Y - 2].colorNum = 4;
			}
		}

		//右下
		if (coordinates.X < 20 && coordinates.Y < 11) {
			if (Board.nowBoard[coordinates.X + 2][coordinates.Y + 2].chessNum != 0)
			{
				if (Board.nowBoard[coordinates.X + 2][coordinates.Y + 2].chessNum <= 7)//有旗子且為敵方
				{
					//紅色
					Board.nowBoard[coordinates.X + 2][coordinates.Y + 2].colorNum = 5;
				}
			}
			else
			{
				//藍色
				Board.nowBoard[coordinates.X + 2][coordinates.Y + 2].colorNum = 4;
			}
		}
	}

	//黑
	else
	{
		//左上
		if (coordinates.X > 2 && coordinates.Y > 7) {
			if (Board.nowBoard[coordinates.X - 2][coordinates.Y - 2].chessNum != 0)
			{
				if (Board.nowBoard[coordinates.X - 2][coordinates.Y - 2].chessNum > 7)//有旗子且為敵方
				{
					//紅色
					Board.nowBoard[coordinates.X - 2][coordinates.Y - 2].colorNum = 5;
				}
			}
			else
			{
				//藍色
				Board.nowBoard[coordinates.X - 2][coordinates.Y - 2].colorNum = 4;
			}
		}


		//右上
		if (coordinates.X > 2 && coordinates.Y < 11) {
			if (Board.nowBoard[coordinates.X - 2][coordinates.Y + 2].chessNum != 0)
			{
				if (Board.nowBoard[coordinates.X - 2][coordinates.Y + 2].chessNum > 7)//有旗子且為敵方
				{
					//紅色
					Board.nowBoard[coordinates.X - 2][coordinates.Y + 2].colorNum = 5;
				}
			}
			else
			{
				//藍色
				Board.nowBoard[coordinates.X - 2][coordinates.Y + 2].colorNum = 4;
			}
		}

		//左下
		if (coordinates.X < 6 && coordinates.Y > 7) {
			if (Board.nowBoard[coordinates.X + 2][coordinates.Y - 2].chessNum != 0)
			{
				if (Board.nowBoard[coordinates.X + 2][coordinates.Y - 2].chessNum > 7)//有旗子且為敵方
				{
					//紅色
					Board.nowBoard[coordinates.X + 2][coordinates.Y - 2].colorNum = 5;
				}
			}
			else
			{
				//藍色
				Board.nowBoard[coordinates.X + 2][coordinates.Y - 2].colorNum = 4;
			}
		}

		//右下
		if (coordinates.X < 6 && coordinates.Y < 11) {
			if (Board.nowBoard[coordinates.X + 2][coordinates.Y + 2].chessNum != 0)
			{
				if (Board.nowBoard[coordinates.X + 2][coordinates.Y + 2].chessNum > 7)//有旗子且為敵方
				{
					//紅色
					Board.nowBoard[coordinates.X + 2][coordinates.Y + 2].colorNum = 5;
				}
			}
			else
			{
				//藍色
				Board.nowBoard[coordinates.X + 2][coordinates.Y + 2].colorNum = 4;
			}
		}
	}
}

void GeneralChess::moveUp(int a, int b, board & Board)
{
	//紅
	if (identity > 7)
	{
		//左上
		if (a >= 16 && b >= 7) {
			if (a == (coordinates.X - 2) && b == (coordinates.Y - 2))
			{
				if (Board.nowBoard[a][b].colorNum == 5)
				{
					coordinates.X = a;
					coordinates.Y = b;
					//吃棋
				}
				else if (Board.nowBoard[a][b].colorNum == 4)
				{
					coordinates.X = a;
					coordinates.Y = b;
				}
			}
		}

		//右上
		if (a >= 16 && b <= 11) {
			if (a == (coordinates.X - 2) && b == (coordinates.Y + 2))
			{
				if (Board.nowBoard[a][b].colorNum == 5)
				{
					coordinates.X = a;
					coordinates.Y = b;
					//吃棋
				}
				else if (Board.nowBoard[a][b].colorNum == 4)
				{
					coordinates.X = a;
					coordinates.Y = b;
				}
			}
		}

	}
	//黑
	else {
		//左上
		if (a >= 2 && b >= 7) {
			if (a == (coordinates.X - 2) && b == (coordinates.Y - 2))
			{
				if (Board.nowBoard[a][b].colorNum == 5)
				{
					coordinates.X = a;
					coordinates.Y = b;
					//吃棋
				}
				else if (Board.nowBoard[a][b].colorNum == 4)
				{
					coordinates.X = a;
					coordinates.Y = b;
				}
			}
		}
		
		//右上
		if (a >= 2 && b <= 11) {
			if (a == (coordinates.Y - 2) && b == (coordinates.Y + 2))
			{
				if (Board.nowBoard[a][b].colorNum == 5)
				{
					coordinates.X = a;
					coordinates.Y = b;
					//吃棋
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
	//紅
	if (identity > 7)
	{
		//左下
		if (a <= 20 && b >= 7) {
			if (a == (coordinates.Y + 2) && b == (coordinates.Y - 2))
			{
				if (Board.nowBoard[a][b].colorNum == 5)
				{
					coordinates.X = a;
					coordinates.Y = b;
					//吃棋
				}
				else if (Board.nowBoard[a][b].colorNum == 4)
				{
					coordinates.X = a;
					coordinates.Y = b;
				}
			}
		}

		//右下
		if (a <= 20 && b <= 11) {
			if (a == (coordinates.Y + 2) && b == (coordinates.Y + 2))
			{
				if (Board.nowBoard[a][b].colorNum == 5)
				{
					coordinates.X = a;
					coordinates.Y = b;
					//吃棋
				}
				else if (Board.nowBoard[a][b].colorNum == 4)
				{
					coordinates.X = a;
					coordinates.Y = b;
				}
			}
		}
	}
	//黑
	else {
		//左下
		if (a <= 6 && b >= 7) {
			if (a == (coordinates.Y + 2) && b == (coordinates.Y - 2))
			{
				if (Board.nowBoard[a][b].colorNum == 5)
				{
					coordinates.X = a;
					coordinates.Y = b;
					//吃棋
				}
				else if (Board.nowBoard[a][b].colorNum == 4)
				{
					coordinates.X = a;
					coordinates.Y = b;
				}
			}
		}

		//右下
		if (a <= 6 && b <= 11) {
			if (a == (coordinates.Y + 2) && b == (coordinates.Y + 2))
			{
				if (Board.nowBoard[a][b].colorNum == 5)
				{
					coordinates.X = a;
					coordinates.Y = b;
					//吃棋
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
