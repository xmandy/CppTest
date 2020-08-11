#include <iostream>

class A
{
public:
    A(int x): a(x) {}


    int get() {return a;}

private:
    int a = 0;

};

void f(const A& test) {}

int main(int argc, const char** argv) {

    A tmp(3);
    A tmp1 = 3;
    f(3);

    return 0;
}