#include <unordered_map>
#include <iostream>
#include <vector>

struct Test
{
    int a;
    Test(int x)
    : a(x)
    {

    }
};

int main(int argc, char const *argv[])
{
    std::vector<std::unordered_map<int, Test>> maps;
    maps.resize(3);
    signed char idx = 0; 
    std::cout << (idx - 1 + 3) % 3 << "\n";

    const auto& iter = maps[0].find(1);
    std::cout << (iter == maps[0].end()) << "\n";
    return 0;
}
