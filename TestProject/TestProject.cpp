#include <iostream>
#include <vector>
#include <string>
using namespace std;

int add(int a, int b)
{
	cout << &a << &b << endl;
	int result = a + b;
	return result;
}


int main()
{
	/*for (int i = 0; i < 10000; ++i)
	{
		add(i, i + 5);
	}*/

	vector<int> vec(10, 0);
	int a = vec[2];
	int b = vec[3];
}
