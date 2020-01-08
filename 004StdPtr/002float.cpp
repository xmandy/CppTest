#include <iostream>
#include<vector>
#include<algorithm>
#include <memory>

class A
{
    public:
        A() { }
        A(int val) { 
            value = val;
            std::cout << "A construct" << val <<  "\n";
        }

        int value{0};
};

struct sorter {
    bool operator () (const int& l, const int r) const
    {
        return l < r;
    }
};

struct sorterA {
     bool operator () (const A& l, const A& r) const
    {
        return l.value < r.value;
    }
} sorterA1;


int main(int argc, char const *argv[])
{
    /* code */
    /*
    std::vector<int> vec;
    vec.emplace_back(1);
    vec.emplace_back(10);
    vec.emplace_back(4);
    std::sort(vec.begin(), vec.end(), sorter());
    for (auto i : vec)
        std::cout << i << "\n";
        */

    std::vector<A> vec;
    vec.emplace_back(1);
    vec.emplace_back(10);
    vec.emplace_back(4);
    std::sort(vec.begin(), vec.end(), sorterA1);
    for (auto i : vec)
        std::cout << i.value << "\n";


    int arr[] = {3, 8, 10, 2, 6, 9, 7};
    std::vector<std::shared_ptr<A>> vec1;
    for (int i = 0; i < 7; ++i)
    {
        int idx = 0;
        for (auto j = 0; j < vec1.size(); ++j)
        {
            if (arr[i] > vec1[j]->value)
            {
                idx = j + 1;
            }
        }
        vec1.insert(vec1.begin() + idx, std::make_shared<A>(arr[i]));

    }

    for (auto i : vec1)
        std::cout << i->value << "\n";

    return 0;
}
