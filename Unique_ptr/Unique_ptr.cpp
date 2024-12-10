
#include <iostream>
#include <memory>
using namespace std;
class A
{
public:
	void setValue(int _Val)
	{
		Val = _Val;
	}

private:
	int Val = 0;
};

void RefSet(unique_ptr<A>& ptr, int _Val)
{
	ptr->setValue(_Val);
}

void GetSet(A* ptr, int _Val)
{
	ptr->setValue(_Val);
}

int main()
{
	// unique_ptr은 내부에서 복사 생성자를 제거해서 복사가 안됨.

	unique_ptr<A> pa_1(new A());
	unique_ptr<A> pa_2(new A());
	pa_1 = pa_2; // 삭제된 함수라고 오류가 뜸

	unique_ptr<A> pa_3(new A());
	RefSet(pa_3, 3); // 참조로 받으면 unique_ptr을 사용하는 의미가 없음.
	GetSet(pa_3.get(), 3);

	// 이렇게 new를 직접 할 경우 예외가 발생한다면 unique_ptr이 초기화되지 않고 메모리 누수가 발생할 수도 있음.
	std::unique_ptr<A> ptr11(new A());

	// make는 예외가 발생하면 내부에서 메모리 해제를 처리하므로 예외 발생에 있어 더 안전함.
	unique_ptr<A> pa2 = make_unique<A>();
	pa2.get()->setValue(5);

	A* a2 = new A();
	pa2.reset(a2); // 매우 위험한 코드임 a2의 외부 동작을 막지못함.
	delete a2; // delete를 하게되면 double delete 문제가 발생하므로 하면안되는 짓. (오류나는거보니 막지는 못하는듯)

	pa2.reset(new A()); // 쓸거면 이렇게 쓰거나 그냥 새로 만드는게 나음.
	pa2.reset(nullptr); // 이렇게 소유 해제도 가능.
	pa2.reset(); // nullptr이 기본 인자임. 

	unique_ptr<A> pa3 = make_unique<A>();

}

