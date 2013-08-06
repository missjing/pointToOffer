
//求数组逆序数，用归并的思想
int inversePairsCore(int *data, int *copy, int start, int end)
{
	if(start >= end)
		return 0;

	int mid = (start + end) / 2;
	int left = inversePairsCore(data, copy, 0, mid);
	int right = inversePairsCore(data, copy, mid + 1, end);
	int i = mid;
	int j = end;
	int copyIndex = end;
	while(i >= start && j >= mid + 1)
	{
		if(data[i] > data[j])
		{
			copy[copyIndex--] = data[i--];
			count += j - mid;
		}
		else
			copy[copyIndex--] = data[j--];
	}
	for(; i >= start; --i)
		copy[copyIndex--] = data[i];
	for(; j >= mid + 1; --j)
		copy[copyIndex--] = data[j];

	return left + right + count;
}

int inversePairs(int *data, int length)
{
	if(data == NULL || length <= 0)
		return 0;
	int *copy = new int[length];
	int count = inversePairsCore(data, copy, 0, length - 1);
	delete[] copy;
	return count;
}

