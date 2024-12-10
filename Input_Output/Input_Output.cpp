
#include <iostream>
using namespace std;

int main()
{
	char arr[100];
	int b;
	cin >> arr;

	//cout << sizeof(char) << endl;
	//cin.ignore(100, '\n');

	cin.ignore(numeric_limits<streamsize>::max(), '\n'); // 들어있는input 만큼 무시하겠다 즉 버퍼 클리어

	cin >> b;

	cout << arr << "\n" << b;
}

