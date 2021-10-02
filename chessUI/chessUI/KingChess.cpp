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

//將/帥走的範圍不能超過九宮格
//走法是上、下、左、右
void KingChess::moveColor(board & Board)
{
	//紅
	if (identity > 7)
	{
		//左
		if (Board.nowBoard[coordinates.X][coordinates.Y - 2].chessNum != 0 && coordinates.Y > 7)
		{
			if (Board.nowBoard[coordinates.X][coordinates.Y - 2].chessNum <= 7)//有旗子且為敵方
			{
				//紅色
				Board.nowBoard[coordinates.X][coordinates.Y - 2].colorNum = 5;
			}
		}
		else if (Board.nowBoard[coordinates.X][coordinates.Y - 2].chessNum == 0 && coordinates.Y > 7)
		{
			//藍色
			Board.nowBoard[coordinates.X][coordinates.Y - 2].colorNum = 4;
		}

		//右
		if (Board.nowBoard[coordinates.X][coordinates.Y + 2].chessNum != 0 && coordinates.Y < 11)
		{
			if (Board.nowBoard[coordinates.X][coordinates.Y + 2].chessNum <= 7)//有旗子且為敵方
			{
				//紅色
				Board.nowBoard[coordinates.X][coordinates.Y + 2].colorNum = 5;
			}
		}
		else if (Board.nowBoard[coordinates.X][coordinates.Y + 2].chessNum == 0 && coordinates.Y < 11)
		{
			//藍色
			Board.nowBoard[coordinates.X][coordinates.Y + 2].colorNum = 4;
		}

		//上
		if (Board.nowBoard[coordinates.X - 2][coordinates.Y].chessNum != 0 && coordinates.X > 16)
		{
			if (Board.nowBoard[coordinates.X - 2][coordinates.Y].chessNum <= 7)//有旗子且為敵方
			{
				//紅色
				Board.nowBoard[coordinates.X - 2][coordinates.Y].colorNum = 5;
			}
		}
		else if (Board.nowBoard[coordinates.X - 2][coordinates.Y].chessNum == 0 && coordinates.X > 16)
		{
			//藍色
			Board.nowBoard[coordinates.X - 2][coordinates.Y].colorNum = 4;
		}

		//王見王
		for (int j = coordinates.X - 2; j >= 2; j -= 2)
		{
			if (Board.nowBoard[j][coordinates.Y].chessNum != 0 && Board.nowBoard[j][coordinates.Y].chessNum == 1)
			{
				//紅色
				Board.nowBoard[j][coordinates.Y].colorNum = 5;
				break;
			}	
		}

		//下
		if (Board.nowBoard[coordinates.X + 2][coordinates.Y].chessNum != 0 && coordinates.X < 20)
		{
			if (Board.nowBoard[coordinates.X + 2][coordinates.Y].chessNum <= 7)//有旗子且為敵方
			{
				//紅色
				Board.nowBoard[coordinates.X + 2][coordinates.Y].colorNum = 5;
			}
		}
		else if (Board.nowBoard[coordinates.X + 2][coordinates.Y].chessNum == 0 && coordinates.X < 20)
		{
			//藍色
			Board.nowBoard[coordinates.X + 2][coordinates.Y].colorNum = 4;
		}
	}

	//黑
	else
	{
		//左
		if (Board.nowBoard[coordinates.X][coordinates.Y - 2].chessNum != 0 && coordinates.Y > 7)
		{
			if (Board.nowBoard[coordinates.X][coordinates.Y - 2].chessNum > 7)//有旗子且為敵方
			{
				//紅色
				Board.nowBoard[coordinates.X][coordinates.Y - 2].colorNum = 5;
			}
		}
		else if (Board.nowBoard[coordinates.X][coordinates.Y - 2].chessNum == 0 && coordinates.Y > 7)
		{
			//藍色
			Board.nowBoard[coordinates.X][coordinates.Y - 2].colorNum = 4;
		}

		//右
		if (Board.nowBoard[coordinates.X][coordinates.Y + 2].chessNum != 0 && coordinates.Y < 11)
		{
			if (Board.nowBoard[coordinates.X][coordinates.Y + 2].chessNum > 7)//有旗子且為敵方
			{
				//紅色
				Board.nowBoard[coordinates.X][coordinates.Y + 2].colorNum = 5;
			}
		}
		else if (Board.nowBoard[coordinates.X][coordinates.Y + 2].chessNum == 0 && coordinates.Y < 11)
		{
			//藍色
			Board.nowBoard[coordinates.X][coordinates.Y + 2].colorNum = 4;
		}

		//上
		if (Board.nowBoard[coordinates.X - 2][coordinates.Y].chessNum != 0 && coordinates.X > 2)
		{
			if (Board.nowBoard[coordinates.X - 2][coordinates.Y].chessNum > 7)//有旗子且為敵方
			{
				//紅色
				Board.nowBoard[coordinates.X - 2][coordinates.Y].colorNum = 5;
			}
		}
		else if (Board.nowBoard[coordinates.X - 2][coordinates.Y].chessNum == 0 && coordinates.X > 2)
		{
			//藍色
			Board.nowBoard[coordinates.X - 2][coordinates.Y].colorNum = 4;
		}

		//下
		if (Board.nowBoard[coordinates.X + 2][coordinates.Y].chessNum != 0 && coordinates.X < 6)
		{
			if (Board.nowBoard[coordinates.X + 2][coordinates.Y].chessNum > 7)//有旗子且為敵方
			{
				//紅色
				Board.nowBoard[coordinates.X + 2][coordinates.Y].colorNum = 5;
			}
		}
		else if (Board.nowBoard[coordinates.X + 2][coordinates.Y].chessNum == 0 && coordinates.X < 6)
		{
			//藍色
			Board.nowBoard[coordinates.X + 2][coordinates.Y].colorNum = 4;
		}

		//王見王
		for (int j = coordinates.X + 2; j <= 20; j += 2)
		{
			if (Board.nowBoard[j][coordinates.Y].chessNum != 0 && Board.nowBoard[j][coordinates.Y].chessNum == 8)
			{
				//紅色
				Board.nowBoard[j][coordinates.Y].colorNum = 5;
				break;
			}
		}
	}
}

