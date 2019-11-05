#include <iostream>

template<typename T>
T adder(T v)
{
    std::cout << __PRETTY_FUNCTION__ << "\n";
    return v;
}

template <typename T, typename... Args>
T adder(T first, Args... args)
{
    std::cout << __PRETTY_FUNCTION__ << "\n";
    return first + adder(args...);
}

template<typename T>
bool pair_comparer(T a, T b)
{
    return a == b;
}

template<typename T>
bool pair_comparer(T a)
{
    return false;
}

template<typename T, typename... Args>
T pair_comparer(T a, T b, Args... args)
{
    return a == b && pair_comparer(args...);
}

int main(int argc, char const *argv[])
{
    /* code */
    std::cout << adder(1, 2, 3, 4, 5) << "\n";

    std::cout << "comparer: " << pair_comparer(1, 1, 2, 2, 3, 3) << "\n";
    return 0;
}
