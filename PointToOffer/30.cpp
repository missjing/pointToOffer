//最小的k个数

int partition(int *array, int length, int start, int end)
{
	if(array == NULL || length <= 0 || start < 0 || end >= length || start > end)
		return 0;
	int small = start - 1;
	int x = array[end];
	for(int large = start; large < end; large++)
	{
		if(array[large] < x)
		{
			++small;
			swap(&array[small], &array[large]);
		}
	}
	++small;
	swap(&array[small], &array[end]);
	return small;
}

void getLeastKNumbers(int *input, int n, int *output, int k)
{
	if(input == NULL || k > n || k <= 0 || n <= 0)
		return;
	int start = 0;
	int end = n - 1;
	int index = partition(input, n, start, end);
	while(index != k - 1)
	{
		if(index > k - 1)
		{
			end = index - 1;
			index = partition(input, n, start, end);
		}
		else
		{
			start = index + 1;
			index = partition(input, n, start, end);
		}
	}
	for(int i = 0; i <= index; ++i)
		output[i] = input[i];

}