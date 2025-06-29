//这里写具体的僵尸函数e.g.掉血 吃植物
#include "JiangShi.h"

void JiangShi::init_jiangshi()
{
	state = State::walking;    // 初始化状态为行走
	row = 0;     // 设置僵尸所在行
	type = Type::normal;       // 设置僵尸类型为普通僵尸(可以添加类型)
	switch (type)
	{
		case Type::normal:
			health = 100;
			damage = 10;
			speed = 2;
			for (int i = 0; i < 22; i++)
			{
				std::string file_name = "res/zombie/zombie_walk/" + std::to_string(i+1) + ".png";
				
				loadimage(&walk[i], file_name.c_str());
			}
			break;
		case Type::luzhang:
			health = 150;
			damage = 10;
			speed = 30;
			break;

	}
	grass_grid demo;
	width = demo.get_width();                              // 获取草坪格子的宽度
	height = demo.get_height();                            // 获取草坪格子的高度
	position.x = 255 + (width + 12) * 9;                   // 初始位置x坐标
	position.y = 90 + (height + 15) * (row+1);             // 初始位置y坐标
}

void JiangShi::move()
{
	position.x -= double(speed)/10; // 每秒移动像素

	//如果撞到植物则停止(未完成)

	
}

void JiangShi::draw(int delta,int change_time)
{
	if (state == State::walking)
	{
		static int timer = 0,index = 0;
		timer += delta; // 增加计时器
		if(timer > change_time) 
		{
			index = (index + 1) % 22;               // 循环切换图片
			timer = 0;                             // 重置计时器
		}
		putimagePNG(position.x, position.y, &walk[index]); // 绘制行走图片
	}
}

JiangShi::State JiangShi::get_state() 
{
	return state;
}

std::vector<double> JiangShi::get_position() 
{
	return { position.x, position.y };
}