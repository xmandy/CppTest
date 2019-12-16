#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
    vector<int> IntVec;
    IntVec.push_back(0);
    IntVec.push_back(1);

    vector<int>::const_iterator Begin = IntVec.cbegin();
    vector<int>::const_iterator End = IntVec.cend();

    int ia[] = {0, 2, 4, 6, 8};


    cout << "test: " << End - Begin << "\n";

    cout << "test1: " << IntVec[1] << "\n";

    int *p = &ia[2];
    cout << "test2: " << p[-2] << "\n";


    return 0;
}
