//阳光类
//随时间产生阳光 点击收集
//植物被吃产生阳光 自动收集
//用阳光购买植物
//向日葵产生阳光
#include"object.h"
#include"card.h"

class sun:public object{
    public:
        int x;
        int y;
        int value;//当前拥有的阳光值
        sun(int x,int y,int value);

        //绘制阳光
        void draw()const;

        //鼠标左键点击收集阳光
        void collect(/*pos*/);

        //产生阳光（向日葵产生 随机产生 植物死亡产生）
        void make_sun( ){
            //位置
            //刷新时间
            //加载图片
        }

        //消耗阳光(根据卡片类型扣除阳光)
        void cost_sun(const card& sun_cost_of_card){
            //
        }

        int get_value(){ return value; }

}