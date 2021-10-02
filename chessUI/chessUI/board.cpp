#include "board.h"
#include<iostream>
#include<Windows.h>

void pathRecord(int initialX, int initialY, int finalX, int finalY, int ChessNum);

board::board()
{
	noChessBoard = vector<vector<string>>(23, vector<string>(19));
	iniBoard = vector<vector<chessForm>>(23, vector<chessForm>(19));
	nowBoard = vector<vector<chessForm>>(23, vector<chessForm>(19));
	chess.resize(14);

	chess[0] = "將"; chess[1] = "士"; chess[2] = "象"; chess[3] = "車";
	chess[4] = "馬"; chess[5] = "包"; chess[6] = "卒";
	chess[7] = "帥"; chess[8] = "仕"; chess[9] = "相"; chess[10] = "車";
	chess[11] = "傌"; chess[12] = "炮"; chess[13] = "兵";

	setNoChessBoard();

	for (int i = 0; i < 23; i++) {
		for (int j = 0; j < 19; j++) {
			iniBoard[i][j].detail = nowBoard[i][j].detail = noChessBoard[i][j];
			iniBoard[i][j].colorNum = nowBoard[i][j].colorNum = 0;
			iniBoard[i][j].chessNum = nowBoard[i][j].chessNum = 0;
		}
	}
	//if is a new game
	if (isIni) {
		setIniBoard();
		nowBoard = iniBoard;
	}
	else {
		setIniBoard();
		setNowBoard();
	}

	returnTimes = 0;

}

void board::setNoChessBoard()
{
	noChessBoard[0] = { "┌ ","─ ","─ ","─ ","─ ","─ ","─ ","─ ","─ ","─ ","─ ","─ ","─ ","─ ","─ ","─ ","─ ","─ ","┐ " };
	noChessBoard[1] = { "│ ","１","  ","２","  ","３","  ","４","  ","５","  ","６","  ","７","  ","８","  ","９","│ " };
	noChessBoard[2] = { "│ ","┌ ","─ ","┬ ","─ ","┬ ","─ ","┬ ","─ ","┬ ","─ ","┬ ","─ ","┬ ","─ ","┬ ","─ ","┐ ","│ " };
	noChessBoard[3] = { "│ ","│ ","  ","│ ","  ","│ ","  ","│ ","╲ ","│ ","╱ ","│ ","  ","│ ","  ","│ ","  ","│ ","│ " };
	noChessBoard[4] = { "│ ","├ ","─ ","┼ ","─ ","┼ ","─ ","┼ ","─ ","┼ ","─ ","┼ ","─ ","┼ ","─ ","┼ ","─ ","┤ ","│ " };
	noChessBoard[5] = { "│ ","│ ","  ","│ ","  ","│ ","  ","│ ","╱ ","│ ","╲ ","│ ","  ","│ ","  ","│ ","  ","│ ","│ " };
	noChessBoard[6] = noChessBoard[4];
	noChessBoard[7] = { "│ ","│ ","  ","│ ","  ","│ ","  ","│ ","  ","│ ","  ","│ ","  ","│ ","  ","│ ","  ","│ ","│ " };
	noChessBoard[8] = noChessBoard[4]; noChessBoard[9] = noChessBoard[7];
	noChessBoard[10] = { "├ ","┴ ","─ ","┴ ","─ ","┴ ","─ ","┴ ","─ ","┴ ","─ ","┴ ","─ ","┴ ","─ ","┴ ","─ ","┴ ","┤ " };
	noChessBoard[11] = { "│ ","  ","  ","楚","河","  ","  ","  ","  ","  ","  ","  ","  ","  ","漢","界","  ","  ","│ " };
	noChessBoard[12] = { "├ ","┬ ","─ ","┬ ","─ ","┬ ","─ ","┬ ","─ ","┬ ","─ ","┬ ","─ ","┬ ","─ ","┬ ","─ ","┬ ","┤ " };
	noChessBoard[13] = noChessBoard[7]; noChessBoard[14] = noChessBoard[4];
	noChessBoard[15] = noChessBoard[7]; noChessBoard[16] = noChessBoard[4];
	noChessBoard[17] = noChessBoard[3]; noChessBoard[18] = noChessBoard[4];
	noChessBoard[19] = noChessBoard[5];
	noChessBoard[20] = { "│ ","└ ","─ ","┴ ","─ ","┴ ","─ ","┴ ","─ ","┴ ","─ ","┴ ","─ ","┴ ","─ ","┴ ","─ ","┘ ","│ " };
	noChessBoard[21] = { "│ ","九","  ","八","  ","七","  ","六","  ","五","  ","四","  ","三","  ","二","  ","一","│ " };
	noChessBoard[22] = { "└ ","─ ","─ ","─ ","─ ","─ ","─ ","─ ","─ ","─ ","─ ","─ ","─ ","─ ","─ ","─ ","─ ","─ ","┘ " };
}

