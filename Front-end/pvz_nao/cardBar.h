#pragma once
#include"res.h"
#include<vector>
#include<string>
#include"Card.h"
extern MyRes RESALL;


class single_cardBar
{
private:
	int status;     //格子的状态可以判断是否有植物卡片,格子中的卡片是否能种植；

	//格子在整个种植栏中的坐标和宽高
	int x;
	int y;
	int width;
	int height;

	//卡片类，里面记录了卡片的信息
	Card* card;

public:
    
	//无参构造
	single_cardBar()
	{
		status = 0;
		x = 0;
		y = 0;
		width = 65;
		height = 90;
		card = NULL;
	}

	//有参构造
	single_cardBar(int i)
	{
		status = 0;
		width = 65;
		height = 90;
		x = 390 + i * width;
		y = 8;
		card = NULL;
	}

	//获取状态信息
	int get_status()
	{
		return status;
	}

	//获取格子中的卡片信息
	Card* get_card()
	{
		return card;
	}

	//获取格子在种植栏中的x坐标
	int get_x()
	{
		return x;
	}

	//获取格子的种植栏中的y坐标
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

	void set_card(Card* ptr)
	{
		card = ptr;
	}
};


class CardBar
{
public:
	//构造函数和析构函数
	CardBar();                      
	CardBar(std::vector<Card> &arr_card);
	~CardBar() = default;

	//绘图函数
	void draw_bar(int x,int y);

	//获取信息函数，和草方块差不多，返回一个单个栏子中的指针，可以获取里面的信息
	single_cardBar* get_location(int msgx, int msgy);


	void on_input(const ExMessage & msg);
	//设置阳光的函数,这只是初步的定了一个大体的框架
	void set_suncount(int sunnum);//还需要传入一个信息


private:
	std::vector<single_cardBar> cardBar;            //存卡片的数组
	int num;                                        //记录了存储了多少卡片
	int sun_count;                                  //记录阳光总数
	
	//阳光文本框的长度与高度
	int const SUNTEXTWIDTH = 50;
	int const SUNTEXTHEIGHT = 15;
};