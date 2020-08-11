
#include <iostream>
#include <istream>
#include <iterator>
#include <fstream>

using namespace std;

int main(int argc, char const *argv[])
{
    /* code */
    istream_iterator<int> int_it(cin);
    istream_iterator<int> int_eof;

    ifstream in("aaa.txt");
    istream_iterator<string> str_it;
    while (int_it != int_eof)
    {
        cout<< "test: " << *int_it++ << "\n";
    }
    
    return 0;
}