void board::setIniBoard()
{
	iniBoardIn.open("iniBoard.txt");
	
	int buf[10][9];
	string in;

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 9; j++) {
			iniBoardIn >> buf[i][j];
		}
	}

	iniBoardIn >> gamerNow;

	for (int i = 1; i <= 10; i++) {
		for (int j = 0; j < 9; j++) {

			iniBoard[2 * i][2 * j + 1].chessNum = buf[i - 1][j];

			if (buf[i - 1][j] != 0) {
				iniBoard[2 * i][2 * j + 1].detail = chess[buf[i - 1][j] - 1];

				if (buf[i - 1][j] < 8) {
					iniBoard[2 * i][2 * j + 1].colorNum = 1;
				}
				else if (buf[i - 1][j] >= 8) {
					iniBoard[2 * i][2 * j + 1].colorNum = 2;
				}
			}

		}
	}
	iniBoardIn.close();
}

void board::setNowBoard()
{
	
	boardIn.open("recordBoard.txt");
	
	int buf[10][9];
	string in;

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 9; j++) {
			boardIn >> buf[i][j];
		}
	}

	boardIn >> gamerNow;

	for (int i = 1; i <= 10; i++) {
		for (int j = 0; j < 9; j++) {

			nowBoard[2 * i][2 * j + 1].chessNum = buf[i - 1][j];

			if (buf[i - 1][j] == 0) {
				nowBoard[2 * i][2 * j + 1].detail = noChessBoard[2 * i][2 * j + 1];
				nowBoard[2 * i][2 * j + 1].colorNum = 0;
			}
			else {
				nowBoard[2 * i][2 * j + 1].detail = chess[buf[i - 1][j] - 1];

				if (buf[i - 1][j] < 8) {
					nowBoard[2 * i][2 * j + 1].colorNum = 1;
				}
				else if (buf[i - 1][j] >= 8) {
					nowBoard[2 * i][2 * j + 1].colorNum = 2;
				}
			}
		}
	}
	boardIn.close();
}


void board::showBoard()
{

	if (!isIni) {
		setNowBoard();
		isIni = true;
	}


	iniPos.X = 31;
	iniPos.Y = 1;
	//定位點，需更改

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), iniPos);

	for (int i = 0; i < 23; i++) {
		for (int j = 0; j < 19; j++) {
			switch (nowBoard[i][j].colorNum) {
			case 0:
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colorB);
				break;
			case 1:
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colorBl);
				break;
			case 2:
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colorRe);
				break;
			case 3:
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colorChose);
				break;
			case 4:
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colorWalk);
				break;
			case 5:
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colorEat);
				break;
			}
			cout << nowBoard[i][j].detail;
		}
		iniPos.Y += 1;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), iniPos);
	}

	COORD posBoardIni;
	posBoardIni.X = 33;
	posBoardIni.Y = 3;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), posBoardIni);

}

void board::recoverBoard()
{
	for (int i = 1; i <= 10; i++) {
		for (int j = 0; j < 9; j++) {

			if (nowBoard[2 * i][2 * j + 1].colorNum == 3) {
				if (gamerNow == 0) {
					nowBoard[2 * i][2 * j + 1].colorNum = 1;
				}
				else {
					nowBoard[2 * i][2 * j + 1].colorNum = 2;
				}
			}
			else if (nowBoard[2 * i][2 * j + 1].colorNum == 4) {
				nowBoard[2 * i][2 * j + 1].colorNum = 0;
			}
			else if (nowBoard[2 * i][2 * j + 1].colorNum == 5) {
				if (gamerNow == 0) {
					nowBoard[2 * i][2 * j + 1].colorNum = 2;
				}
				else {
					nowBoard[2 * i][2 * j + 1].colorNum = 1;
				}
			}
		}
	}
}

