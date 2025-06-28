#include<iostream>
#include<graphics.h>
#include "JiangShi.h"
#include "res.h"
#include "PlayScene.h"


MyRes RESALL;
PlayScene playScene; // 创建PlayScene对象

int main()
{
	srand(static_cast<unsigned int>(time(0))); // 设置随机种子
	initgraph(1400, 600);//初始化画布

	bool running = true;//控制游戏结束

	RESALL.load();//加载资源
	BeginBatchDraw();//开始绘画

	JiangShi common;           //创建僵尸对象
	common.init_jiangshi();    //初始化僵尸

	while (running)
	{
		const DWORD start_time = GetTickCount();//获取开始时间

		cleardevice();//清除画布

		playScene.on_draw(0, 0); // 绘制游戏场景背景

		
		common.move();             //移动僵尸
		common.draw(144, 100);       //绘制僵尸，参数为每帧的时间间隔和图片切换时间

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