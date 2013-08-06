long long Fibonacci(unsigned int n)
{
	if(n <= 0)
		return 0;
	 if(n == 1)
		return 1;
	
	 return Fibonacci(n - 1) + Fibonacci(n - 2);
}

//������������⣺�����ظ�����
//�����������ѭ���������ӵ����ϼ���

long long Fibonacci2(unsigned int n)
{
	if(n == 0)
		return 0;
	if(n == 1)
		return 1;
	long long fib1 = 0;
	long long fib2 = 1;
	long long fibn = 0;
	for(unsigned int i = 2; i <= n; ++i)
	{
		fibn = fib1 + fib2;
		fib1 = fib2;
		fib2 = fibn;
	}

	return fibn;
}