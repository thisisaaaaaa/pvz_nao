#include"cardBar.h"
#include<graphics.h>
#include<iostream>

CardBar::CardBar()
{
	num = 0;
	sun_count = 25;
}

CardBar::CardBar(std::vector<Card>& arr_card)
{
	num = arr_card.size();
	sun_count = 25;
	cardBar.resize(num);
	for (int i = 0; i < num; i++)
	{
		cardBar[i] = single_cardBar(i);
		cardBar[i].set_card(&arr_card[i]);
	}
}

void CardBar::draw_bar(int x,int y)
{
	putimage(x, y, &RESALL.plantingBar);
	settextcolor(BLACK);
	setbkmode(TRANSPARENT);
	int textHeight = textheight(std::to_string(sun_count).c_str());
	int textWidth = textwidth(std::to_string(sun_count).c_str());
	outtextxy(x+20+(SUNTEXTWIDTH-textWidth)/2, y + 77+(SUNTEXTHEIGHT-textHeight)/2, std::to_string(sun_count).c_str());
	if (num != 0)
	{
		for (int i = 0; i < num; i++)
		{
			//调用Card里的
		}
	}
}

single_cardBar* CardBar::get_location(int msgx, int msgy)
{
	for (int i = 0; i < cardBar.size(); i++)
	{
		if (msgx > cardBar[i].get_x() && msgx< cardBar[i].get_x() + cardBar[i].get_width() && msgy > cardBar[i].get_y() && msgy < cardBar[i].get_y() + cardBar[i].get_height())
		{
			return &cardBar[i];
		}
		else return NULL;
	}
}



void CardBar::on_input(const ExMessage& msg)
{
	if (msg.message == WM_LBUTTONDOWN) {
		single_cardBar* temp = get_location(msg.x, msg.y);
		if (temp != NULL)
		{
			std::cout << temp->get_x() << " " << temp->get_y() << std::endl;
		}
	}
}