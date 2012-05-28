/*
 * snake.cpp
 *
 *  Created on: 2010-10-28
 *      Author: 付卓
 */

#include "snake.h"
#include <stdio.h>

snake::snake(int x,int y)
{
	direct=RIGHT;ori_x=x;ori_y=y;
	width_map=WIDTH;
	height_map=HEIGHT;
	createBody(x,y);
	score=0;
	gameOver=false;
	createFood_lock = false;
}
snake::~snake()
{

}
void snake::moveStep()
{
    if(createFood_lock == true) {
			cout<<"creating food"<<endl;
			return;
	}
	switch(direct)
	{
		case UP:
			if(MAP[head.x-1][head.y]==NOTHING)
			{
				gotoXY(head.x-1,head.y);
			}
			else if(MAP[head.x-1][head.y]==FOOD) getFood();
			else gameOver=true;
			break;
		case DOWN:
			if(MAP[head.x+1][head.y]==NOTHING)
			{
				gotoXY(head.x+1,head.y);
			}
			else if(MAP[head.x+1][head.y]==FOOD) getFood();
			else gameOver=true;
			break;
		case LEFT:
			if(MAP[head.x][head.y-1]==NOTHING)
			{
				gotoXY(head.x,head.y-1);
			}
			else if(MAP[head.x][head.y-1]==FOOD) getFood();
			else gameOver=true;
			break;
		case RIGHT:
			if(MAP[head.x][head.y+1]==NOTHING)
			{
				gotoXY(head.x,head.y+1);
			}
			else if(MAP[head.x][head.y+1]==FOOD) getFood();
			else gameOver=true;
			break;

		default:break;
	}
}
void snake::gotoXY(int x,int y)//移动函数，每次只一步！！
{
	MAP[x][y]=1;head.x=x;head.y=y;//新建头点
	MAP[trail.x][trail.y]=NOTHING;//清除尾点
	bool flag_trail=false;
	for(int i=1;i<=HEIGHT;i++)
		for(int j=1;j<=WIDTH;j++)
		{
			if(MAP[i][j]==length-1 && flag_trail==false)//得到尾
			{
				trail.x=i;trail.y=j;flag_trail=true;
			}
			if( MAP[i][j]>0 && !(i==x && j==y) )
			{
				MAP[i][j]+=1;//除了新的头点所有点编号加1
			}
		}
}
void snake::getFood()
{
	cout<<"yes i get one!"<<endl;
	score++;
	MAP[snakeFood.x][snakeFood.y]=1;head.x=snakeFood.x;head.y=snakeFood.y;//fresh头点
	length++;//增加长度
	for(int i=1;i<=HEIGHT;i++)
		for(int j=1;j<=WIDTH;j++)
		{
			if( MAP[i][j]>0 && !(i==snakeFood.x && j==snakeFood.y) )
			{
				MAP[i][j]+=1;//除了新的头点所有点编号加1
			}
		}
	while(createFood());
}
int snake::moveUp()
{
	if(MAP[head.x-1][head.y]==NOTHING || MAP[head.x-1][head.y]==FOOD) {direct=UP;return 1;}
	else if(direct==DOWN) return 0;
	else {gameOver=true;return 0;}
}
int snake::moveDown()
{
	if(MAP[head.x+1][head.y]==NOTHING || MAP[head.x+1][head.y]==FOOD) {direct=DOWN;return 1;}
	else if(direct==UP) return 0;
	else {gameOver=true;return 0;}
}
int snake::moveLeft()
{
	if(MAP[head.x][head.y-1]==NOTHING || MAP[head.x][head.y-1]==FOOD) {direct=LEFT;return 1;}
	else if(direct==RIGHT) return 0;
	else {gameOver=true;return 0;}
}
int snake::moveRight()
{
	if(MAP[head.x][head.y+1]==NOTHING || MAP[head.x][head.y+1]==FOOD) {direct=RIGHT;return 1;}
	else if(direct==LEFT) return 0;
	else {gameOver=true;return 0;}
}
void snake::createBody(int x,int y)
{
	for(int i=0;i<=HEIGHT+1;i++)
		for(int j=0;j<=WIDTH+1;j++)
		{
			if(i==0||j==0||i==HEIGHT+1||j==WIDTH+1) MAP[i][j]=WALL;
			else MAP[i][j]=NOTHING;
		}
	for(int j=y;j>=1;j--) MAP[x][j]=y-j+1;
	length=y;
	head.x=x;head.y=y;
	trail.x=x;trail.y=1;
	while(createFood());
}
bool snake::createFood()
{
    //createFood_lock=true;
	srand(time(NULL));
	snakeFood.x=rand()%(HEIGHT)+1;
	snakeFood.y=rand()%(WIDTH)+1;
	if(MAP[snakeFood.x][snakeFood.y]==NOTHING) {
		MAP[snakeFood.x][snakeFood.y]=FOOD;
		printf("create snake food(%d, %d)\n", snakeFood.x, snakeFood.y); 
		createFood_lock=false;
		return true;
	}
	else return false;
}
bool snake::setFood(int x,int y)
{
	clearFood();
	if(MAP[x][y]==NOTHING) {MAP[x][y]=FOOD;snakeFood.x=x;snakeFood.y=y;return true;}
	else return false;
}
void snake::clearFood()
{
	for(int i=1;i<=HEIGHT;i++)
		for(int j=1;j<=WIDTH;j++)
		{
			if(MAP[i][j]==FOOD) MAP[i][j]=NOTHING;
		}
}
void snake::resetFood()
{
	clearFood();
	while(createFood());
}
void snake::gameReset()
{
	cout<<"gameReset!"<<endl;
	gameOver=false;
	direct=RIGHT;
	createBody(ori_x,ori_y);
	score=0;
}
