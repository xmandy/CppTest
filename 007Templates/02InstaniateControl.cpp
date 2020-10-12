#include <iostream>
#include <type_traits>
#include <string>

using namespace std;

/*
注意，使用AFINAE必须得是function template
如下: 如果去掉开头的template<class U=T>即变回class template
这样编译时就无法通过，class template必须保证每隔member function是well-formed
*/


template<class T>
class InstantiateSwitch
{
    public:
    InstantiateSwitch(T input)
        : value(input)
    {

    }

    template<class U = T>
    typename std::enable_if<std::is_integral_v<U>, std::string>::type
    PrintIntStr()
    {
        return "int";
    }

    template<class U = T>
    typename std::enable_if<std::is_floating_point_v<U>, std::string>::type
    PrintFloatStr()
    {
        return "float";
    }


    private:
    T       value;
};

int main(int argc, char const *argv[])
{
    InstantiateSwitch<int> a1(10);
    std::cout << a1.PrintIntStr() << "\n";

    InstantiateSwitch<float> a2(10.0);
    std::cout << a2.PrintFloatStr() << "\n";
    // a1.PrintFloatStr();
    
    return 0;
}
