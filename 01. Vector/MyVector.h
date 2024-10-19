#pragma once

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

	void push_back(TYPE _Val)
	{
		++Size;
		if (Size > Capacity)
		{
			Capacity *= 2;

			TYPE* TempData = new TYPE[Capacity];
			for (int i = 0; i < Size; ++i)
			{
				TempData[i] = Data[i];
			}

			delete[] Data;
			Data = TempData;
		}
		Data[Size - 1] = _Val;
	}

	void pop_back()
	{
		--Size;
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

	size_t capacity()
	{
		return Capacity;
	}

	TYPE& operator [] (size_t Index)
	{
		return this->Data[Index];
	}

	void PrintData()
	{
		std::cout << " ";
		for (int i = 0; i < Size; ++i)
		{
			std::cout << Data[i] << " ";
		}
		std::cout << "\n\n";
	}

	void clear()
	{
		Size = 0;
	}

private:
	TYPE* Data;

	size_t Size;
	size_t Capacity;
};