void Add(int a, int b, int& result)
{
	result = a + b;
}
void Factorial(int a, int& result)
{
	int i = 1;
	result = 1;
	while (a >= i )
	{
		result *= i;
		i++;
	}
}
void Swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}