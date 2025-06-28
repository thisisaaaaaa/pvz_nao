//声明一个植物类
#include"JiangShi.h"
class ZhiWu {
	public:
		enum class Type{sunflower ,peashooter};
		enum class State { dying, attacking,};

		Type type;
		State state;
		int row;
		int col;

	//构造函数
		ZhiWu(Type type, int row , int col );
	//析构函数
		virtual void ~ZhiWu() = default;

		virtual void normal( );//正常状态下植物的动画
		virtual void take_damage(int degree);//受到伤害
		virtual void attack_jiangshi(JiangShi& jiangshi); //攻击僵尸

		// 获取位置
		int getrow() const { return row; };
		int getcol() const { return col; };


};
