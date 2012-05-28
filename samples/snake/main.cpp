/*
 * main.cpp
 *
 *  Created on: 2010-10-28
 *      Author: ¸¶×¿
 */

#include <ZApplication.h>
#include "snakeWidget.h"

int main(int argc ,char *argv[])
{
	ZApplication *app=new ZApplication(argc,argv);
	snakeWidget *widget=new snakeWidget();
	widget->show();
	app->exec();
	delete widget;
	delete app;
	return 0;
}
