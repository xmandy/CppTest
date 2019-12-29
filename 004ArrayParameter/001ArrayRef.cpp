#include <iostream>

int main(int argc, const char** argv) {
    int a[3]{1, 2, 3};
    for (auto i : a)
    {
        std::cout << i << "\n";
    }
    int (&b)[3] = a;
    for (auto i : b)
    {
        std::cout << i << "\n";
    }
    return 0;
}

/*
four func return string[10]&
string (&func())[10]

typedef string stype[10]
stype& func();

auto func() -> string(&) [10];

string str[10];
decltype(str) &func();
*/
