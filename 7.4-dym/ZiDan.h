//声明一个子弹类
#pragma once
#include "PlayScene.h"
#include "ZhiWu.h"
#include "tools.h"
#include <vector>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
#include "object.h"


class ZiDan :public object {
	public:
        //子弹种类
        enum class Type 
        {
            normal_pea, 
            icy_pea 
        };
        //子弹状态
        enum class State 
        {
            flying, 
            disappearing,
            attacktive
		};
        Type type;                   //类型
		State state;                 //状态 
        double launch_time;          //发射间隔
        struct position				 //位置
        {
            double x;
            double y;
        } position;
        int damage;                  //伤害
		int speed;                   //速度
        int cnt = 0;                 // 动画计数器
		int leave_time = 20;         //滞留时间
     //构造函数
        //ZiDan(Type type, int row, int damage,);
    //析构函数
       // virtual ~ZiDan() = default;

        //初始化子弹
        virtual void init_zidan();

        //子弹移动
        virtual void move(ZiDan* temp);

        //子弹绘制
        virtual void draw(std::vector<ZiDan*>& temp, int delta, int change_time);

        //创建子弹
        void creat_zidan(ZiDan* temp,ZhiWu* demo);

        //状态改变
		void state_change(ZiDan* temp_flying);

        //清理子弹
        void clear(std::vector<ZiDan*>& temp);

        //获取状态
        virtual State get_state();

        //获取位置
        virtual std::vector<double> get_position();

};