#include <iostream>

using namespace std;

class A
{
    public:
    inline virtual void ShowNum() 
    {
        cout << "This Time : " << mNum << "\n";
    }
    private:
    int mNum = 0;

};

class B: public A
{
    public:
    inline virtual void ShowNum() override
    {
        A::ShowNum();
        cout << "test\n";
    }
};

int main(int argc, const char** argv) {
    B b;
    b.ShowNum();
    return 0;
}