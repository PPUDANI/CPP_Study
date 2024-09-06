
int Add(int _Left, int _Right)
{
	return _Left + _Right;
}

void Add(int _Left, int _Right, int& Res)
{
	Res = _Left + _Right;
}

void Add(int _Left, int _Right, int* Res)
{
	if (Res == nullptr)
	{
		return;
	}
	*Res = _Left + _Right;
}

void Add(int _Left, int _Right, int** Res)
{
	if (Res == nullptr || *Res == nullptr)
	{
		return;
	}

	**Res = _Left + _Right;
}

int main()
{
	int a = 4;
	int b = 6;

	int res1 = Add(a, b);

	int res2;
	Add(a, b, res2);

	int res3;
	int* res3_ptr = nullptr;
	Add(a, b, res3_ptr);

	int res4;
	int* res4_ptr = &res4;
	Add(a, b, &res4_ptr);

}