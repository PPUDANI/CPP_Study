
#include <vector>
#include <algorithm>

bool compare(int Left, int Right)
{
	return Left > Right;
}


int main()
{
	std::vector<int> vec = {1, 2, 3, 4, 5};
	std::sort(vec.begin(), vec.end(), compare);
	

}