void KingChess::moveUp(int a, int b, board & Board)
{
	//紅
	if (identity > 7)
	{
		if (a == (coordinates.X - 2) && b == coordinates.Y && a >= 16)//上面一格
		{
			if (Board.nowBoard[a][b].colorNum == 5)
			{
				coordinates.X = a;
				//吃棋
			}
			else if (Board.nowBoard[a][b].colorNum == 4)
			{
				coordinates.X = a;
			}
		}

		//王見王
		if (b == coordinates.Y)
		{
			for (int a = 6; a >= 2; a - 2)
			{
				if (Board.nowBoard[a][b].colorNum == 5)
				{
					coordinates.X = a;
					//吃棋
				}
			}
		}

	}
	//黑
	else {
		if (a == (coordinates.X - 2) && b == coordinates.Y && a >= 2)//上面一格
		{
			if (Board.nowBoard[a][b].colorNum == 5)
			{
				coordinates.X = a;
				//吃棋
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
	//左
	if (a == coordinates.X && b == (coordinates.Y - 2) && b >= 7)//上面一格
	{
		if (Board.nowBoard[a][b].colorNum == 5)
		{
			coordinates.Y = b;
			//吃棋
		}
		else if (Board.nowBoard[a][b].colorNum == 4)
		{
			coordinates.Y = b;
		}
	}

	//右
	if (a == coordinates.X && b == (coordinates.Y + 2) && b <= 11)//上面一格
	{
		if (Board.nowBoard[a][b].colorNum == 5)
		{
			coordinates.Y = b;
			//吃棋
		}
		else if (Board.nowBoard[a][b].colorNum == 4)
		{
			coordinates.Y = b;
		}
	}
}


void KingChess::moveBack(int a, int b, board & Board)
{
	//紅
	if (identity > 7)
	{
		if (a == (coordinates.X + 2) && b == coordinates.Y && a <= 20)//上面一格
		{
			if (Board.nowBoard[a][b].colorNum == 5)
			{
				coordinates.X = a;
				//吃棋
			}
			else if (Board.nowBoard[a][b].colorNum == 4)
			{
				coordinates.X = a;
			}
		}
	}
	//黑
	else {
		if (a == (coordinates.X + 2) && b == coordinates.Y && a <= 6)//上面一格
		{
			if (Board.nowBoard[a][b].colorNum == 5)
			{
				coordinates.X = a;
				//吃棋
			}
			else if (Board.nowBoard[a][b].colorNum == 4)
			{
				coordinates.X = a;
			}
		}

		//王見王
		if (b == coordinates.Y)
		{
			for (int a = 16; a <= 20; a + 2)
			{
				if (Board.nowBoard[a][b].colorNum == 5)
				{
					coordinates.X = a;
					//吃棋
				}
			}
		}
	}
}

void KingChess::Check(board & Board)
{
	//只有王見王才可能有將軍情形

	//紅
	if (identity > 7) {
		//王見王
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

	//黑
	else
	{
		//王見王
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
