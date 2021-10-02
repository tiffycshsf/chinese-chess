#ifndef board_h
#define board_h

#include<vector>
#include<string>
#include<Windows.h>
#include<conio.h>
#include<fstream>

#include"CannonChess.h"
#include"ElephentChess.h"
#include"GeneralChess.h"
#include"HorseChess.h"
#include"KingChess.h"
#include"RookChess.h"
#include"SoldierChess.h"



using namespace std;

struct recordForm {
	int chess;
	COORD pos1;
	COORD pos2;
	int chess2;		
	//被吃
};

struct chessForm {
	short chessNum;
	string detail;
	int colorNum;
};

class board {

public:

	friend class CannonChess;
	friend class ElephentChess;
	friend class GeneralChess;
	friend class HorseChess;
	friend class KingChess;
	friend class RookChess;
	friend class SoldierChess;

	board();
	void setNoChessBoard();
	void setIniBoard();
	void setNowBoard();
	void newGame();

	bool isIni = true;
	void showBoard();
	void recoverBoard();

	void move(int ch); //int _getch
	
	void showHint(int x, int y);
	void checkKing();
	void cancel();
	void recover();
	void regret();
	int getGamerNow();
	int getisWin();

private:
	
	vector<vector<string>> noChessBoard;
	vector<vector<chessForm>> iniBoard;
	vector<vector<chessForm>> nowBoard;
	vector<recordForm> record;
	vector<string> chess;

	ifstream boardIn; 
	ifstream iniBoardIn;
	int gamerNow;	//0 = B, 1 = R
	bool enterCheck;

	bool isKing;
	COORD posNow; //for enterCheck
	COORD iniPos;//定位點

	int returnTimes;//修正

	int isWin = 2; //0黑贏 1紅贏 2未分勝負
	int colorB = 240; //0
	int colorBl = 112; //1
	int colorRe = 116; //2
	int colorChose = 63; //3
	int colorWalk = 31;//4
	int colorEat = 95;//5
	
};

#endif // !board_h

