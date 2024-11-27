#include<iostream>
#include<vector>
using namespace std;

int main() {
	vector<int> vec;
	vec.push_back(0);
	vec.push_back(3);

	// access the third element, which doesn't exist
	try
	{
		vec.at(2);
	}
	catch (exception& ex)
	{
		cout << ex.what() << endl;
	}

	return 0;
}