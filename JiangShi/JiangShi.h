//声明了一个僵尸类
#include "ZhiWu.h"
class JiangShi {
	public:
		enum class Type{normal, ghost, }; //僵尸的属性
		enum class State{walking, attacking, dying}; //僵尸的状态

		State state;

	//构造函数
		JiangShi(Type type, int row); //僵尸类型 僵尸生成所在行
	//析构函数
		virtual ~JiangShi() = default;

	virtual void move(int speed); //移动
	virtual void take_damage(int degree); //受到伤害
	virtual void attack_plant(ZhiWu &plant); //攻击植物


	private:
		Type type;
		int row;


};