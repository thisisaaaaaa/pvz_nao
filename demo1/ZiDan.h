//声明一个子弹类

class ZiDan {
	public:
        enum class Type { pea, fire, ice };

        Type type;
        int row;
     //构造函数
        ZiDan(Type type, int row, int damage,);
    //析构函数
        virtual ~ZiDan() = default;

        virtual void move(int speed); //移动
};