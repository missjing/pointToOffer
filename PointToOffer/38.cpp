//数字在有序数组中出现的次数。二分查找O(logn)

int getBoundK(int *number, int length, int k, bool isLeft)
{
	int start = 0;
	int end = length - 1;
	while(start <= end)
	{
		int mid = (start + end) / 2;
		if(number[mid] > k)
			end = mid - 1;
		else if(number[mid] < k)
			start = mid + 1;
		else
		{
			if(isLeft)
			{
				if(number[mid - 1] != k || mid == 0)
					return mid;
				else
					end = mid - 1;
			}
			else
			{
				if(number[mid + 1] != k || mid == length - 1)
					return mid;
				else
					start = mid + 1;
			}
		}
	}
}

int getNumOfK(int *number, int length, int k)
{
	if(number == NULL|| length <= 0)
		return 0;
	bool isLeft = true;
	int left = getBoundK(number, length, k, isLeft);
	isLeft = false;
	int right = getBoundK(number, length, k, isLeft);
	return right - left + 1;
}

//int BinarySearch(int *arr, int n, int target)
//{
//	if(arr == NULL || n <= 0)
//		return -1;
//	int i = 0, j = n - 1;
//	while(i <= j)
//	{
//		int mid = (i + j) / 2;
//		if(arr[mid] == target)
//			return mid;
//		else if(arr[mid] > target)
//			j = mid - 1;
//		else
//			i = mid + 1;
//	}
//}