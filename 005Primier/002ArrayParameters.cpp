#include <iostream>

void test(int a[2])
{
    a[0] = 1;
    a[1] = 0;
}

int main(int argc, char const *argv[])
{
    /* code */
    int a[2] = {0, 0};
    test(a);
    for (auto i: a)
    {
        std::cout<< i << "\n";
    }
    return 0;
}
