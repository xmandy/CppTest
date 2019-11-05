#include <iostream>

struct Types
{
    //typedef int TypeSlot0;
    //typedef float TypeSlot1;
    //typedef double TypeSlot2;
};

int main(int argc, const char** argv) {
    Types b;
    //Types::TypeSlot0 a = 10;
    int a;
    std::cout << "Hello World\n" << a << "\n" << sizeof(b) << "\n";
    return 0;
}