void board::move(int ch)
{
	iniPos.X = 31;
	iniPos.Y = 1;
	CONSOLE_SCREEN_BUFFER_INFO pos;
	COORD posNext;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &pos);
	int xNow = pos.dwCursorPosition.X, yNow = pos.dwCursorPosition.Y;
	posNext.X = xNow; posNext.Y = yNow;
	switch (ch) {
	case 72:
		if (yNow - iniPos.Y > 2) {
			posNext.Y = yNow - 2;
		}
		break;
	case 80:
		if (yNow - iniPos.Y < 20) {
			posNext.Y = yNow + 2;
		}
		break;
	case 77:
		if (xNow - iniPos.X < 34) {
			posNext.X = xNow + 4;
		}
		break;
	case 75:
		if (xNow - iniPos.X > 2) {
			posNext.X = xNow - 4;
		}
		break;
	case 13:
		int xCheck = yNow - iniPos.Y;
		int yCheck = ((xNow - iniPos.X) / 2);
		if (nowBoard[xCheck][yCheck].colorNum == gamerNow + 1 && !enterCheck) {
			nowBoard[xCheck][yCheck].colorNum = 3;
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), posNext);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colorChose);
			cout << nowBoard[xCheck][yCheck].detail;
			enterCheck = true;
			posNow.X = xCheck;
			posNow.Y = yCheck;
			showHint(xCheck, yCheck);
			COORD uiPOS2;
			uiPOS2.X = 76;
			uiPOS2.Y = 10;
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), (uiPOS2));
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
				FOREGROUND_INTENSITY | FOREGROUND_RED |
				FOREGROUND_GREEN | FOREGROUND_BLUE);
			cout << " 現在選到的是";
			if (nowBoard[posNow.X][posNow.Y].chessNum <= 7) //黑
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
					nowBoard[posNow.X][posNow.Y].colorNum);
				cout << nowBoard[posNow.X][posNow.Y].detail;
			}
			else
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
					FOREGROUND_INTENSITY | FOREGROUND_RED);
				cout << nowBoard[posNow.X][posNow.Y].detail;
			}

			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
				FOREGROUND_INTENSITY | FOREGROUND_RED |
				FOREGROUND_GREEN | FOREGROUND_BLUE);
		}
		else if (enterCheck) {
			int color = nowBoard[xCheck][yCheck].colorNum;
			switch (color)
			{
			case 3: 
			{
				enterCheck = false;
				recoverBoard();
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), iniPos);
				showBoard();
				COORD uiPOS;
				uiPOS.X = 76;
				uiPOS.Y = 10;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
					FOREGROUND_INTENSITY | FOREGROUND_RED |
					FOREGROUND_GREEN | FOREGROUND_BLUE);
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), (uiPOS));
				cout << "                 ";
				break;
			}
			case 4:
			{
				if (returnTimes != 0) {
					int sum = record.size() - returnTimes - 1;
					record.erase(record.begin() + sum, record.end());
					returnTimes = 0;
				}

				recordForm temp;

				temp.chess = nowBoard[posNow.X][posNow.Y].chessNum;
				temp.chess2 = 0;
				temp.pos1 = posNow;

				nowBoard[xCheck][yCheck].chessNum = temp.chess;
				nowBoard[xCheck][yCheck].detail = chess[temp.chess - 1];
				nowBoard[xCheck][yCheck].colorNum = gamerNow + 1;

				nowBoard[posNow.X][posNow.Y].chessNum = 0;
				nowBoard[posNow.X][posNow.Y].detail = noChessBoard[posNow.X][posNow.Y];
				nowBoard[posNow.X][posNow.Y].colorNum = 0;

				posNow.X = xCheck;
				posNow.Y = yCheck;
				temp.pos2 = posNow;

				record.push_back(temp);

				enterCheck = false;
				recoverBoard();
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), iniPos);
				showBoard();

				COORD uiPOS;
				uiPOS.X = 74;
				uiPOS.Y = 2;

				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), (uiPOS));
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
					FOREGROUND_INTENSITY | FOREGROUND_RED |
					FOREGROUND_GREEN | FOREGROUND_BLUE);
				cout << " 現在輪到 ";
				if (gamerNow == 0)
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
						FOREGROUND_INTENSITY | FOREGROUND_RED);
					cout << " 紅色方 ";
					gamerNow = 1;
				}
				else
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
						FOREGROUND_INTENSITY | FOREGROUND_BLUE);
					cout << " 黑色方 ";
					gamerNow = 0;
				}
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
					FOREGROUND_INTENSITY | FOREGROUND_RED |
					FOREGROUND_GREEN | FOREGROUND_BLUE);
				cout << "下棋";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
					FOREGROUND_INTENSITY | FOREGROUND_RED |
					FOREGROUND_GREEN | FOREGROUND_BLUE);

				uiPOS.X = 76;
				uiPOS.Y = 10;
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), (uiPOS));
				cout << "                          ";

				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), posNow);

				if (record.size() < 21)
				{
					for (int i = 0; i < record.size(); i++)
					{
						uiPOS.X = 4;
						uiPOS.Y = 2 + i;
						SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), (uiPOS));
						cout.width(2);
						cout << i + 1;
						cout.width(1);
						if (record[i].chess <= 7)
						{
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
								FOREGROUND_INTENSITY | FOREGROUND_BLUE);
							cout << " 黑";
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
								FOREGROUND_INTENSITY | FOREGROUND_RED |
								FOREGROUND_GREEN | FOREGROUND_BLUE);

						}
						else
						{
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
								FOREGROUND_INTENSITY | FOREGROUND_RED);
							cout << " 紅";
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
								FOREGROUND_INTENSITY | FOREGROUND_RED |
								FOREGROUND_GREEN | FOREGROUND_BLUE);
						}
						cout << " :";
						pathRecord(record[i].pos1.X, record[i].pos1.Y,  record[i].pos2.X, record[i].pos2.Y, record[i].chess);
					}
				}

				checkKing();
				break;
			}
			case 5:
			{
				if (returnTimes != 0) {
					int sum = record.size() - returnTimes - 1;
					record.erase(record.begin() + sum, record.end());
					returnTimes = 0;
				}

				recordForm temp;
				temp.chess = nowBoard[posNow.X][posNow.Y].chessNum;
				temp.chess2 = nowBoard[xCheck][yCheck].chessNum;
				temp.pos1 = posNow;

				nowBoard[xCheck][yCheck].chessNum = temp.chess;
				nowBoard[xCheck][yCheck].detail = chess[temp.chess - 1];
				nowBoard[xCheck][yCheck].colorNum = gamerNow + 1;

				nowBoard[posNow.X][posNow.Y].chessNum = 0;
				nowBoard[posNow.X][posNow.Y].detail = noChessBoard[posNow.X][posNow.Y];
				nowBoard[posNow.X][posNow.Y].colorNum = 0;

				posNow.X = xCheck;
				posNow.Y = yCheck;
				temp.pos2 = posNow;
				record.push_back(temp);

				enterCheck = false;
				recoverBoard();
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), iniPos);
				showBoard();

				if (temp.chess2 == 1) {
					isWin = 1;
					break;
				}
				else if(temp.chess2 == 8)
				{
					isWin = 0;
					break;
				}

				//==============================================UI右邊=============================================
				COORD uiPOS;
				uiPOS.X = 74;
				uiPOS.Y = 2;

				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), (uiPOS));
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
					FOREGROUND_INTENSITY | FOREGROUND_RED |
					FOREGROUND_GREEN | FOREGROUND_BLUE);
				cout << " 現在輪到 ";
				if (gamerNow == 0)
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
						FOREGROUND_INTENSITY | FOREGROUND_RED);
					cout << " 紅色方 ";
					gamerNow = 1;
				}
				else
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
						FOREGROUND_INTENSITY | FOREGROUND_BLUE);
					cout << " 黑色方 ";
					gamerNow = 0;
				}
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
					FOREGROUND_INTENSITY | FOREGROUND_RED |
					FOREGROUND_GREEN | FOREGROUND_BLUE);
				cout << "下棋";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
					FOREGROUND_INTENSITY | FOREGROUND_RED |
					FOREGROUND_GREEN | FOREGROUND_BLUE);

				uiPOS.X = 76;
				uiPOS.Y = 10;
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), (uiPOS));
				cout << "                 ";

				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), posNext);

	
				checkKing();
				break;
			}
			}
		}
		break;
	}

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), posNext);

}

