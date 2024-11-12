#include <iostream>
using namespace std;

void print_string(string* Val)
{
	cout << *Val << endl;
}

int main()
{
	// const_cast 사용처 : 클래스의 포인터 또는 참조값만 가능
	{	
		string DefaultString = "Default_String";
		print_string(&DefaultString);

		const string ConstString = "Const_String";
		print_string(const_cast<string*>(&ConstString));

		//print_string(&ConstString); -> error
	}

	cout << endl;

	// static_cast 기본 형변환
	{
		size_t Size = 10;
		int to_Int = static_cast<int>(Size); // 암시적 형변환 : int to_int = Size;

		int Integer = 65;
		char to_Char = static_cast<char>(Integer); // 암시적 형변환 : char to_char = Integer;

		char Character = 'A';
		int Char_to_Int = static_cast<int>(Character); // 암시적 형변환 : int Char_to_Int = Character;

		cout << "<static_cast 기본 사용법>" << endl;
		cout << "size_t = 10 -> int : " << to_Int << endl;
		cout << "int = 65 -> char : " << to_Char << endl;
		cout << "char = 'A' -> int : " << Char_to_Int << endl;
	}

	// static_cast와 dynamic_cast 차이
	{
		class Parent
		{
		public:
			string name = "";
			int Age;
		};

		class Child : public Parent
		{
		public:
			string School = "";
		};

		// static_cast 사용처
		{
			Parent* Parent_ptr = new Parent();
			Child* Child_ptr = new Child();

			Parent* static_cast_Parent_ptr = static_cast<Parent*>(Child_ptr);
			Child* static_cast_Child = static_cast<Child*>(Parent_ptr); // 다운 캐스팅 가능 (주의)

			Parent Parent_obj = Parent();
			Child Child_obj = Child();

			Parent static_cast_Parent = static_cast<Parent>(Child_obj); // 업캐스팅 가능
			//Child static_cast_Child = static_cast<Child>(Parent_obj); // 다운 캐스팅 불가
		}

		// dynamic_cast 사용법 : 클래스의 포인터 또는 참조값만 가능
		{
			Parent* Parent_ptr = new Parent();
			Child* Child_ptr = new Child();

			Parent* static_cast_Parent_ptr = dynamic_cast<Parent*>(Child_ptr); // 업캐스팅 가능
			//Child* static_cast_Child = dynamic_cast<Child*>(Parent_ptr); // 다운 캐스팅 불가 (가상함수 테이블이 안만들어져서 크기가늠 불가)
		}

		class Vir_Parent
		{
		public:
			Vir_Parent() {}
			virtual ~Vir_Parent()
			{
			}

			string name = "";
			int Age;
		};

		class Vir_Child : public Vir_Parent
		{
		public:
			Vir_Child() {}
			~Vir_Child()
			{
			}

			string School = "";
		};

		// static_cast
		{   
			Vir_Parent Parent_obj = Vir_Parent();
			Vir_Child Child_obj = Vir_Child();

			Vir_Parent static_cast_Parent = static_cast<Vir_Parent>(Child_obj); // 업캐스팅 가능
			//Vir_Child static_cast_Child = static_cast<Vir_Child>(Parent_obj); // 다운 캐스팅 불가


			Vir_Parent* Parent_ptr = new Vir_Parent();
			Vir_Child* Child_ptr = new Vir_Child();

			Vir_Parent* static_cast_Parent_ptr = static_cast<Vir_Parent*>(Child_ptr); // 업 캐스팅 가능
			Vir_Child* static_cast_Child = static_cast<Vir_Child*>(Parent_ptr); // 다운 캐스팅 가능 (주의)
		}

		// dynamic_cast 가상함수를 하나라도 선언해서 가상 테이블이 생성된다면 다운 캐스팅이 가능해짐
		{   
			Vir_Parent* Parent_ptr = new Vir_Parent();
			Vir_Child* Child_ptr = new Vir_Child();

			Vir_Parent* static_cast_Parent_ptr = dynamic_cast<Vir_Parent*>(Child_ptr); // 업캐스팅 가능
			Vir_Child* static_cast_Child = dynamic_cast<Vir_Child*>(Parent_ptr); // 다운 캐스팅 가능
		}
	}
	
}