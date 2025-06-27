#include<iostream>
#include<graphics.h>

int main()
{
	initgraph(1280, 720);//初始化画布

	bool running = true;//控制游戏结束

	BeginBatchDraw();

	while (running)
	{
		const DWORD start_time = GetTickCount();//获取开始时间
		
		cleardevice();//清除画布

		FlushBatchDraw();
		
		const DWORD end_time = GetTickCount();//获取结束时间
		const DWORD elapsed_time = end_time - start_time;//计算耗时
		if (elapsed_time < 1000 / 60)
		{
			Sleep(1000 / 60 - elapsed_time);//如果耗时小于16.67毫秒，则等待剩余时间
		}
	}
	EndBatchDraw();

	return 0;
}