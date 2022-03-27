#include<iostream>
#include<string>
#include<vector>
#include<cstddef>

using std::string;
using std::vector;

int main() {
    //vector不是类型，而是模板。编译器根据模板描述来创建类或函数，这个过程称为实例化。
    vector<int> v1; //初始化一个空vector，元素类型为int
    vector<int> v2(v1); //v2包含v1中的所有元素副本
    vector<int> v3(10, 1); //v3容器数量为10，所有元素初始值是1
    vector<int> v4(10); //v4容器数量为10，默认值取决于元素类型
    vector<int> v5{1, 2, 3}; //v5包含指定序列元素
    vector<int> v6 = {1, 2, 3}; //等价v5
    vector<int> v7 = v6; //把v6所有元素拷贝给v7
    vector<int> v8(v6); //等价v7
    
    //c++中vector能高效增长，不需要褚时指定长度
    int tmp = 0;
    for(int i = 0; i < 10; i++) {
        v1.push_back(i);
    }
    //i一定要初始化
    for(decltype(v1.size()) i = 0; i != v1.size(); ++i) {
        std::cout << v1[i] << std::endl;
    }

    string str = "Hello world!";
    //迭代器，可迭代对象/容器，都有begin()和end()，begin返回容器中第一个元素，end返回容器中最后一个元素的下一个位置
    for (auto it = str.begin(); it != str.end() && !isspace(*it); ++it) {
        //迭代器通过*解引用来取出所指向的元素
        *it = toupper(*it);
    }
    std::cout << str << std::endl;

    //迭代器实际类型为容器内的iterator
    vector<int>::iterator it1 = v1.begin();
    string::iterator it2 = str.begin();
    //对于常量容器，返回的常量迭代器
    const string cstr = "Hello world";
    const vector<int> cv= {1 ,2, 3};
    string::const_iterator cstr_ite= cstr.begin();
    vector<int>::const_iterator cv_itr = cv.begin();
    //对于只想读，不想修改，可直接使用常量迭代器，c++11提供了cbegin和cend来创建常量迭代器
    vector<int>::const_iterator cv_itr2 = v1.cbegin();
    //以上是用于标识出类型，一般我们无需关系迭代器类型，直接auto声明迭代器就行

    //如果容器中不是build-in类型，而是类类型，则可以通过箭头运算符获取内部成员 
    vector<string> vstr = {"abc", "", "def"};
    for(auto it = vstr.cbegin(); it != vstr.cend(); ++it) {
        //箭头运算符获取内部成员，相当于:(*it).empty()
        if (!it -> empty()) {
            std::cout << *it << std::endl;
        }
    }

    vector<int> v10 = {1, 3, 5, 6, 8, 9, 14, 19, 21};
    auto begin = v10.cbegin();
    auto end = v10.cend();
    //两个迭代器相减则为二者指向索引的的差值
    auto mid = begin + (end - begin) / 2;
    int query_num = 19;
    int result = 0;
    while(mid != end) {
        if (*mid == query_num) {
            std::cout << "find num:" << *mid << std::endl;
            break;
        }
        if (*mid < query_num) {
            //索引+/-则为向前或向后移动指定位置
            begin = mid + 1;
        } else {
            end = mid;
        }
        mid = begin + (end - begin)/2;
    }
}