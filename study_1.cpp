#include <iostream> //引入标准io头文件
#include "Demo_header.h" //引入自定义header

//下面的const说明
//const不管声明还是定义都使用extern
extern const int c2 = 456;

int main()
{

    //build-in type，内置类型实现与机器硬件密切相关，内置类型又称：算术类型
    char t1 = 'a';
    wchar_t t2 = 'b';
    char16_t t3 = 'c';
    char32_t t4 = 'd';
    bool t5 = true;
    short t6 = 1;
    int t7 = 2;
    long t8 = 3;
    long long t9 = 4;
    float t10 = 3.14;
    double t11 = 3.14;

    int inputVal = 0;
    //输入
    /* 
     * >>输入运算符，左侧为istream，右侧为从istream读取存储的数据的对象
     * :: 命名空间的作用域运算符，表示左侧的命名空间为右侧值
     */
    std::cin >> inputVal;
    //输出
    /* 
     * <<输出运算符，左侧为ostream，右侧为要输出的值
     * 无论输入还是输出都是一个表达式，c++表达式是返回值的，<<和>>表达式返回结果都是其左侧对象，即std::cout和std::cin
     * 这就是为什么可以联用<<和>>的原因
    */
    std::cout << "Input number: " << inputVal << std::endl;

    //复合类型，基于其它类型的类型。包括：引用和指针
    //引用：变量的别名(引用即别名)
    int origin_val = 1;
    //使用&定义引用变量，引用变量无法重新绑定其它变量，所以引用变量必须初始化。引用不是对象，只是一个对象的别名
    int &ref_val = origin_val;
    //指针：存储的是内存空间地址
    //使用*定义指针, &被称为取地址符，用于获取地址。因为应用不是对象，所以没有地址，所以指针不能指向引用
    int *ip1 = &origin_val;
    //指向指针的指针
    int **ip2 = &ip1;
    //指针变量加*被称为解引用，解引用是获取指针所指向的具体值。解引用符用来访问该对象
    std::cout << ip1 << *ip1 << std::endl; 
    //定义空指针有三种方式：
    //NULL为预处理变量，在cstdlib中定义，它的值就是0。预处理器在执行时会将其替换成0
    int *p1 = NULL;
    int *p2 = 0;
    //c++11新标准，可以被转换为指向任意
    int *p3 = nullptr;
    //void*指针是一种特殊指针，可用于存放任意对象的地址
    int vp1 = 1;
    double vp2 = 2;
    void *vp = &vp1;
    vp = &vp2;

    //const和constexpr用于声明常量
    //常量必须初始化，一旦赋值则不能修改
    const int c1 = 123;
    //extern const不能在函数内定义
    extern const int c2;
    //常量引用，绑定到常量的引用
    const int &const_ref = c1;
    //指向常量的指针
    const int *const_ip = &c1;
    //指针本身也是常量
    const int *const const_ip2 = &c1;
    //constexpr常量表达式，值不会改变，表达式在编译过程中就能计算出结果
    constexpr int constexpr_c1 = c1 + 1;

    //定义类型别名，两种方式: typedef和using
    typedef double alias_double;
    alias_double a1 = 3.14;
    using alias_double2 = double;
    alias_double2 a2 = 3.14;

    //auto类型说明符，C++11引入能让编译器推断表达式类型
    int val1 = 1;
    double val2 = 3.14;
    auto val3 = val1 + val2;

    //decltype返回操作数或表达式的类型
    decltype(val2) val4 = 3.1415;
    int &val5 = val1;
    //变量加上()则得到的类型是引用类型，对于引用类型需要初始化
    decltype((val1)) val6 = val5;

    //使用自定义类型
    Demo_header data1;
    std::cin >> data1.v1 >> data1.v2 >> data1.v3;
    std::cout << "v1: " <<data1.v1 << " v2: " << data1.v2 << " v3:" << data1.v3 << std::endl;
}