void board::showHint(int x, int y)
{
	int buf = nowBoard[x][y].chessNum;
	

	switch (buf) {
	case 1:
	{
		KingChess king(buf, x, y);
		king.moveColor(*this);
		break;
	}
	case 2:
	{
		GeneralChess general(buf, x, y);
		general.moveColor(*this);
		break;
	}
	case 3:
	{
		ElephentChess elephent(buf, x, y);
		elephent.moveColor(*this);
		break;
	}
	case 4:
	{
		RookChess rook(buf, x, y);
		rook.moveColor(*this);
		break;
	}
	case 5:
	{
		HorseChess horse(buf, x, y);
		horse.moveColor(*this);
		break;
	}
	case 6:
	{
		CannonChess cannon(buf, x, y);
		cannon.moveColor(*this);
		break;
	}
	case 7:
	{
		SoldierChess soldier(buf, x, y);
		soldier.moveColor(*this);
		break;
	}
	case 8:
	{
		KingChess king(buf, x, y);
		king.moveColor(*this);
		break;
	}
	case 9:
	{
		GeneralChess general(buf, x, y);
		general.moveColor(*this);
		break;
	}
	case 10:
	{
		ElephentChess elephent(buf, x, y);
		elephent.moveColor(*this);
		break;
	}
	case 11:
	{
		RookChess rook(buf, x, y);
		rook.moveColor(*this);
		break;
	}
	case 12:
	{
		HorseChess horse(buf, x, y);
		horse.moveColor(*this);
		break;
	}
	case 13:
	{
		CannonChess cannon(buf, x, y);
		cannon.moveColor(*this);
		break;
	}
	case 14:
	{
		SoldierChess soldier(buf, x, y);
		soldier.moveColor(*this);
		break;
	}
	}
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), iniPos);
	showBoard();
}

