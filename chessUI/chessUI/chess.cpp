#include "chess.h"


chess::~chess()
{
	exist = 0;//物件消失
}

chess::chess(int a,int b,int c )
{
	identity = a;
	coordinates.X = b;
	coordinates.Y = c;
	exist = 1;
}