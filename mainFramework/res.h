#pragma once
#include<graphics.h>


/*使用说明
  在拥有主函数的文件中先定义一个全局变量，统一名称就叫 ***RESALL***，具体形式为 MyRes RESALL
  在其他文件中如果需要用到资源的话，那么需要包含头文件include"res.h"，并声明有一个外部变量extern MyRes RESALL
*/
class MyRes
{
public:
	IMAGE menuBG;                     //开始菜单的背景图片
	IMAGE selectButton1;              //开始菜单的开始按钮默认状态
	IMAGE selectButton2;              //开始菜单的开始按钮默认状态
	IMAGE playBG;                     //游玩场景的背景
	IMAGE plantingBar;                 //场景上面的植物种植栏
	IMAGE card_pea;                   //豌豆卡片
	IMAGE card_sunflower;             //向日葵卡片
	IMAGE card_wallnut;               //坚果卡片  
	IMAGE startSet;                    //开始的时候的文字图片Set
	IMAGE startReady;                 //开始的时候的文字图片Ready
	IMAGE startPlant;                  //开始的时候的文字图片Set
	
	void load()
	{
		loadimage(&menuBG, "res/menu.png");
		loadimage(&playBG, "res/background1.jpg");
		loadimage(&selectButton1, "res/menu1.png");
		loadimage(&selectButton2, "res/menu2.png");
		loadimage(&plantingBar, "res/bar.jpg");
		loadimage(&card_pea, "res/card_pea.png");
		loadimage(&card_sunflower, "res/card_sunflower.png");
		loadimage(&card_wallnut, "res/card_wallnut.png");
		loadimage(&startSet, "res/StartSet.png");
		loadimage(&startReady, "res/StartReady.png");
		loadimage(&startPlant, "res/StartPlant.png");
		
	}
};