void board::checkKing()
{
	for (int i = 1; i <= 10; i++) {
		for (int j = 0; j < 9; j++) {
			if (isKing) {
				break;
			}

			if (nowBoard[2 * i][2 * j + 1].chessNum != 0) {
				int buf = nowBoard[2 * i][2 * j + 1].chessNum;
				switch (buf) {
				case 1:
				{
					KingChess king(buf, 2 * i, 2 * j + 1);
					king.Check(*this);
					break;
				}
				case 4:
				{
					RookChess rook(buf, 2 * i, 2 * j + 1);
					rook.check(*this);
					break;
				}
				case 5:
				{
					HorseChess horse(buf, 2 * i, 2 * j + 1);
					horse.check(*this);
					break;
				}
				case 6:
				{
					CannonChess cannon(buf, 2 * i, 2 * j + 1);
					cannon.check(*this);
					break;
				}
				case 7:
				{
					SoldierChess soldier(buf, 2 * i, 2 * j + 1);
					soldier.check(*this);
					break;
				}
				case 8:
				{
					KingChess king(buf, 2 * i, 2 * j + 1);
					king.Check(*this);
					break;
				}
				case 11:
				{
					RookChess rook(buf, 2 * i, 2 * j + 1);
					rook.check(*this);
					break;
				}
				case 12:
				{
					HorseChess horse(buf, 2 * i, 2 * j + 1);
					horse.check(*this);
					break;
				}
				case 13:
				{
					CannonChess cannon(buf, 2 * i, 2 * j + 1);
					cannon.check(*this);
					break;
				}
				case 14:
				{
					SoldierChess soldier(buf, 2 * i, 2 * j + 1);
					soldier.check(*this);
					break;
				}
				}
			}
			
		}
	}
}

