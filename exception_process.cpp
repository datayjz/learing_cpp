#include<iostream>
//c++标准提供了4个标准库来处理异常
#include<stdexcept>  //常用异常类
#include<exception>  //最通用异常类
#include<new>        //定义了bad_alloc异常
//#include<type_info>//定义了bad_cast异常

int main() {
    //stdexception头文件中定义以下异常类
    //exception: 最常见的问题
    //runtime_error: 只有运行时才能检测到的问题
    //range_error: 运行时错误，生成结果超过值域范围
    //overflow_error: 运行时错误，计算上溢
    //underflow_error: 运行时错误，计算下溢
    //logic_error: 程序逻辑错误
    //domain_error: 逻辑错误，参数对应的结果值不存在
    //invalid_argument: 逻辑错误：参数无效
    //length_error: 逻辑错误，实处创建一个超出该类型的最大长度对象
    //out_of_range: 逻辑错误：使用一个超出范围有效值


    //异常处理语句try-catch
    try {
        int num1, num2;
        std::cin >> num1 >> num2;
        if (num2 == 0) {
            throw std::invalid_argument("Divisor cannot be 0.");
        }
        int result = num1 / num2;
        std::cout << "result:"  << result << std::endl;
    } catch(std::invalid_argument e) {
        std::cerr << e.what() << std::endl;
    } catch(std::runtime_error er) {
        std::cerr << er.what() << std::endl;
    }
}