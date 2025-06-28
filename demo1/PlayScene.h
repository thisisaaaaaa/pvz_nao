#pragma once
#include<iostream>
#include"res.h"
#include<graphics.h>
extern MyRes RESALL;


//草坪格子的类
class grass_grid
{
private:
	int status;     //格子的状态，默认没有植物的时候为零，有植物的时候为1；
	
	//格子在窗口的坐标和宽高
	int x;         
	int y;
	int width;
	int height;

	//格子在数组中的位置
	int index_x;
	int index_y;

public:
	//无参构造
	grass_grid()
	{
		status = 0;
		x = 0;
		y = 0;
		width = 70;
		height = 80;
		index_x = 0;
		index_y = 0;
	}

	//有参构造(i为列数，j为行数)
	grass_grid(int i, int j)
	{
		status = 0;
		width = 70;
		height = 80;
		x = 255 + i * width + i * 12;
		y = 90 + j * height + j * 15;
		index_x = i;
		index_y = j;
	}

	//获取格子的窗口x坐标
	int get_x()
	{
		return x;
	}

	//获取格子的窗口y坐标
	int get_y()
	{
		return y;
	}

	//获取格子的宽度
	int get_width()
	{
		return width;
	}

	//获取格子的高度
	int get_height()
	{
		return height;
	}

	//获取格子的数组x坐标
	int get_index_x()
	{
		return index_x;
	}

	//获取格子的数组y坐标
	int get_index_y()
	{
		return index_y;
	}

	//设置状态
	void set_status(int num)
	{
		status = num;
	}
};


//上面装卡片的格子类
class single_cardBar
{
private:
	int status;     //格子的状态可以判断阳光是否可以使其种植；
	//格子在窗口的坐标和宽高
	int x;
	int y;
	int width;
	int height;
public:
	//无参构造
	single_cardBar()
	{
		status = 0;
		x = 0;
		y = 0;
		width = 65;
		height = 90;
	}

	//有参构造
	single_cardBar(int i)
	{
		status = 0;
		width = 65;
		height = 90;
        
	}

	//获取格子的窗口x坐标
	int get_x()
	{
		return x;
	}

	//获取格子的窗口y坐标
	int get_y()
	{
		return y;
	}

	//获取格子的宽度
	int get_width()
	{
		return width;
	}

	//获取格子的高度
	int get_height()
	{
		return height;
	}

	//设置状态
	void set_status(int num)
	{
		status = num;
	}
};



class PlayScene
{
public:
	PlayScene();
	~PlayScene() =default;

	//void putimagePNG(int x, int y, IMAGE* img);
	void on_update();                    //更新游玩场景的数据
	void on_input(const ExMessage& msg);              //处理玩家输入信息
	void on_draw(int x ,int y);//渲染游玩场景的图片

	grass_grid* get_location(int msg_x,int msg_y);     //这个函数是用来看图片上的某一点坐标属于哪一个草坪块,返回一个指针，如果不在合理位置中，会返回一个NULL指针


	//还没搞好
	void moving_scene();             //移动场景



	grass_grid grass[5][9];                //草地的后端数组实现
	single_cardBar cardBar[8];                    //卡片槽的后端数组实现

private:
	int left;               
};

