#include<iostream>
using namespace std;
struct Sbit {
    bool    Flag : 1;
    unsigned int Day  : 3;
    unsigned int Night : 4;
};

int main(int argc, char const *argv[])
{
    /* code */
    Sbit a {0, 1, 2};
    std::cout<< "size: " << sizeof(a) << "\n";
    return 0;
}
