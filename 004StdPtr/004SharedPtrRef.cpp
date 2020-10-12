#include <iostream>
#include <memory>
#include <vector>
#include <unordered_set>

// shared_ptr使用ref时，需要注意背后的shared_ptr对象是否已经被释放

int main(int argc, char const *argv[])
{
    std::vector<std::shared_ptr<int>> test;

    std::unordered_set<std::shared_ptr<int>> test1;

    test.push_back(std::make_shared<int>(5));
    auto& value = test.back();
    std::cout << *value << "\n";
    // test.pop_back();
    // std::cout << *value << "\n";
    test1.emplace(std::move(value));
    test.pop_back();
    std::cout << *value << "\n";




    return 0;
}
