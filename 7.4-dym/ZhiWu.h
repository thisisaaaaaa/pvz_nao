//声明一个植物类
#pragma once
#include "Jiangshi.h"
#include "PlayScene.h"
#include "tools.h"
#include <vector>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
#include "object.h"
class ZhiWu :public object{
	public:
		enum class Type
		{
			sunflower ,
			pea_shooter
		};
		enum class State 
		{ 
			dying, 
			attacking
		};
		Type type;
		State state;
		int idx;
		int row;
		int col;
		int cnt = 0;

	//构造函数
		//ZhiWu(Type type, int row , int col );
	//析构函数
		//virtual void ~ZhiWu() = default;

		//virtual void normal( );//正常状态下植物的动画
		//virtual void take_damage(int degree);//受到伤害
		//virtual void attack_jiangshi(JiangShi& jiangshi); //攻击僵尸

		// 获取位置
		int getrow() const { return row; };
		int getcol() const { return col; };
		void drawplant(std::vector<ZhiWu*> plant, int interval, int delta);
		void init_zhiwu(LPCTSTR path, int num);
};
