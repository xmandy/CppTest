#include <iostream>
#include <cmath>
#include <bitset>

using namespace std;

int main(int argc, char const *argv[])
{
    /* code */
    /*
    //version 1
    float r = 0.8;
    float g = 0.7;
    float b = 0.1;

    float presion = 100.0;
    float presionReal = 100.0;

    float encode = float(int(r*presion) + int(g*presion)*int(presionReal) + int(b*presion) * int(presionReal) * int(presionReal));
    encode /= presionReal * presionReal * presionReal;

    cout << "1 " << encode << "\n";
    encode *= presionReal * presionReal * presionReal;
    float rD = (encode - int(encode / presionReal) * presionReal) / presion;
    float gD = float(int(float(int((encode - int(encode / presionReal / presionReal) * presionReal * presionReal))) / presionReal)) / presion;
    float bD = float(int(encode / presionReal / presionReal)) / presion;

    cout << "2 " << encode << ", " << int(r * presion) << ", " << rD << "\n";
    cout << "r: " << rD << " g: " << gD << " b: " << bD << "\n";
    */
   using uint = unsigned int;

    // version 2
    uint r = 120;
    uint g = 234;
    uint b = 98;

    unsigned int res = (r & 0xFF) | ((g & 0xFF) << 8) | ((b & 0xFF) << 16);

    float encode = (float)res/float(0xFFFFFF);
    encode = 0.23529;
    uint rD = ((unsigned int)round(encode * 0xFFFFFF)) & 0xFF;
    uint gD = (((unsigned int)round(encode * 0xFFFFFF)) & 0xFF00) >> 8;
    uint bD = (((unsigned int)round(encode * 0xFFFFFF)) & 0xFF0000) >> 16;

    cout << "1 " << bitset<sizeof(int)*8>(res) << "\n";
    cout << "1 " << hex << res << "\n";
    cout << "2 " << hex << (unsigned int)round(encode * 0xFFFFFF) << "\n";
    uint tmp = ((uint)round(encode * 0xFFFFFF));
    cout << "3 " << dec<< tmp;

    cout <<dec<< "r: " << rD << " g: " << gD << " b: " << bD << "\n";

    cout <<  tmp << "\n";
    return 0;
}
