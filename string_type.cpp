#include<iostream>
#include<string> //string标准库头文件
#include<cctype> //ctype.h是c语言标准库头文件，c++标准库兼容c，一般使用c++头文件名称name.h -> cname，这样可用std namespace

//using声明，使用后则不需要通过namespace和作用域符
using std::cin;
using std::cout;
using std::endl;
using std::string;

int main() {
    //初始化string （拷贝初始化、直接初始化）
    string s1; //初始化空字符串
    std::string s2 = "abc"; //s2是abc字符串的副本，使用“=”赋值是拷贝初始化，编译器会把右侧初始值拷贝到新建对象中
    string s3("abc"); //等价s3是“abc”的副本
    string s4(s2); //s4是s2的副本
    string s5(10, 'a'); //连续10字符a组成的字符串

    //输入的不可见字符被忽略，比如空格、制表符等
    cin >> s1;
    cout << s1 << std::endl;
    //getline不忽略不可见字符，结束符被忽略
    //getline(cin, s1);
    cout << s1 << endl;

    if (!s1.empty()) {
        cout << "s1 no empty, size is:" << s1.size() << std::endl;
    }
    //string::size_type是string.size()实际返回值类型，是标准库类型中定义的几种配套类型之一
    //作用域符说明size_type是string中定义的
    string::size_type s1_len = s1.size();
    s3 = s2 + "def";
    //不支持，string相加，需要+两侧至少有一个string对象，不能都是字面值
    //s4 = "abc" + "def";

    //c++11提供的：范围for，遍历序列中的每个元素
    for (auto c : s3) {
        if (islower(c))
        cout << c << endl;
    }
    string s6 = "hello world!";
    //循环变量是引用类型，则引用变量实际绑定的是字符串中的原值
    for(char &c : s6) {
        c = toupper(c);
    }
    cout << "s6:" << s6 << endl;
    //通过下标索引访问
    s6 = "hello world!";
    s6[0] = toupper(s6[0]);
    cout << "s6:" << s6 << endl;
}