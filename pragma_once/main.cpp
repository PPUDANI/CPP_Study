
#include "A.h"
#include "B.h" // B.h에더 A가 Include 되었지만 재정의 오류가 나지 않음.

int main()
{
	A ObjA = A();
	B ObjB = B();
}