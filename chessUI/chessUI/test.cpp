#include"board.h"
#include <conio.h>
#include<windows.h>
#include <iostream>
#include <fstream>
#include<string>
#include<vector>
#include "EConsole.h"
using namespace std;



int state = 0; //menu=0 main =1 option=2 template(regret)=3 template(restore)=4 victory = 5
void loadUI(string state); //menu main board option regret restore
void menuCtr(int ctr);
void optionCtr(int ctr);
void templateCtr(int ctr);
void action(); //戰況顯示 選棋判斷 誰走棋
void initParameter(); //for new game
vector<recordForm>* point;
board game;

int test = 0;
int team = game.getGamerNow();






int main()
{
	//設置標題
	char title[6] = "chess";
	_SetConsoleTitle(title);
	_GetConsoleTitle(title, 6);

	//變數
	char key;
	int menuopt = 0;
	int optionopt = 0;
	int templateopt = 0;


	//起始畫面
	loadUI("menu");

	while (key = _getch()) //讀取
	{
		//state0 =============================================
		if (state == 0)
		{
			if (key == 72) //key up code
			{
				if (menuopt != 0 && menuopt <= 2)
				{
					menuopt--;
				}
			}
			else if (key == 80) //key down code
			{
				if (menuopt != 2 && menuopt >= 0)
				{
					menuopt++;
				}
			}
			menuCtr(menuopt);
			if (key == 13) //切換狀態機
			{
				if (menuopt == 0) //開新遊戲
				{
					initParameter();
					game.newGame();
					loadUI("main");
					loadUI("board");
					state = 1;
				}
				else if (menuopt == 1)//繼續遊戲
				{
					game.isIni = false;
					loadUI("main");
					loadUI("board");
					state = 1;
				}
				else if (menuopt == 2)//離開遊戲
				{
					exit(0);
				}

				menuopt = 0;
			}
		}
		//state1 =============================================
		else if (state == 1)
		{
			if (key == 27) //exc
			{
				state = 2;
				loadUI("option");
				optionCtr(0);
			}
			else if (key == 44)
			{
				state = 3;
				loadUI("regret");
				//action();
			}
			else if (key == 46)
			{
				state = 4;
				loadUI("restore");
			}
			else
			{
				game.move(key);
				
				if (game.getisWin() == 1)
				{
					if (game.getGamerNow() == 0) {
						SetColor(0);
						Clr();
						loadUI("blackVictory");
						state = 5;
					}
					else {
						SetColor(0);
						Clr();
						loadUI("redVictory");
						state = 5;
					}
				}
			}
		}
		//state2 =============================================
		else if (state == 2)
		{
			if (key == 72) //key up code
			{
				if (optionopt != 0 && optionopt <= 3)
				{
					optionopt--;
				}
			}
			else if (key == 80) //key down code
			{
				if (optionopt != 3 && optionopt >= 0)
				{
					optionopt++;
				}
			}
			optionCtr(optionopt);
			if (key == 13) //切換狀態機
			{
				if (optionopt == 0) //繼續遊戲
				{
					game.isIni = false;
					loadUI("board"); //把棋盤刷新就好
					state = 1;
				}
				else if (optionopt == 1)//重新開始
				{
					initParameter();
					game.newGame();
					loadUI("main");
					loadUI("board");
					state = 1;
				}
				else if (optionopt == 2)//回主選單
				{
					Clr();
					loadUI("menu");
					state = 0;
				}
				else if (optionopt == 3)//離開遊戲
				{
					exit(0);
				}

				optionopt = 0;
			}
		}
		//state3 =============================================
		else if (state == 3)
		{
			if (key == 75) //key up code
			{
				if (templateopt != 0 && templateopt <= 1)
				{
					templateopt--;
				}
			}
			else if (key == 77) //key down code
			{
				if (templateopt != 2 && templateopt >= 0)
				{
					templateopt++;
				}
			}
			templateCtr(templateopt);
			if (key == 13) //切換狀態機
			{
				if (templateopt == 0) //確定
				{
					game.regret();
					loadUI("board");
					state = 1;
				}
				else if (templateopt == 1) //取消
				{
					loadUI("board");
					state = 1;
				}

				templateopt = 0;
			}
		}
		//state4 =============================================
		else if (state == 4)
		{
			if (key == 75) //key up code
			{
				if (templateopt != 0 && templateopt <= 1)
				{
					templateopt--;
				}
			}
			else if (key == 77) //key down code
			{
				if (templateopt != 2 && templateopt >= 0)
				{
					templateopt++;
				}
			}
			templateCtr(templateopt);
			if (key == 13) //切換狀態機
			{
				if (templateopt == 0) //確定
				{
					game.recover(); 
					loadUI("board");
					state = 1;
				}
				else if (templateopt == 1) //取消
				{
					loadUI("board");
					state = 1;
				}

				templateopt = 0;
			}
		}
		else if (state == 5)
		{
			if (key == 13) //切換狀態機
			{
				exit(0);
			}
		}
	}
}

