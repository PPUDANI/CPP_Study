#pragma once




class Iterator
{
public:
	Iterator();
	~Iterator();
};

template <class TYPE>
class MyVector
{
public:
	MyVector()
	{

	}

	MyVector(size_t _Size)
	{
		Size = _Size;
		Capacity = _Size;
		Data = new int[Size];
	}

	MyVector(size_t _Size, TYPE _Eliment)
		: Size(_Size), Capacity(_Size)
	{
		if (Size > 0)
		{
			Data = new int[Size];

			for (int i = 0; i < Size; ++i)
			{
				Data[i] = _Eliment;
			}
		}
	}

	~MyVector()
	{
		delete[] Data;
	}

	TYPE& back()
	{
		return Data[Size - 1];
	}

	void push_back()
	{

	}

	void pop_back()
	{

	}

	void reserve(int _Size)
	{
		if (_Size > 0)
		{
			Size = _Size;
			Data = new int[_Size];
		}
	}

	size_t size()
	{
		return Size;
	}

	TYPE& operator [] (size_t Index)
	{
		return this->Data[Index];
	}

private:
	TYPE* Data;

	size_t Size;
	size_t Capacity;
};