#include <iostream>
#include <vector>

int main(int argc, char const *argv[])
{
    int j[] {0, 1, 2, 3};
    auto item = std::begin(j);
    for (; item < std::end(j); ++item)
    {
        std::cout << *(item) <<  "\n";
    }
    std::vector<int> a{0, 1, 2};
    auto &tmp = a[0];
    tmp = 15;
    std::cout<< a[0] << "\n";
    return 0;
}
