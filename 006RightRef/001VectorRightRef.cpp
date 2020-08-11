
#include <iostream>
#include <vector>
using namespace std;

using IntVec = vector<int>;

IntVec gVec;

void test(IntVec &&vec)
{
    gVec = std::move(vec);
}

int main(int argc, const char** argv) {
    IntVec localVec{0, 1, 2, 3, 4};
    for(auto i:  localVec)
    {
        std::cout<< "111 " << i << "\n";
    }

    test(std::move(localVec));
    for(auto i:  gVec)
    {
        std::cout<< "222 " << i << "\n";
    }

    for(auto i:  localVec)
    {
        std::cout<< "333 " << i << "\n";
    }



    return 0;
}