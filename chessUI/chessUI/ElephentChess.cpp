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

//象/相走的範圍不能過河
//走法是右上田、右下田、左上田、左下田
//如果右上、右下、左上、左下有棋子則不能走

void ElephentChess::moveColor(board & Board)
{
	//紅
	if (identity > 7)
	{
		//左上田
		if (coordinates.X >= 16 && coordinates.Y >= 5) {
			if (Board.nowBoard[coordinates.X - 2][coordinates.Y - 2].chessNum == 0) {
				if (Board.nowBoard[coordinates.X - 4][coordinates.Y - 4].chessNum != 0)
				{
					if (Board.nowBoard[coordinates.X - 4][coordinates.Y - 4].chessNum <= 7)//有旗子且為敵方
					{
						//紅色
						Board.nowBoard[coordinates.X - 4][coordinates.Y - 4].colorNum = 5;
					}
				}
				else
				{
					//藍色
					Board.nowBoard[coordinates.X - 4][coordinates.Y - 4].colorNum = 4;
				}
			}
		}
		

		//右上田
		if (coordinates.X >= 16 && coordinates.Y <= 13) {
			if (Board.nowBoard[coordinates.X - 2][coordinates.Y + 2].chessNum == 0) {
				if (Board.nowBoard[coordinates.X - 4][coordinates.Y + 4].chessNum != 0)
				{
					if (Board.nowBoard[coordinates.X - 4][coordinates.Y + 4].chessNum <= 7)//有旗子且為敵方
					{
						//紅色
						Board.nowBoard[coordinates.X - 4][coordinates.Y + 4].colorNum = 5;
					}
				}
				else
				{
					//藍色
					Board.nowBoard[coordinates.X - 4][coordinates.Y + 4].colorNum = 4;
				}
			}
		}


		//左下田
		if (coordinates.X <= 16 && coordinates.Y >= 5) {
			if (Board.nowBoard[coordinates.X + 2][coordinates.Y - 2].chessNum == 0) {
				if (Board.nowBoard[coordinates.X + 4][coordinates.Y - 4].chessNum != 0)
				{
					if (Board.nowBoard[coordinates.X + 4][coordinates.Y - 4].chessNum <= 7)//有旗子且為敵方
					{
						//紅色
						Board.nowBoard[coordinates.X + 4][coordinates.Y - 4].colorNum = 5;
					}
				}
				else
				{
					//藍色
					Board.nowBoard[coordinates.X + 4][coordinates.Y - 4].colorNum = 4;
				}
			}
		}


		//右下田
		if (coordinates.X <= 16 && coordinates.Y <= 13) {
			if (Board.nowBoard[coordinates.X + 2][coordinates.Y + 2].chessNum == 0) {
				if (Board.nowBoard[coordinates.X + 4][coordinates.Y + 4].chessNum != 0)
				{
					if (Board.nowBoard[coordinates.X + 4][coordinates.Y + 4].chessNum <= 7)//有旗子且為敵方
					{
						//紅色
						Board.nowBoard[coordinates.X + 4][coordinates.Y + 4].colorNum = 5;
					}
				}
				else
				{
					//藍色
					Board.nowBoard[coordinates.X + 4][coordinates.Y + 4].colorNum = 4;
				}
			}
		}

	}

	//黑
	else
	{
		//左上田
		if (coordinates.X >= 6 && coordinates.Y >= 5) {
			if (Board.nowBoard[coordinates.X - 2][coordinates.Y - 2].chessNum == 0) {
				if (Board.nowBoard[coordinates.X - 4][coordinates.Y - 4].chessNum != 0)
				{
					if (Board.nowBoard[coordinates.X - 4][coordinates.Y - 4].chessNum > 7)//有旗子且為敵方
					{
						//紅色
						Board.nowBoard[coordinates.X - 4][coordinates.Y - 4].colorNum = 5;
					}
				}
				else
				{
					//藍色
					Board.nowBoard[coordinates.X - 4][coordinates.Y - 4].colorNum = 4;
				}
			}
		}


		//右上田
		if (coordinates.X >= 6 && coordinates.Y <= 13) {
			if (Board.nowBoard[coordinates.X - 2][coordinates.Y + 2].chessNum == 0) {
				if (Board.nowBoard[coordinates.X - 4][coordinates.Y + 4].chessNum != 0)
				{
					if (Board.nowBoard[coordinates.X - 4][coordinates.Y + 4].chessNum > 7)//有旗子且為敵方
					{
						//紅色
						Board.nowBoard[coordinates.X - 4][coordinates.Y + 4].colorNum = 5;
					}
				}
				else
				{
					//藍色
					Board.nowBoard[coordinates.X - 4][coordinates.Y + 4].colorNum = 4;
				}
			}
		}


		//左下田
		if (coordinates.X <= 6 && coordinates.Y >= 5) {
			if (Board.nowBoard[coordinates.X + 2][coordinates.Y - 2].chessNum == 0) {
				if (Board.nowBoard[coordinates.X + 4][coordinates.Y - 4].chessNum != 0)
				{
					if (Board.nowBoard[coordinates.X + 4][coordinates.Y - 4].chessNum > 7)//有旗子且為敵方
					{
						//紅色
						Board.nowBoard[coordinates.X + 4][coordinates.Y - 4].colorNum = 5;
					}
				}
				else
				{
					//藍色
					Board.nowBoard[coordinates.X + 4][coordinates.Y - 4].colorNum = 4;
				}
			}
		}


		//右下田
		if (coordinates.X <= 6 && coordinates.Y <= 13) {
			if (Board.nowBoard[coordinates.X + 2][coordinates.Y + 2].chessNum == 0) {
				if (Board.nowBoard[coordinates.X + 4][coordinates.Y + 4].chessNum != 0)
				{
					if (Board.nowBoard[coordinates.X + 4][coordinates.Y + 4].chessNum > 7)//有旗子且為敵方
					{
						//紅色
						Board.nowBoard[coordinates.X + 4][coordinates.Y + 4].colorNum = 5;
					}
				}
				else
				{
					//藍色
					Board.nowBoard[coordinates.X + 4][coordinates.Y + 4].colorNum = 4;
				}
			}
		}
	}
}

void ElephentChess::moveUp(int a, int b, board & Board)
{
	//紅
	if (identity > 7)
	{
		//左上田
		if (a >= 16 && b >= 5) {
			if (a == (coordinates.X - 4) && b == (coordinates.Y - 4))
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

		//右上田
		if (a >= 16 && b <= 13) {
			if (a == (coordinates.X - 4) && b == (coordinates.Y + 4))
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
		//左上田
		if (a >= 6 && b >= 5) {
			if (a == (coordinates.X - 4) && b == (coordinates.Y - 4))
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

		//右上田
		if (a >= 6 && b <= 13) {
			if (a == (coordinates.X - 4) && b == (coordinates.Y + 4))
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


void ElephentChess::moveBack(int a, int b, board & Board)
{
	//紅
	if (identity > 7)
	{
		//左下田

		if (a <= 16 && b >= 5) {
			if (a == (coordinates.X + 4) && b == (coordinates.Y - 4))
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

		//右下田
		if (a <= 16 && b <= 13) {
			if (a == (coordinates.X + 4) && b == (coordinates.Y + 4))
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
		//左下田
		if (a <= 6 && b >= 5) {
			if (a == (coordinates.X + 4) && b == (coordinates.Y - 4))
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

		//右下田
		if (a <= 6 && b <= 13) {
			if (a == (coordinates.X + 4) && b == (coordinates.Y + 4))
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

