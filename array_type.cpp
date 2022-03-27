#include<iostream>
#include<iterator>
#include<cstddef>

int main() {
     unsigned int arr[10];
    //size_t：数组下标一般使用size_t无符号类型，他是cstddef中定义的
    for(size_t i = 0; i < 9; ++i) {
        arr[i] = i;
    }

    std::cout << arr[5] << std::endl;

    int array[] = {1, 2, 3, 4, 5};
    //取出array的首元素指针
    int *ap = array;
    //和数组名字作为首元素指针一样
    ap = &array[0];
    //获取数据尾指针(最后元素下一个位置)，数组指针可以执行vector中大部分动作
    int *ap_end = &array[5];
    //指针执行+/-还是指针，向前或先后指向的元素
    for (int *i = array; i != ap_end; ++i) {
        std::cout << *i << std::endl;
    }

    //c++11中在iterator头文件中的begin和and来获取数据首指针和尾指针，
    int *array_begin = std::begin(array);
    int *array_end = std::end(array);
    for (; array_begin != array_end; ++array_begin) {
        std::cout << *array_begin << std::endl;
    }
    //ptrdiff_t和size_t一样，都是cstddef中的有符号整型
    ptrdiff_t siz = array_end - array_begin;
}