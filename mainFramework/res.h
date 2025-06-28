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
	IMAGE selectButton1;              //开始菜单的开始按钮
	IMAGE selectButton2;              //开始菜单的开始按钮
	IMAGE selectButton3;              //开始菜单的开始按钮
	IMAGE playBG;                     //游玩场景的背景
	IMAGE plantingBar;                 //场景上面的植物种植栏
	IMAGE test;//试验

	void load()
	{
		loadimage(&menuBG, "res/Selector_BG.jpg");
		loadimage(&playBG, "res/background1.jpg");
		loadimage(&selectButton1, "res/SelectorScreen_Shadow_StartAdventure.jpg");
		loadimage(&selectButton2, "res/SelectorScreen_StartAdventure_Button1.jpg");
		loadimage(&selectButton3, "res/SelectorScreen_StartAdventure_Highlight.jpg");
		loadimage(&plantingBar, "res/bar.jpg");
		loadimage(&test, "res/card_pea.png");
	}
};




