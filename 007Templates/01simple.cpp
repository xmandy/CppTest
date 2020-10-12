#include <iostream>

template<class T, T val>
struct test
{
    typedef T value_type;
    static const T value = val;
};

int main(int argc, char const *argv[])
{
    std::cout << test<bool, true>::value << "\n";
    return 0;
}
