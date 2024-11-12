#include <iostream>
using namespace std;

void print_string(string* Val)
{
	cout << *Val << endl;
}

int main()
{
	// const_cast ���ó : Ŭ������ ������ �Ǵ� �������� ����
	{	
		string DefaultString = "Default_String";
		print_string(&DefaultString);

		const string ConstString = "Const_String";
		print_string(const_cast<string*>(&ConstString));

		//print_string(&ConstString); -> error
	}

	cout << endl;

	// static_cast �⺻ ����ȯ
	{
		size_t Size = 10;
		int to_Int = static_cast<int>(Size); // �Ͻ��� ����ȯ : int to_int = Size;

		int Integer = 65;
		char to_Char = static_cast<char>(Integer); // �Ͻ��� ����ȯ : char to_char = Integer;

		char Character = 'A';
		int Char_to_Int = static_cast<int>(Character); // �Ͻ��� ����ȯ : int Char_to_Int = Character;

		cout << "<static_cast �⺻ ����>" << endl;
		cout << "size_t = 10 -> int : " << to_Int << endl;
		cout << "int = 65 -> char : " << to_Char << endl;
		cout << "char = 'A' -> int : " << Char_to_Int << endl;
	}

	// static_cast�� dynamic_cast ����
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

		// static_cast ���ó
		{
			Parent* Parent_ptr = new Parent();
			Child* Child_ptr = new Child();

			Parent* static_cast_Parent_ptr = static_cast<Parent*>(Child_ptr);
			Child* static_cast_Child = static_cast<Child*>(Parent_ptr); // �ٿ� ĳ���� ���� (����)

			Parent Parent_obj = Parent();
			Child Child_obj = Child();

			Parent static_cast_Parent = static_cast<Parent>(Child_obj); // ��ĳ���� ����
			//Child static_cast_Child = static_cast<Child>(Parent_obj); // �ٿ� ĳ���� �Ұ�
		}

		// dynamic_cast ���� : Ŭ������ ������ �Ǵ� �������� ����
		{
			Parent* Parent_ptr = new Parent();
			Child* Child_ptr = new Child();

			Parent* static_cast_Parent_ptr = dynamic_cast<Parent*>(Child_ptr); // ��ĳ���� ����
			//Child* static_cast_Child = dynamic_cast<Child*>(Parent_ptr); // �ٿ� ĳ���� �Ұ� (�����Լ� ���̺��� �ȸ�������� ũ�Ⱑ�� �Ұ�)
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

			Vir_Parent static_cast_Parent = static_cast<Vir_Parent>(Child_obj); // ��ĳ���� ����
			//Vir_Child static_cast_Child = static_cast<Vir_Child>(Parent_obj); // �ٿ� ĳ���� �Ұ�


			Vir_Parent* Parent_ptr = new Vir_Parent();
			Vir_Child* Child_ptr = new Vir_Child();

			Vir_Parent* static_cast_Parent_ptr = static_cast<Vir_Parent*>(Child_ptr); // �� ĳ���� ����
			Vir_Child* static_cast_Child = static_cast<Vir_Child*>(Parent_ptr); // �ٿ� ĳ���� ���� (����)
		}

		// dynamic_cast �����Լ��� �ϳ��� �����ؼ� ���� ���̺��� �����ȴٸ� �ٿ� ĳ������ ��������
		{   
			Vir_Parent* Parent_ptr = new Vir_Parent();
			Vir_Child* Child_ptr = new Vir_Child();

			Vir_Parent* static_cast_Parent_ptr = dynamic_cast<Vir_Parent*>(Child_ptr); // ��ĳ���� ����
			Vir_Child* static_cast_Child = dynamic_cast<Vir_Child*>(Parent_ptr); // �ٿ� ĳ���� ����
		}
	}
	
}