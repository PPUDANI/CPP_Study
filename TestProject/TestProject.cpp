#include <iostream>
#include <vector>
#include <functional>
#include <memory>
using namespace std;

int main()
{
	int a;
	shared_ptr<int> sp = std::make_shared<int>(a);
	weak_ptr<int> wp1(sp);
	wp1.reset();
}