void loadUI(string state) //menu main board option regret restore
{
	wfstream UI;
	wstring sy;
	int line = 0;
	if (state == "menu")
	{
		SetColor(0);
		UI.open("menu.txt");
		while (getline(UI, sy))
		{
			gotoxy(44, 6 + line);
			wcout << sy << endl;
			line++;
		}
		UI.close();
		gotoxy(49, 8);
		SetColor(8);
		wcout << "開新遊戲";
		SetColor(0);
	}
	else if (state == "main")
	{
		SetColor(0);
		gotoxy(0, 0);
		UI.open("UI.txt");
		while (getline(UI, sy))
		{
			wcout << sy << endl;
		}
		UI.close();
		gotoxy(74, 2);
		SetColor(0);

		cout << " 現在輪到 ";
		if (team == 0)
		{
			SetColor(4);
			cout << " 黑色方 ";
		}
		else if (team == 1)
		{
			SetColor(1);
			cout << " 紅色方 ";
		}
		SetColor(0);
		cout << "下棋";
	}
	else if (state == "board")
	{
		game.showBoard();
		SetColor(0);
	}
	else if (state == "option")
	{
		SetColor(0);
		UI.open("option.txt");
		while (getline(UI, sy))
		{
			cout.width(2);
			gotoxy(40, 3 + line);
			wcout << sy << endl;
			line++;
		}
		UI.close();
	}
	else if (state == "regret")
	{
		UI.open("template.txt");
		while (getline(UI, sy))
		{
			gotoxy(32, 6 + line);
			wcout << sy << endl;
			line++;
		}
		UI.close();

		gotoxy(49, 10); //
		SetColor(1);
		wcout << "悔棋";
		SetColor(0);

		gotoxy(38, 16);
		SetColor(8);
		wcout << "確定";
		SetColor(0);
	}
	else if (state == "restore")
	{
		UI.open("template.txt");
		while (getline(UI, sy))
		{
			gotoxy(32, 6 + line);
			wcout << sy << endl;
			line++;
		}
		UI.close();

		gotoxy(49, 10); //
		SetColor(1);
		wcout << "復原";
		SetColor(0);

		gotoxy(38, 16);
		SetColor(8);
		wcout << "確定";
		SetColor(0);
	}
	else if (state == "redVictory")
	{
	UI.open("victory.txt");
	while (getline(UI, sy))
	{
		gotoxy(32, 6 + line);
		wcout << sy << endl;
		line++;
	}
	UI.close();

	gotoxy(43, 10); //
	SetColor(1);
	wcout << "紅";
	SetColor(8);
	gotoxy(44, 16);
	wcout << "離開遊戲";
	}
	else if (state == "blackVictory")
	{
	UI.open("victory.txt");
	while (getline(UI, sy))
	{
		gotoxy(32, 6 + line);
		wcout << sy << endl;
		line++;
	}
	UI.close();

	gotoxy(43, 10); //
	SetColor(4);
	wcout << "黑";
	SetColor(8);
	gotoxy(44, 16);
	wcout << "離開遊戲";
	gotoxy(0, 0);
	}
}
void menuCtr(int ctr)
{
	switch (ctr)
	{
	case 0:
		gotoxy(49, 8);
		SetColor(8);
		wcout << "開新遊戲";
		gotoxy(49, 12);
		SetColor(0);
		wcout << "繼續遊戲";
		gotoxy(49, 16);
		SetColor(0);
		wcout << "離開遊戲";
		SetColor(0);
		break;
	case 1:
		gotoxy(49, 8);
		SetColor(0);
		wcout << "開新遊戲";
		gotoxy(49, 12);
		SetColor(8);
		wcout << "繼續遊戲";
		gotoxy(49, 16);
		SetColor(0);
		wcout << "離開遊戲";
		SetColor(0);
		break;
	case 2:
		gotoxy(49, 8);
		SetColor(0);
		wcout << "開新遊戲";
		gotoxy(49, 12);
		SetColor(0);
		wcout << "繼續遊戲";
		gotoxy(49, 16);
		SetColor(8);
		wcout << "離開遊戲";
		SetColor(0);
		break;
	}
}
void optionCtr(int ctr)
{
	switch (ctr)
	{
	case 0:
		gotoxy(44, 5);
		SetColor(8);
		wcout << "繼續遊戲";
		gotoxy(44, 9);
		SetColor(0);
		wcout << "重新開始";
		gotoxy(44, 13);
		SetColor(0);
		wcout << "回主選單";
		gotoxy(44, 17);
		SetColor(0);
		wcout << "離開遊戲";
		SetColor(0);
		break;
	case 1:
		gotoxy(44, 5);
		SetColor(0);
		wcout << "繼續遊戲";
		gotoxy(44, 9);
		SetColor(8);
		wcout << "重新開始";
		gotoxy(44, 13);
		SetColor(0);
		wcout << "回主選單";
		gotoxy(44, 17);
		SetColor(0);
		wcout << "離開遊戲";
		SetColor(0);
		break;
	case 2:
		gotoxy(44, 5);
		SetColor(0);
		wcout << "繼續遊戲";
		gotoxy(44, 9);
		SetColor(0);
		wcout << "重新開始";
		gotoxy(44, 13);
		SetColor(8);
		wcout << "回主選單";
		gotoxy(44, 17);
		SetColor(0);
		wcout << "離開遊戲";
		SetColor(0);
		break;
	case 3:
		gotoxy(44, 5);
		SetColor(0);
		wcout << "繼續遊戲";
		gotoxy(44, 9);
		SetColor(0);
		wcout << "重新開始";
		gotoxy(44, 13);
		SetColor(0);
		wcout << "回主選單";
		gotoxy(44, 17);
		SetColor(8);
		wcout << "離開遊戲";
		SetColor(0);
		break;
	default:
		break;
	}
}
void templateCtr(int ctr)
{
	switch (ctr)
	{
	case 0: //確定
		gotoxy(38, 16);
		SetColor(8);
		wcout << "確定";
		gotoxy(57, 16);
		SetColor(0);
		wcout << "取消";
		SetColor(0);
		break;
	case 1: //取消
		gotoxy(38, 16);
		SetColor(0);
		wcout << "確定";
		gotoxy(57, 16);
		SetColor(8);
		wcout << "取消";
		SetColor(0);
		break;
	default:
		break;
	}
}


void initParameter()
{
	state = 0;
	team = game.getGamerNow();
}

