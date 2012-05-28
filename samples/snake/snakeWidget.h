/*
 * snakeWidget.h
 *
 *  Created on: 2010-10-28
 *      Author: ��׿
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

#define WIDGET_W 240	//���ڿ��
#define WIDGET_H 320	//���ڸ߶�
#define TIME 100		//֡��10Hz

#define SNAKE_2 0		//�������Ϊ1,���������ߣ��������Ϊ0��Ϊһ����

#define CHANGE2_1 1		//��2����ʳ�ﵽ1
#define CHANGE1_2 2		//��1����ʳ�ﵽ2

#include <iostream>
using namespace std;

class snakeWidget : public ZWidget
{
	Q_OBJECT
	public:
		snakeWidget();
		~snakeWidget();
		virtual void keyPressEvent(QKeyEvent *e);//�Ӹ���дQWidget�ļ����¼�
		virtual void timerEvent(QTimerEvent *e);//time
		virtual void paintEvent(QPaintEvent *e);
	private:
		//QLabel *lab;//������ʾ��ϷͼƬ�Ĳ���
		QPixmap pix;//��ϷͼƬ���ݴ�
		QTimer *timer;//��ʱ���������̶�֡��
		snake *mysnake;//��1ʵ��
	  #if SNAKE_2
		snake *mysnake2;//��2ʵ��
	  #endif
		int width_map;//��Ϸ����
		int height_map;//��Ϸ�����
	private:
		void initial();//��ʼ��
		void freshScreen();//ˢ����Ļ
		void calcFood(int flag);//�������ߵ�ʳ����ͬһ��
	public slots:
		void updateFrame(int num=0);//ȡ����һ֡ͼ��
};


#endif /* SNAKEWIDGET_H_ */

