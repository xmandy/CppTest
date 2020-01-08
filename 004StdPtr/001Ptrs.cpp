#include <iostream>
#include <memory>

class B;
class C;

class A
{
    public:
    A() {std::cout << "allocA: " << this << "\n";}
    ~A() { std::cout<< "deallocA" << "\n"; }
    std::shared_ptr<B> mPtr1;
    std::shared_ptr<C> mPtr2;
};

class B
{
    public:
    B() {}
    ~B() { std::cout<< "deallocB" << "\n"; }
    std::weak_ptr<A> mPtr;
};

class C
{
    public:
    C() {}
    ~C() { std::cout<< "deallocC" << "\n"; }
    std::shared_ptr<A> mPtr;
};

int main(int argc, char const *argv[])
{
    /* code */
    {
        std::shared_ptr<A> a1(new A);
        std::shared_ptr<A> a2(new A);
        std::shared_ptr<B> b(new B);
        std::shared_ptr<C> c (new C);
        // case 1
        a1->mPtr1 = b;
        b->mPtr = a1;
        std::cout<< a1.use_count() << " " << b.use_count() << "\n";
        a2->mPtr2 = c;
        c->mPtr = a2;
        std::cout<< a2.use_count() << " " << c.use_count() << "\n";
    }
    system("pause");
    return 0;
}
