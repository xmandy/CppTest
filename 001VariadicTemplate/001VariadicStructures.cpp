#include <iostream>

template <class... Ts> struct tuple {};

template <class T, class... Ts>
struct tuple<T, Ts...> : tuple<Ts...>
{
    tuple(T t, Ts... ts): tuple<Ts ...>(ts...), tail(t) {}
    T tail;
};

// element holder helps to get element from tuple
template<size_t, class> struct elem_type_holder;

template <class T, class... Ts>
struct elem_type_holder<0, tuple<T, Ts...>>
{
    typedef T elem_type;
};

template<size_t k, class T, class... Ts>
struct elem_type_holder<k, tuple<T, Ts...>>
{
    typedef typename elem_type_holder<k-1, tuple<Ts...>>::elem_type elem_type;
};


template<size_t k, class... Ts>
typename std::enable_if<
    k == 0, typename elem_type_holder<0, tuple<Ts...>>::elem_type&>::type
    get(tuple<Ts...>& t)
    {
        std::cout << __PRETTY_FUNCTION__ << "\n";
        return t.tail;
    }

template<size_t k, class T, class... Ts>
// outside type is std::enable_if structure's field
typename std::enable_if<
    k != 0, typename elem_type_holder<k, tuple<T, Ts...>>::elem_type&>::type
    get(tuple<T, Ts...>& t)
    {
        std::cout << __PRETTY_FUNCTION__ << "\n";
        tuple<Ts...> &base = t;
        return get<k-1>(base);
    }

int main(int argc, char const *argv[])
{
    //tuple<double, int, const char*> temp(1.0, 1, "abc");
    //tuple<int, const char*> temp2 = temp;
    tuple<int, int, int>temp(1, 2, 3);
    tuple<int, int> temp2 = temp;
    std::cout << "0 th is:\n" << get<0>(temp) << "\n";
    std::cout << "1 th is:\n" << get<1>(temp) << "\n";
    std::cout << "2 th is:\n" << get<2>(temp) << "\n";
    std::cout<< get<0>(temp2) << "\n";
    return 0;
}






/*
int main(int argc, char const *argv[])
{
    tuple<double, int, const char*> t1(2.0, 8, "111");
    return sizeof(t1);
}
*/
