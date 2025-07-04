//卡片类的声明

//卡片状态 跟随阳光更新
//卡片位置 跟随鼠标左键移动
#include"object.h"
#include"sun.h"
class card:public object{
    public:
    enum class Type
		{
			sunflower ,
			pea_shooter
		};

    card(int x,int y,Type type);

    //在不同位置画卡片
    void draw()const;

    //更新卡片状态（调整放在上方栏的图片阴影）
    void update(const sun& sun){
        //根据sun.value更新当前卡片的状态
    }

    //选中卡片
    void check_click(/*鼠标位置*/){
        //鼠标点击一次选中 鼠标松开 若未经过拖动则取消选中 若经过拖动则直接种植
    }

    //检查是否选中（）
    bool is_selected(){
        //通过check_click函数判断是否选中
        //选中之后卡片离开上方栏
    }

    //长按移动以种植卡片（卡片追随鼠标）
    bool move_card();

    //检查卡片是否可用
    bool is_available()const;

    //获取阳光消耗
    int get_sun_cost() { return sun_cost; }

    Type type;
    int width,height;//卡片尺寸
    bool available;//设定是否可用
    int sun_cost;//设定阳光消耗
};