#include <iostream>

class A
{
    A () {};
    ~A() { std::cout << "deconstruct A"
                     << "\n"; }
};

int main(int argc, char const *argv[])
{
    return 0;
}


