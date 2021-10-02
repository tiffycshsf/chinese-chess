#pragma once
#include<iostream>	
#include<windows.h>
using namespace std;

class chess //baseClass
{
public:
	//void virtual moveColor();
	//void virtual moveUp(int ,int); //進
	//void virtual moveHorizon(int,int);//平
	//void virtual moveBack(int,int);//退
	chess(int, int, int);//編號 座標x,y
	virtual ~chess(); //吃旗時更改exist = 0
private:
	COORD coordinates;
	int identity;//旗子編號
	int exist = 1;//存在棋盤中

};
