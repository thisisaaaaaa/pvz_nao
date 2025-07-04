#include<iostream>
#include<graphics.h>
#include<vector>
#include "JiangShi.h"
#include "res.h"
#include "PlayScene.h"
#include "ZhiWu.h"
#include "movingScene.h"
#include <time.h>
#include<stdlib.h>

int game_cnt = 0;
int delta = 1000/144;
int idx_cnt = 0;
MyRes RESALL;
PlayScene playScene; // 创建PlayScene对象
ExMessage msg;
grass_grid *current_grid;
std::vector<JiangShi*> dier;
std::vector<ZhiWu*> plant;
int main()
{
	srand((unsigned int)(time(NULL))); // 设置随机种子
	initgraph(1000, 600);//初始化画布

	bool running = true;//控制游戏结束

	RESALL.load();//加载资源
	ZhiWu zhiwu;
	JiangShi common;           //创建僵尸对象
	common.init_jiangshi();    //初始化僵尸
	zhiwu.init_zhiwu(_T("res/%d.png"), 13);
	moving_scene();
	BeginBatchDraw();//开始绘画
	while (running)
	{
		const DWORD start_time = GetTickCount();//获取开始时间
		game_cnt += 1;
		idx_cnt += 1;
		if ((idx_cnt * delta)>10000) {
			int rand_row = rand() % 5;
			JiangShi* temp_dier = new JiangShi();
			std::cout << rand_row << std::endl;
			common.creat_dier(temp_dier,rand_row);
			dier.push_back(temp_dier);
			idx_cnt = 0;
		}
		while (peekmessage(&msg)) {
			if (msg.message == WM_LBUTTONDOWN) {
				current_grid = playScene.get_location(msg.x,msg.y);
				if (current_grid != NULL) {
					if (current_grid->get_status()) {
						break;
					}
					else {
						current_grid->set_status(1);
						ZhiWu* temp = new ZhiWu();
						temp->idx = plant.size();
						temp->col = current_grid->get_y();
						temp->row = current_grid->get_x();
						plant.push_back(temp);
						current_grid->which_plant = temp->idx;
					}
				}
			}
			else if(msg.message == WM_RBUTTONDOWN) {
				current_grid = playScene.get_location(msg.x, msg.y);
				if (current_grid != NULL) {
					if (current_grid->get_status()) {
						int idx = current_grid->which_plant;
						current_grid->which_plant = NULL;
						plant[idx] = NULL;
						current_grid->set_status(0);
					}
				}
				else {
					break;
				}
			}
		}


		cleardevice();//清除画布

		playScene.on_draw(0, 0); // 绘制游戏场景背景

		zhiwu.drawplant(plant,45,1000/144);           
		common.draw(dier,144, 1000);       //绘制僵尸，参数为每帧的时间间隔和图片切换时间

		FlushBatchDraw();//批量绘画



		const DWORD end_time = GetTickCount();//获取结束时间
		const DWORD elapsed_time = end_time - start_time;//计算耗时
		if (elapsed_time < 1000 / 144)
		{
			Sleep(1000 / 144 - elapsed_time);//如果耗时小于16.67毫秒，则等待剩余时间
		}
	}
	EndBatchDraw();

	return 0;
}