#include <iostream>
#include <unordered_set>
#include <vector>

struct ObjectByPointer
{
    int *data = nullptr;

    // must supply this funciton.
    friend bool operator == (const ObjectByPointer& object0, const ObjectByPointer& object)
    {
        return object0.data == object.data;
    }

    bool operator == (const ObjectByPointer& object)
    {
        return data == object.data;
    }

    // bool operator==(const ObjectByPointer object)
    // {
    //     return data == object.data;
    // }

    ObjectByPointer(int* input)
    : data(input)
    {

    }

};

size_t HashFunc(const ObjectByPointer& input)
{
    return std::hash<int*>()(input.data);
}

// custom specialization of std::hash can be injected in namespace std
// namespace std
// {
//     template<> struct hash<S>
//     {
//         std::size_t operator()(S const& s) const noexcept
//         {
//             std::size_t h1 = std::hash<std::string>{}(s.first_name);
//             std::size_t h2 = std::hash<std::string>{}(s.last_name);
//             return h1 ^ (h2 << 1); // or use boost::hash_combine
//         }
//     };
// }

int main(int argc, char const *argv[])
{
    /* code */
    std::unordered_set<ObjectByPointer, decltype(HashFunc)*>  mySet(10, HashFunc);
    int a = 1;
    int b = 2;
    int c = 3;
    mySet.emplace(&a);
    mySet.emplace(&b);
    mySet.emplace(&c);
    for (auto& iter: mySet)
    {
        std::cout << iter.data << "\n";
        /* code */
    }
    
    std::cout << (mySet.find(&a) == mySet.end()) << "\n";

    std::vector<int> a1{1, 2, 3};
    std::vector<int> a2{5, 2, 3};

    std::unordered_set<int> test;
    test.insert(std::begin(a1), std::end(a1));
    test.insert(std::begin(a2), std::end(a2));

    for (auto& iter: test)
    {
        unsigned int a = 4;
        std::cout << a * 8.3 << "\n";
        std::cout << iter << "\n";
    }

    


    return 0;
}

