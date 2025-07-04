//声明了一个僵尸类
#pragma once
#include "ZhiWu.h"
#include "PlayScene.h"
#include "tools.h"
#include <vector>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
#include "object.h"

const int MAX_NUM = 50;
class JiangShi:public object {
public:
	//僵尸的属性
	enum class Type
	{
		normal,
		luzhang
	};
	//僵尸的状态
	enum class State
	{
		walking,
		attacking,
		dying
	};
	Type type;                   //类型
	State state;                 //状态
	double spawn_time = 10;      //生成时间
	int row;                     //所在行
	int health;                  //血量
	int height;                  //高度
	int width;                   //宽度
	struct position				 //位置
	{
		double x;
		double y;
	} position;
	int cnt = 0;                 // 动画计数器
	int speed;                   //速度
	int damage;                  //攻击力
	IMAGE attack[MAX_NUM];       //僵尸攻击图片数组
	IMAGE die[MAX_NUM];          //僵尸死亡图片数组

	//构造函数

	//僵尸类型 僵尸生成所在行
		//Jiangshi(Type type,int row)

	//析构函数
		//virtual ~JiangShi() = default;
		
	//初始化僵尸
	virtual void init_jiangshi();

	//僵尸移动
	virtual void move(JiangShi *temp_dier); 

	//僵尸绘制
	virtual void draw(std::vector<JiangShi*> dier,int delta,int change_time);

	//受到伤害
	//virtual void take_damage(int degree); 

	//攻击植物
	//virtual void attack_plant(ZhiWu &plant); 

	//获取状态
	virtual State get_state();

	//获取位置
	virtual std::vector<double> get_position();
	void creat_dier(JiangShi* temp_dier,int row_rand);
};