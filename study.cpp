#include <iostream> //引入标准io头文件

int main()
{

    int val1 = 1;
    double val2 = 3.14;

    // C++11引入auto类型说明符，让编译器推断表达式类型
    auto val3 = val1 + val2;

    // decltype返回操作数或表达式的类型
    decltype(val2) val4 = 3.1415;
    int &val5 = val1;
    //变量加上()则得到的类型是引用类型，对于引用类型需要初始化
    decltype((val1)) val6 = val5;
}
