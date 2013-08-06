int GetUglyNumber(int index)  //按规律顺序生成，而不是每个数字检验的重复计算
{
	if(index <= 0)
		return 0;
	int* num = new int[index];
	num[0] = 1;
	int nextUglyIndex = 1;
	int *multiply2 = num;
	int *multiply3 = num;
	int *multiply5 = num;
	while(nextUglyIndex < index)
	{
		int m = min(*multiply2 * 2, *multiply3 * 3, *multiply5 * 5);
		num[nextUglyIndex] = m;
		while(*multiply2 * 2 <= num[nextUglyIndex])
			++multiply2;
		while(*multiply3 * 3 <= num[nextUglyIndex])
			++multiply3;
		while(*multiply5 * 5 <= num[nextUglyIndex])
			++multiply5;
		++nextUglyIndex;
	}
	int ugly = num[index - 1];
	delete[] num;
	return ugly;
}

int min(int a, int b, int c)
{
	int m = a < b ? a : b;
	return m < c ? m : c;
}