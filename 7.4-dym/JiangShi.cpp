//这里写具体的僵尸函数e.g.掉血 吃植物
#include "JiangShi.h"
#include<stdlib.h>
#include <time.h>
std::vector<IMAGE*> walk;               //僵尸图片数组
void JiangShi::init_jiangshi()
{
	for (int i = 0; i < 22; i++)
	{
		std::string file_name = "res/zombie/zombie_walk/" + std::to_string(i + 1) + ".png";
		IMAGE* frame = new IMAGE();
		loadimage(frame, file_name.c_str());
		walk.push_back(frame);
	}
		
	
	
}

void JiangShi::creat_dier(JiangShi*temp_dier,int row_rand) {
	temp_dier->state = State::walking;
	temp_dier->row = row_rand;
	temp_dier->type = Type::normal;
	switch (temp_dier->type)
	{
	case Type::normal:
		temp_dier->health = 100;
		temp_dier->damage = 10;
		temp_dier->speed = 2;
		break;
	case Type::luzhang:
		temp_dier->health = 150;
		temp_dier->damage = 10;
		temp_dier->speed = 30;
		break;

	}
	grass_grid demo;
	temp_dier->width = demo.get_width();                              // 获取草坪格子的宽度
	temp_dier->height = demo.get_height();                            // 获取草坪格子的高度
	temp_dier->position.x = 255 + (temp_dier->width + 12) * 9;                   // 初始位置x坐标
	temp_dier->position.y = (temp_dier->height + 15) * (temp_dier->row + 1)-70;             // 初始位置y坐标
}


void JiangShi::move(JiangShi *temp_dier)
{
	temp_dier->position.x -= double(temp_dier->speed)/10; // 每秒移动像素

	//如果撞到植物则停止(未完成)

	
}




void JiangShi::draw(std::vector<JiangShi*> dier,int delta,int change_time)
{
	for (int i = 0; i < dier.size(); ++i) {
		if (dier[i]) {
			move(dier[i]);
			dier[i]->exist_time += delta;
			if (dier[i]->exist_time > change_time) {
				dier[i]->cnt = (dier[i]->cnt + 1) % 22;
				dier[i]->exist_time = 0;
			}
			putimagePNG(dier[i]->position.x, dier[i]->position.y, walk[dier[i]->cnt]); // 绘制行走图片
		}
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