/*
 * snakeWidget.h
 *
 *  Created on: 2010-10-28
 *      Author: 付卓
 */

#ifndef SNAKEWIDGET_H_
#define SNAKEWIDGET_H_

#include "snake.h"

#include <ZWidget.h>
#include <qwidget.h>
#include <qpainter.h>
#include <qpixmap.h>
#include <qlabel.h>
#include <qtimer.h>
#include <qevent.h>
#include <qcolor.h>

#define WIDGET_W 240	//窗口宽度
#define WIDGET_H 320	//窗口高度
#define TIME 100		//帧速10Hz

#define SNAKE_2 0		//如果定义为1,则有两条蛇，如果定义为0则为一条蛇

#define CHANGE2_1 1		//从2拷贝食物到1
#define CHANGE1_2 2		//从1拷贝食物到2

#include <iostream>
using namespace std;

class snakeWidget : public ZWidget
{
	Q_OBJECT
	public:
		snakeWidget();
		~snakeWidget();
		virtual void keyPressEvent(QKeyEvent *e);//从覆盖写QWidget的键盘事件
		virtual void timerEvent(QTimerEvent *e);//time
		virtual void paintEvent(QPaintEvent *e);
	private:
		//QLabel *lab;//用以显示游戏图片的部件
		QPixmap pix;//游戏图片的暂存
		QTimer *timer;//定时器，产生固定帧速
		snake *mysnake;//蛇1实例
	  #if SNAKE_2
		snake *mysnake2;//蛇2实例
	  #endif
		int width_map;//游戏点阵长
		int height_map;//游戏点阵宽
	private:
		void initial();//初始化
		void freshScreen();//刷新屏幕
		void calcFood(int flag);//将两条蛇的食物变成同一个
	public slots:
		void updateFrame(int num=0);//取得下一帧图形
};


#endif /* SNAKEWIDGET_H_ */

