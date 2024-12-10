#include <iostream>
using namespace std;

int main()
{
	char a[100];
	cout << strlen(a) << " byte" << endl;
	string str = "";

	str += a[0];
	str += a[1];
	str += a[2];
	str += a[3];

	cout << str << endl;
}