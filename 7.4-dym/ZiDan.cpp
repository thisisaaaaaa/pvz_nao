#include "ZiDan.h"
#include "ZhiWu.h"
#include<stdlib.h>
#include <time.h>

std::vector<IMAGE*> normal_pea_fly;         //子弹飞行图片数组
std::vector<IMAGE*> normal_pea_attack;      //子弹消失图片数组

extern std::vector<JiangShi*> dier;

void ZiDan::init_zidan()
{
	/*for (int i = 0; i < 22; i++)
	{
		std::string file_name = "res/zombie/zombie_walk/" + std::to_string(i + 1) + ".png";
		IMAGE* frame = new IMAGE();
		loadimage(frame, file_name.c_str());
		walk.push_back(frame);
	}*/
	IMAGE* frame = new IMAGE();
	loadimage(frame, "res/zidan/PeaNormal_0.png");
	normal_pea_fly.push_back(frame);
	loadimage(frame, "res/zidan/PeaNormalExplode_0.png");
	normal_pea_attack.push_back(frame);


}

void ZiDan::creat_zidan(ZiDan* temp_flying,ZhiWu* demo) {
	temp_flying->state = State::flying;
	temp_flying->type = Type::normal_pea;
	switch (temp_flying->type)
	{
	case Type::normal_pea:
		temp_flying->damage = 10;
		temp_flying->speed = 10;
		break;
	case Type::icy_pea:
		temp_flying->damage = 15;
		temp_flying->speed = 10;
		break;

	}
	temp_flying->position.x = demo->row;                   // 初始位置x坐标
	temp_flying->position.y = demo->col;                   // 初始位置y坐标
}

void ZiDan::state_change(ZiDan* temp_flying)
{
	// 如果子弹飞出屏幕，则设置状态为消失
	if (temp_flying->position.x > 1000) {
		temp_flying->state = State::disappearing; 
		return;
	}
	//如果和僵尸相遇，则设置状态为攻击
	for (int i = 0; i < dier.size();i++) {
		if (dier[i]) {
			if (dier[i]->position.x == temp_flying->position.x && dier[i]->position.y == temp_flying->position.y)
			{
				temp_flying->state = State::attacktive;
				return;
			}
		}
	}
	//如果上述都不存在则不变
	return;
}

void ZiDan::move(ZiDan* temp_flying)
{
	if(temp_flying->state == State::flying)
		temp_flying->position.x -= double(temp_flying->speed) / 10; // 每秒移动像素
}




void ZiDan::draw(std::vector<ZiDan*>& temp, int delta, int change_time)
{
	for (int i = 0; i < temp.size(); ++i) {
		if (temp[i]) {
			move(temp[i]);
			temp[i]->exist_time += delta;
			if (temp[i]->exist_time > change_time) {
				temp[i]->cnt = (temp[i]->cnt + 1) % 1;
				temp[i]->exist_time = 0;
			}
			if(temp[i]->state == State::flying)
				putimagePNG(temp[i]->position.x, temp[i]->position.y, normal_pea_fly[temp[i]->cnt]); // 绘制飞行图片
			else if (temp[i]->state == State::attacktive)
			{
				if (temp[i]->leave_time > 0)
				{
					putimagePNG(temp[i]->position.x, temp[i]->position.y, normal_pea_attack[temp[i]->cnt]); // 绘制攻击图片
					--leave_time;
				}
				else
				{
					temp[i] = NULL; // 攻击后删除子弹
				}
			}
				
		}
	}
}

void ZiDan::clear(std::vector<ZiDan*>& temp)
{
	for (int i = 0; i < temp.size(); ++i)
	{
		if (temp[i]->state == State::disappearing)
		{
			temp[i] = NULL; // 清理消失的子弹
		}
	}
}

ZiDan::State ZiDan::get_state()
{
	return state;
}

std::vector<double> ZiDan::get_position()
{
	return { position.x, position.y };
}