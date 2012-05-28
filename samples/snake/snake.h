/*
 * snake.h
 *
 *  Created on: 2010-10-28
 *      Author: ��׿
 */

#ifndef SNAKE_H_
#define SNAKE_H_


#include <iostream>
#include <cmath>
#include <ctime>

using namespace std;

#define WALL -1		//ǽ
#define NOTHING -2	//�հ�
#define FOOD 0		//ʳ��

#define WIDTH 24	//���������
#define HEIGHT 32	//���������

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
		void createBody(int x,int y);//��������
		void getFood();//�����õ�ʳ��ʱ����
		bool setFood(int x,int y);//ǿ���趨ʳ��λ��
		void clearFood();//���ʳ�ֻ���ڻ�ͼ�ϣ�
		bool createFood();//����ʳ��
		void resetFood();//����ʳ��
	public:
		int MAP[HEIGHT+2][WIDTH+2];//��ͼ����������:-2Ϊ�� -1Ϊǽ 0Ϊfood 1���Ժ�ΪBody���α�� ���ܼ���һȦ�����ǽ
	public:
		enum director{UP,DOWN,LEFT,RIGHT}direct;//�ߵ��ƶ�����
		int length,ori_x,ori_y;//�ߵĳ��ȣ�����ͷ��Ĭ������
		int width_map,height_map;//����ĳ�����
		int score;//��Ϸ�÷�
		coordinate head,trail;//ͷ��β������ֵ
		coordinate snakeFood;//ʳ�������ֵ
		bool gameOver;//��Ϸ������־
	public:
		void moveStep();//������һ֡����
		void gameReset();//��Ϸ��λ
		int moveUp();//�ƶ�����
		int moveDown();
		int moveLeft();
		int moveRight();
		void gotoXY(int x,int y);
    private:
		bool createFood_lock;
};

#endif /* SNAKE_H_ */
