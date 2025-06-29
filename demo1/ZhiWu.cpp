#include "ZhiWu.h"
#include<iostream>
#include<vector>
#include<string>
#include<graphics.h>
#include "res.h"
#include "PlayScene.h"


void ZhiWu::drawplant(std::vector<ZhiWu*> plant) {
	for (int i = 0; i < plant.size(); ++i) {
		if (plant[i]) {
			IMAGE img;
			loadimage(&img,_T("res/1.png"));
			int x = plant[i]->row;
			int y = plant[i]->col;
			putimagePNG(x, y, &img);
		}
	}

}
