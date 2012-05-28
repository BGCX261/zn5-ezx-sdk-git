/*
 * snakeWidget.cpp
 *
 *  Created on: 2010-10-28
 *      Author: ¸¶×¿
 */

#include <qapplication.h>
#include "snakeWidget.h"

snakeWidget::snakeWidget():ZWidget(NULL, NULL, 0, (ZSkinService::WidgetClsID)0)
{
	this->setGeometry(0,0,WIDGET_W,WIDGET_H);
	//lab=new QLabel(this);
	pix=QPixmap(WIDGET_W,WIDGET_H);
	pix.fill(Qt::green);
	//lab->setPixmap(pix);
	//lab->setGeometry(0, 0, WIDGET_W, WIDGET_H);


	mysnake=new snake(1,3);

	calcFood(CHANGE2_1);
	width_map=mysnake->width_map;
	height_map=mysnake->height_map;

	freshScreen();
	cout<<"start timer"<<endl;
	timer=new QTimer(this);
	QObject::connect(timer,SIGNAL(timeout()),this,SLOT(updateFrame()));
	timer->start(TIME);
	//fuzhuo add 
	startTimer(150);
}

snakeWidget::~snakeWidget()
{
	delete mysnake;
}

void snakeWidget::paintEvent(QPaintEvent *e)
{
	QPainter *p=new QPainter(&pix);

		if(mysnake->gameOver)
		{
			p->setPen(Qt::red);p->setBrush(Qt::red);
			p->drawRect(0,0,WIDGET_W,WIDGET_H);
			p->setPen(Qt::white);
			p->drawText(0,20,QString("GameOver!\n score is:%1\n").arg(mysnake->score));
			delete p;
			//lab->setPixmap(pix);
			killTimers();
			bitBlt(this, QPoint(0,0), &pix);
			return;
		}

		p->setPen(Qt::white);
		p->setBrush(Qt::white);
		p->drawRect(0,0,WIDGET_W,WIDGET_H); //»­±³¾°

		for(int i=1;i<=height_map;i++)
			for(int j=1;j<=width_map;j++)
			{
				if(mysnake->MAP[i][j]==1)
				{
					p->setPen(Qt::red);p->setBrush(Qt::green);
					p->drawRect((j-1)*WIDGET_W/width_map,(i-1)*WIDGET_H/height_map,WIDGET_W/width_map,WIDGET_H/height_map);
				}
				else if(mysnake->MAP[i][j]>1)
				{
					p->setPen(Qt::blue);
					p->setBrush(QColor(255,255,0));
					p->drawRect((j-1)*WIDGET_W/width_map,(i-1)*WIDGET_H/height_map,WIDGET_W/width_map,WIDGET_H/height_map);
				}
				if(mysnake->MAP[i][j]==FOOD)
				{
					p->setPen(Qt::white);
					p->setBrush(Qt::red);
					p->drawRect((j-1)*WIDGET_W/width_map,(i-1)*WIDGET_H/height_map,WIDGET_W/width_map,WIDGET_H/height_map);
				}
			}

			p->setPen(Qt::green);
			p->drawText(0,20,QString("score: %1").arg(mysnake->score));
	delete p;
	//lab->setPixmap(pix);
	bitBlt(this, QPoint(0,0), &pix);
}
void snakeWidget::freshScreen()
{
	this->update();
	return;
	/*
	QPainter *p=new QPainter(&pix);

		if(mysnake->gameOver)
		{
			p->setPen(Qt::red);p->setBrush(Qt::red);
			p->drawRect(0,0,WIDGET_W,WIDGET_H);
			p->setPen(Qt::white);
			p->drawText(WIDGET_W/2-30,WIDGET_H/2-10,QString("GameOver! \n your score is:%1\nplease press SPACE KEY to restart game").arg(mysnake->score));
			delete p;
			lab->setPixmap(pix);
			return;
		}

		p->setPen(Qt::blue);
		p->setBrush(Qt::blue);
		p->drawRect(0,0,WIDGET_W,WIDGET_H); //»­±³¾°

		for(int i=1;i<=height_map;i++)
			for(int j=1;j<=width_map;j++)
			{
				if(mysnake->MAP[i][j]==1)
				{
					p->setPen(Qt::red);p->setBrush(Qt::green);
					p->drawRect((j-1)*WIDGET_W/width_map,(i-1)*WIDGET_H/height_map,WIDGET_W/width_map,WIDGET_H/height_map);
				}
				else if(mysnake->MAP[i][j]>1)
				{
					p->setPen(Qt::blue);
					p->setBrush(QColor(255,255,0));
					p->drawRect((j-1)*WIDGET_W/width_map,(i-1)*WIDGET_H/height_map,WIDGET_W/width_map,WIDGET_H/height_map);
				}
				if(mysnake->MAP[i][j]==FOOD)
				{
					p->setPen(Qt::white);
					p->setBrush(Qt::red);
					p->drawRect((j-1)*WIDGET_W/width_map,(i-1)*WIDGET_H/height_map,WIDGET_W/width_map,WIDGET_H/height_map);
				}
			}

			p->setPen(Qt::green);
			p->drawText(0,50,QString("score: %1").arg(mysnake->score));
	delete p;
	lab->setPixmap(pix);
	*/
}
void snakeWidget::initial()
{
	//donothing
}
void snakeWidget::updateFrame(int num)
{
	if(!mysnake->gameOver)
	{
		mysnake->moveStep();
		freshScreen();
	}
	if(mysnake->gameOver)
	{
		cout<<"gameOver!"<<endl;
		freshScreen();

	}
}
void snakeWidget::timerEvent(QTimerEvent *e)
{
	updateFrame(1);
}
void snakeWidget::calcFood(int flag)
{
}
void snakeWidget::keyPressEvent(QKeyEvent *e)
{
	int keyCode=e->key();
	//cout<<"keyCode="<<keyCode<<endl;
	if(mysnake->gameOver)
	{
		if(keyCode==4152 ) {//left soft key
			mysnake->gameReset();
			killTimers();
			startTimer(150);
		}else if(keyCode == 4154){//right soft key
			qApp->exit();
		}
		return;
	}
	switch(keyCode)
	{
		case 87://ÉÏ
		case 4115://Ò¡¸ËÉÏ
		case 50://2¼ü
		case 16777235:
			if(mysnake->moveUp()) {updateFrame(1);}
			break;
		case 83://ÏÂ
		case 4117://Ò¡¸ËÏÂ
		case 56://8
		case 16777237:
			if(mysnake->moveDown()) {updateFrame(1);}
			break;
		case 65://×ó
		case 4114://Ò¡¸Ë×ó
		case 52://4
		case 16777234:
			if(mysnake->moveLeft()) {updateFrame(1);}
			break;
		case 68://ÓÒ
		case 4116://Ò¡¸ËÓÒ
		case 54://6
		case 16777236:
			if(mysnake->moveRight()) {updateFrame(1);}
			break;
		case 4154://ÓÒ¼ü
			qApp->exit();
			break;
		default:
			cout<<keyCode<<endl;
			break;
	}
}
