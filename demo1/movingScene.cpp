#include"movingScene.h"

const int WINDOW_WIDTH = 1000;
const int WINDOW_HEIGHT = 600;
const int STARTBUTTON_WIDTH = 192;
const int STARTBUTTON_HEIGHT = 75;


void moving_scene()
{

	//这是场景移动到最边上的坐标
	int minLeft = 1000 - RESALL.playBG.getwidth();

	//这是开始按钮的矩阵区域加载
	RECT startButton_rect;
	startButton_rect.left = (WINDOW_WIDTH - STARTBUTTON_WIDTH) / 2;
	startButton_rect.right = startButton_rect.left + STARTBUTTON_WIDTH;
	startButton_rect.top = (WINDOW_HEIGHT - STARTBUTTON_HEIGHT) / 2;
	startButton_rect.bottom = startButton_rect.top + STARTBUTTON_HEIGHT;

	//这是场景移动
	for (int x = 0; x >= minLeft; x -= 3)
	{
		putimage(x, 0, &RESALL.playBG);
		Sleep(20);
		FlushBatchDraw();
	}
	EndBatchDraw();

	ExMessage msg;
	startButton start = startButton(startButton_rect, "res/ui_start_idle.png", "res/ui_start_hovered.png");
	BeginBatchDraw();
	while (!start.is_game_started)
	{
		while (peekmessage(&msg))
		{
			start.ProcessEvent(msg);
		}

		cleardevice();
		putimage(minLeft, 0, &RESALL.playBG);
		start.Draw();
		FlushBatchDraw();
	}
	EndBatchDraw();

	//这是场景移回
	BeginBatchDraw();
	for (int x = minLeft; x <= 0; x += 3)
	{
		putimage(x, 0, &RESALL.playBG);
		Sleep(20);
		FlushBatchDraw();
	}
	EndBatchDraw();


	//这是开头字幕
	int timer = 0;
	BeginBatchDraw();
	while (timer < 2400)
	{
		cleardevice();
		putimage(0, 0, &RESALL.playBG);
		timer += 1;
		if (timer <= 800)
			putimagePNG(350, 234, &RESALL.startSet);
		else if (timer > 800 && timer <= 1600)
			putimagePNG(350, 234, &RESALL.startReady);
		else
			putimagePNG(350, 240, &RESALL.startPlant);

		FlushBatchDraw();
	}
	EndBatchDraw();
}