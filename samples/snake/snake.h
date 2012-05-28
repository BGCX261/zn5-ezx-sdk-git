/*
 * snake.h
 *
 *  Created on: 2010-10-28
 *      Author: 付卓
 */

#ifndef SNAKE_H_
#define SNAKE_H_


#include <iostream>
#include <cmath>
#include <ctime>

using namespace std;

#define WALL -1		//墙
#define NOTHING -2	//空白
#define FOOD 0		//食物

#define WIDTH 24	//横向点阵数
#define HEIGHT 32	//纵向点阵数

struct coordinate{
	int x;
	int y;
};
struct Body{
	coordinate cord;
	struct Body *next;
};
class snake
{
	public:
		snake(int x,int y);
		~snake();
		void createBody(int x,int y);//产生蛇体
		void getFood();//蛇听得到食物时动作
		bool setFood(int x,int y);//强制设定食物位置
		void clearFood();//清楚食物（只是在画图上）
		bool createFood();//产生食物
		void resetFood();//重置食物
	public:
		int MAP[HEIGHT+2][WIDTH+2];//地图及蛇体数据:-2为空 -1为墙 0为food 1及以后为Body各段编号 四周加了一圈虚拟的墙
	public:
		enum director{UP,DOWN,LEFT,RIGHT}direct;//蛇的移动方向
		int length,ori_x,ori_y;//蛇的长度，及蛇头的默认坐标
		int width_map,height_map;//点阵的长宽数
		int score;//游戏得分
		coordinate head,trail;//头、尾的坐标值
		coordinate snakeFood;//食物的坐标值
		bool gameOver;//游戏结束标志
	public:
		void moveStep();//产生下一帧数据
		void gameReset();//游戏复位
		int moveUp();//移动函数
		int moveDown();
		int moveLeft();
		int moveRight();
		void gotoXY(int x,int y);
    private:
		bool createFood_lock;
};

#endif /* SNAKE_H_ */
