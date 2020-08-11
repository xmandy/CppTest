#include <iostream>

int b[3]{1, 1, 1};

using ArrayType = int[3];
ArrayType* test1()
{
    return &b;
}

int* test2()
{
    return &b[0];
}

void print(int a[3])
{
    for(auto i = 0; i < 3; ++i)
        std::cout << "test----->>: " << a[i] << "\n";

}

int main(int argc, char const *argv[])
{
    int a[3]{0};

    print(*test1());
    print(test2());

    /* code */
    return 0;
}
