#include <iostream>
#include <vector>
using namespace std;

// 두 문법 모두 자료형 별칭 치환으로 기능은 같음.
// 가독성 면에서 떨어지므로 using이라는 최신 문법을 만들게 됨.

// typedef
typedef unsigned int Typedef_UINT;

// using
using Using_UINT = unsigned int;

// 가장 큰 차이점은 template을 사용 유무임.
// typedef은 기본적인 문법으로는 template을 사용할 수 없음.
template <typename T>
typedef std::vector<T> type; // ERROR!

// 만약 사용하려면 별칭을 구조체 내에서 정의해야함.
template <typename T>
struct Vec {
    typedef std::vector<T> type; 
};

// using은 template 사용이 가능하고 더욱 가독성있으며 간편함.
template <typename T>
using Vec_T = vector<T>;

int main()
{
    std::cout << "Hello World!\n";
}
