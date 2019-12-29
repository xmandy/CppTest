// 例1：只有复制构造函数
// can not use clang, it automatically add move-copy-assign constructor
#include <iostream>
using namespace std;

// interface
class Useless
{
private:
    int n;          // number of elements
    char * pc;      // pointer to data
    static int ct;  // number of objects
    void ShowObject() const;

public:
    Useless();
    explicit Useless(int k);
    Useless(int k, char ch);
    Useless(const Useless & f); // regular copy constructor
    ~Useless();
    Useless operator+(const Useless & f)const;
    void ShowData() const;
};

// implementation
int Useless::ct = 0;

Useless::Useless()
{
    ++ct;
    n = 0;
    pc = nullptr;
    cout << "default constructor called; number of objects: " << ct << endl;
    ShowObject();
}

Useless::Useless(int k) : n(k)
{
    ++ct; 
    cout << "Useless(int k) constructor called; number of objects: " << ct << endl;
    pc = new char[n];
    ShowObject();
}

Useless::Useless(int k, char ch) : n(k)
{
    ++ct;
    cout << "Useless(int k, char ch) constructor called; number of objects: " << ct << endl;
    pc = new char[n];
    for (int i = 0; i < n; i++)
        pc[i] = ch;
    ShowObject();
}

Useless::Useless(const Useless & f) : n(f.n) 
{
    ++ct;
    cout << "copy constructor const called; number of objects: " << ct << endl;
    pc = new char[n];
    for (int i = 0; i < n; i++)
        pc[i] = f.pc[i];
    ShowObject();
}

Useless::~Useless()
{
    cout << "destructor called; "; 
    cout << "deleted object:\n";
    ShowObject();
    delete [] pc;
    cout << "objects left: " << --ct << endl << endl;
}

Useless Useless::operator+(const Useless & f)const
{
    cout << "Entering operator+()\n";
    Useless temp = Useless(n + f.n);
    for (int i = 0; i < n; i++)
        temp.pc[i] = pc[i];
    for (int i = n; i < temp.n; i++)
        temp.pc[i] = f.pc[i - n];
    cout << "temp object:\n";
    cout << "Leaving operator+()\n";
    return temp;
}

void Useless::ShowObject() const
{ 
    cout << "Number of elements: " << n;
    cout << " Data address: " << (void *) pc << endl << endl;
}

void Useless::ShowData() const
{
    if (0 == n)
    {
        cout << "(object empty)";
    }
    else
    {
        for (int i = 0; i < n; i++)
            cout << pc[i];
    }
    cout << endl;
}

// application
int main()
{
    {
        Useless one(10, 'x');
        Useless two = one;          // calls copy constructor
        Useless three(20, 'o');
        Useless four(one + three);  // calls operator+(), copy constructor
        cout << "object one: ";
        one.ShowData();
        cout << "object two: ";
        two.ShowData();
        cout << "object three: ";
        three.ShowData();
        cout << "object four: ";
        four.ShowData();
        std::move(one);
    }
    cin.get();
}

// out
/*
Useless(int k, char ch) constructor called; number of objects: 1
Number of elements: 10 Data address: 004A4910

copy constructor const called; number of objects: 2
Number of elements: 10 Data address: 004A4958

Useless(int k, char ch) constructor called; number of objects: 3
Number of elements: 20 Data address: 004A49A0

Entering operator+()
Useless(int k) constructor called; number of objects: 4
Number of elements: 30 Data address: 004A49F0

temp object:
Leaving operator+()
copy constructor const called; number of objects: 5
Number of elements: 30 Data address: 004A4C50

destructor called; deleted object:
Number of elements: 30 Data address: 004A49F0

objects left: 4

object one: xxxxxxxxxx
object two: xxxxxxxxxx
object three: oooooooooooooooooooo
object four: xxxxxxxxxxoooooooooooooooooooo
destructor called; deleted object:
Number of elements: 30 Data address: 004A4C50

objects left: 3

destructor called; deleted object:
Number of elements: 20 Data address: 004A49A0

objects left: 2

destructor called; deleted object:
Number of elements: 10 Data address: 004A4958

objects left: 1

destructor called; deleted object:
Number of elements: 10 Data address: 004A4910

objects left: 0

*/