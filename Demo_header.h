//为了防止头文件多次引入，使用预处理器(编译之前的一段程序)
//#define xx 定义一个预处理变量; #ifdef xx 当且仅当xx定义时为真; #ifndef xx 当且仅当xx未定义时为真。一旦为真，则执行代码直到#endif
//这套操作称为：头文件保护符

//第一次加载当前头文件时处理变量DEMO_HEADER_H未定义，ifndef为真则一直执行到#endif，当执行到#define时定义预处理变量 
#ifndef DEMO_HEADER_H
#define DEMO_HEADER_H
#include<string>
/*
 * 头文件一般包含那些只被定义一次的实体，比如类、const、constexpr变量等
 */

//struct关键字定义类
// 类一般定义在头文件中，而且头文件名称应与类名一致。这样类方便被各个文件所复用。
struct Demo_header {
    unsigned int v1 = 0;
    double v2 = 0;
    std::string v3;
//类体后面要加分号，因为后面可以紧跟变量名，以表示是当前类的类型
} d1;
#endif