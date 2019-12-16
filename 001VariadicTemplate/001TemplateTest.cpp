#include <iostream>

template <class... Ts>
struct tuple {};

template<class T, class... Ts>
struct tuple<T, Ts... >: tuple<Ts... > {
    tuple(T t, Ts... ts): tuple(Ts... ts), tail(t) {};
    T tail;
};

template<size_t, class> struct holder {};

template <class T, class... Ts>
struct holder<0, tuple<T, Ts...>> { typename T EleType;};

template<size_t Size, class T, class... Ts>
struct holder<Size, tuple<T, Ts...>> { typename holder<Size-1, tuple<Ts...>>::EleType EleType;};