void board::cancel()
{
	recordForm temp = record[record.size() - 1];

	nowBoard[temp.pos2.X][temp.pos2.Y].chessNum = temp.chess2;
	if (temp.chess2 == 0) {
		nowBoard[temp.pos2.X][temp.pos2.Y].detail = noChessBoard[temp.pos2.X][temp.pos2.Y];
	}
	else {
		nowBoard[temp.pos2.X][temp.pos2.Y].detail = chess[temp.chess2 - 1];
	}
	nowBoard[temp.pos2.X][temp.pos2.Y].colorNum = gamerNow + 1;

	if (gamerNow == 0) gamerNow = 1;
	else gamerNow = 0;

	nowBoard[temp.pos1.X][temp.pos1.Y].chessNum = temp.chess;
	nowBoard[temp.pos1.X][temp.pos1.Y].detail = chess[temp.chess - 1];
	nowBoard[temp.pos1.X][temp.pos1.Y].colorNum = gamerNow + 1;

	enterCheck = false;
	isKing = false;
	record.pop_back();

	recoverBoard();
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), iniPos);
	showBoard();
	
}


int board::getGamerNow()
{
	return gamerNow;
}

int board::getisWin()
{
	return isWin;
}

void board::newGame()
{
	record.clear();
	nowBoard = iniBoard;
	enterCheck = false;
	isWin = false;
	isKing = false;
	gamerNow = 1;
}

void board::regret()
{
	iniPos.X = 31;
	iniPos.Y = 1;
		if (record.size() - returnTimes >= 2) {
			for (int i = 0; i < 2; i++) {
				recordForm re = record[record.size() - 1 - returnTimes]; //for回復

				if (re.chess2 != 0) {
					string buf = chess[re.chess2 - 1];
					nowBoard[re.pos2.X][re.pos2.Y].chessNum = re.chess2;
					nowBoard[re.pos2.X][re.pos2.Y].detail = buf;

					if (re.chess2 < 8) {
						nowBoard[re.pos2.X][re.pos2.Y].colorNum = 1;
					}
					else {
						nowBoard[re.pos2.X][re.pos2.Y].colorNum = 2;
					}

				}
				else {
					nowBoard[re.pos2.X][re.pos2.Y].chessNum = 0;
					nowBoard[re.pos2.X][re.pos2.Y].detail = noChessBoard[re.pos2.X][re.pos2.Y];
					nowBoard[re.pos2.X][re.pos2.Y].colorNum = 0;
				}

				posNow = re.pos1;

				string buf = chess[re.chess - 1];
				nowBoard[re.pos1.X][re.pos1.Y].chessNum = re.chess;
				nowBoard[re.pos1.X][re.pos1.Y].detail = buf;

				if (re.chess < 8) {
					nowBoard[re.pos1.X][re.pos1.Y].colorNum = 1;
					gamerNow = 0;
				}
				else {
					nowBoard[re.pos1.X][re.pos1.Y].colorNum = 2;
					gamerNow = 1;
				}

				showBoard();
				returnTimes++;
			}
		
	}
}

void board::recover()
{
	iniPos.X = 31;
	iniPos.Y = 1;

	if (returnTimes != 0) {
		for (int i = 0; i < 2; i++) {
			recordForm re = record[record.size() - returnTimes]; //for回復

			nowBoard[re.pos2.X][re.pos2.Y].chessNum = re.chess;
			nowBoard[re.pos2.X][re.pos2.Y].detail = chess[re.chess - 1];
			nowBoard[re.pos2.X][re.pos2.Y].colorNum = gamerNow + 1;

			nowBoard[re.pos1.X][re.pos1.Y].chessNum = 0;
			nowBoard[re.pos1.X][re.pos1.Y].detail = noChessBoard[re.pos1.X][re.pos1.Y];
			nowBoard[re.pos1.X][re.pos1.Y].colorNum = 0;

			posNow = re.pos2;

			if (gamerNow == 0) gamerNow = 1;
			else gamerNow = 0;

			showBoard();
			returnTimes--;
		}
	}
}


