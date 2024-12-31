#include <iostream>
using namespace std;

int main()
{
    int arr[2] = { 0, };
    //0b 00000001 00000010 00000011 00000100
    arr[0] = 0b00000001000000100000001100000100;
    __int8* ptr = reinterpret_cast<__int8*>(&arr[0]);
    
    cout << static_cast<int>(*(ptr)) << endl;
    ptr++;
    cout << static_cast<int>(*(ptr)) << endl;
    ptr++;
    cout << static_cast<int>(*(ptr)) << endl;
    ptr++;
    cout << static_cast<int>(*(ptr)) << endl;
    return 0;
}