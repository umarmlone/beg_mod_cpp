

int Add(int* a, int* b)
{
	return (* a + * b);
}

void AddVal(int* a, int* b, int* result)
{
	* result =  * a + * b;
}

void Swap(int* a, int* b)
{
	int temp{ 0 };
	temp = * a;
	*a = *b;
	*b = temp;
}
void Factorial(int* a, int* result)
{

	*result = 1;
	int i{ 1 };
	while(*a >= i)
	{
		* result *= i;
		i++;
	}
}
