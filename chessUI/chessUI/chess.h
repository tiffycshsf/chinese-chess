#pragma once
#include<iostream>	
#include<windows.h>
using namespace std;

class chess //baseClass
{
public:
	//void virtual moveColor();
	//void virtual moveUp(int ,int); //�i
	//void virtual moveHorizon(int,int);//��
	//void virtual moveBack(int,int);//�h
	chess(int, int, int);//�s�� �y��x,y
	virtual ~chess(); //�Y�X�ɧ��exist = 0
private:
	COORD coordinates;
	int identity;//�X�l�s��
	int exist = 1;//�s�b�ѽL��

};
