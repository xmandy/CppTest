#include <iostream>
#include <vector>

// func type definitions

using FuncType = int(int, int); // functype
using FuncTypePointer = int(*)(int, int); // functype pointer

int add(int x, int y)
{
    return x + y;
}

int sub(int x, int y)
{
    return x - y;
}

auto getFunc(bool is_add) -> int(*)(int, int)
{
    if (is_add)
        return  add;
    else
    {
        return sub;
    }
}

int main(int argc, const char** argv) {

    std::vector<decltype(add) *> FuncPointerVec;
    FuncPointerVec.push_back(add);
    FuncPointerVec.push_back(sub);

    FuncType* test = add;
    FuncTypePointer test1 = add;

    std::cout << "test1 " <<  FuncPointerVec[0](1, 2) << "\n";
    std::cout << "test2 " <<  getFunc(false)(1, 2) << "\n";

    
    return 0;
}