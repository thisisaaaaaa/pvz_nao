#include "PlayScene.h"


PlayScene::PlayScene()
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			grass_grid temp(j, i);
			grass[i][j] = temp;
		}
	}
	left = 0;
}



void PlayScene::on_update()
{
	std::cout << "正在运行" << std::endl;
}

void PlayScene::on_draw(int x,int y)
{
	putimage(x, y, &RESALL.playBG);
}

void PlayScene::on_input(const ExMessage& msg)
{
	if (msg.message == WM_LBUTTONDOWN) {
		grass_grid* temp = get_location(msg.x, msg.y);
		if (temp != NULL)
		{
			std::cout << temp->get_index_x() << " " << temp->get_index_y() << std::endl;
		}
	}
}


grass_grid* PlayScene::get_location(int msg_x, int msg_y)
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (grass[i][j].get_x() < msg_x && grass[i][j].get_x() + grass[i][j].get_width() > msg_x && grass[i][j].get_y() < msg_y && grass[i][j].get_y() + grass[i][j].get_height() > msg_y)
			{
				return &grass[i][j];
			}
		}
	}
	return NULL;
}



void PlayScene::moving_scene()
{
	int minLeft = 1100 - RESALL.playBG.getwidth();
	for (int x = 0; x >= minLeft; x -= 2)
	{
		BeginBatchDraw();
		on_draw(x, 0);
		EndBatchDraw();
		Sleep(20);
	}
	left = minLeft;
	for (int x = minLeft; x <= 0; x += 2)
	{
		BeginBatchDraw();
		on_draw(x, 0);
		EndBatchDraw();
		Sleep(20);
	}
}