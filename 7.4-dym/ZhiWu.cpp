#include "ZhiWu.h"
#include<iostream>
#include<vector>
#include<string>
#include<graphics.h>
#include "res.h"
#include "PlayScene.h"

std::vector<IMAGE*> frame_list;

void ZhiWu::init_zhiwu(LPCTSTR path, int num) {

	TCHAR path_file[1000];
	for (int i = 0; i < num; ++i) {
		std::string file_name = "res/" + std::to_string(i) + ".png";

		IMAGE* frame = new IMAGE();
		loadimage(frame, file_name.c_str());
		frame_list.push_back(frame);
	}



}
void ZhiWu::drawplant(std::vector<ZhiWu*> plant, int change_time,int delta) {
	for (int i = 0; i < plant.size(); ++i) {
		if (plant[i]) {
			plant[i]->exist_time += delta;
			if (plant[i]->exist_time > change_time) {
				plant[i]->cnt=(plant[i]->cnt+1)%13;
				plant[i]->exist_time = 0;
			}
			int x = plant[i]->row;
			int y = plant[i]->col;

			putimagePNG(x, y, frame_list[plant[i]->cnt]);
		}
	}

}