void pathRecord(int initialX, int initialY, int finalX, int finalY, int ChessNum) {

	//第一個字
	switch (ChessNum) {
	case 1:
		cout << "將";
		break;
	case 2:
		cout << "士";
		break;
	case 3:
		cout << "象";
		break;
	case 4:
		cout << "馬";
		break;
	case 5:
		cout << "車";
		break;
	case 6:
		cout << "包";
		break;
	case 7:
		cout << "卒";
		break;
	case 8:
		cout << "帥";
		break;
	case 9:
		cout << "仕";
		break;
	case 10:
		cout << "相";
		break;
	case 11:
		cout << "傌";
		break;
	case 12:
		cout << "俥";
		break;
	case 13:
		cout << "炮";
		break;
	case 14:
		cout << "兵";
		break;
	}

	//第二個字
	if (ChessNum <= 7) {
		switch (initialY) {
		case 1:
			cout << "１";
			break;
		case 3:
			cout << "２";
			break;
		case 5:
			cout << "３";
			break;
		case 7:
			cout << "４";
			break;
		case 9:
			cout << "５";
			break;
		case 11:
			cout << "６";
			break;
		case 13:
			cout << "７";
			break;
		case 15:
			cout << "８";
			break;
		case 17:
			cout << "９";
			break;
		}
	}
	else {
		switch (initialY) {
		case 17:
			cout << "一";
			break;
		case 15:
			cout << "二";
			break;
		case 13:
			cout << "三";
			break;
		case 11:
			cout << "四";
			break;
		case 9:
			cout << "五";
			break;
		case 7:
			cout << "六";
			break;
		case 5:
			cout << "七";
			break;
		case 3:
			cout << "八";
			break;
		case 1:
			cout << "九";
			break;
		}
	}

	//第三個字
	//水平移動是平
	if (initialX == finalX) {
		cout << "平";
	}
	else {
		//黑棋向上是退，向下是進
		if (ChessNum <= 7) {
			if (initialX < finalX) {
				cout << "進";
			}
			else if (initialX > finalX) {
				cout << "退";
			}
		}
		//紅棋向上是進，向下是退
		else {
			if (initialX > finalX) {
				cout << "進";
			}
			else if (initialX < finalX) {
				cout << "退";
			}
		}
	}

	//第四個字
	//垂直移動是步數
	if (initialY == finalY) {

		int step = abs(finalX - initialX);

		if (ChessNum <= 7) {
			switch (step) {
			case 2:
				cout << "１";
				break;
			case 4:
				cout << "２";
				break;
			case 6:
				cout << "３";
				break;
			case 8:
				cout << "４";
				break;
			case 10:
				cout << "５";
				break;
			case 12:
				cout << "６";
				break;
			case 14:
				cout << "７";
				break;
			case 16:
				cout << "８";
				break;
			case 18:
				cout << "９";
				break;
			}
		}
		else {
			switch (step) {
			case 2:
				cout << "一";
				break;
			case 4:
				cout << "二";
				break;
			case 6:
				cout << "三";
				break;
			case 8:
				cout << "四";
				break;
			case 10:
				cout << "五";
				break;
			case 12:
				cout << "六";
				break;
			case 14:
				cout << "七";
				break;
			case 16:
				cout << "八";
				break;
			case 18:
				cout << "九";
				break;
			}
		}
	}
	//水平移動是棋盤編號
	else {

		if (ChessNum <= 7) {
			switch (finalY) {
			case 1:
				cout << "１";
				break;
			case 3:
				cout << "２";
				break;
			case 5:
				cout << "３";
				break;
			case 7:
				cout << "４";
				break;
			case 9:
				cout << "５";
				break;
			case 11:
				cout << "６";
				break;
			case 13:
				cout << "７";
				break;
			case 15:
				cout << "８";
				break;
			case 17:
				cout << "９";
				break;
			}
		}
		else {
			switch (finalY) {
			case 17:
				cout << "一";
				break;
			case 15:
				cout << "二";
				break;
			case 13:
				cout << "三";
				break;
			case 11:
				cout << "四";
				break;
			case 9:
				cout << "五";
				break;
			case 7:
				cout << "六";
				break;
			case 5:
				cout << "七";
				break;
			case 3:
				cout << "八";
				break;
			case 1:
				cout << "九";
				break;
			}
		}
	}

}
