#include <iostream>
#include <vector>

using namespace std;

long long Foo(long long n)
{
    vector<int> A(10000);
    return n + Foo(n - 1);
}

int main()
{
    long long Res = Foo(10000);
}