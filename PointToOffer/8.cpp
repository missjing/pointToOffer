
//快排
//int RandomInRange(int start, int end)
//{
//	return rand() % (end - start);
//}
//
//int partition(int data[], int length, int start, int end)
//{
//	if(data == NULL || length <= 0 || start <0 || end >= length)
//		throw new exception("Invalid Parameters");
//	int index = RandomInRange(start, end);
//	swap(&data[index], &data[end]);
//	int small = start - 1;
//	for(int index = start; index <= end; index++)
//	{
//		if(data[index] < data[end])
//		{
//			small++;
//			if(small != index)
//				swap(&data[small], &data[index]);
//		}
//	}
//	small++;
//	swap(&data[small], &data[end]);
//	return small;
//}
//
//void QuickSort(int data[], int length, int start, int end)
//{
//	if(start == end)
//		return;
//	if(start < end)
//	{
//		int index = partition(data, length, start, end);
//		QuickSort(data, length, start, index - 1);
//		QuickSort(data, length, index + 1, end);
//	}
//}

#include <iostream>
using namespace std;
int minInRotateArray(int data[], int length)
{
	if(data == NULL || length <= 0)
		throw new exception("Invalid parameters.");
	int start = 0;
	int end = length - 1;
	while(end - start != 1)
	{
		int mid = (start + end) / 2;
		if(data[mid] >= data[start])
			start = mid;
		else if(data[mid] <= data[end])
			end = mid;
	}
	return data[end];
}

//上述代码的两个问题：
//问题1、排序数组本身也算一个特殊的旋转数组，那么最小值应该是数组的第一个元素，上述代码对这种情况失效
//解决方法：利用非特殊旋转数组的第一个元素大于等于最后一个元素作为循环判断，并且记录一个初始化为start的全局mid值，修改为如下：
int minInRotateArray2(int data[], int length)
{
	if(data == NULL || length <= 0)
		throw new exception("Invalid parameters.");
	int start = 0;
	int end = length - 1;
	int mid = start;
	while(data[start] >= data[end])
	{
		if(end - start == 1)
		{
			mid = end;
			break;
		}
		mid = (start + end) / 2;
		if(data[mid] >= data[start])
			start = mid;
		else if(data[mid] <= data[end])
			end = mid;
	}
	return data[mid];
}

//问题2、数组中相等元素较多的特例，如{1, 0, 1, 1, 1}与{1, 1, 1, 0, 1}，第一个指针、第二个指针和中间指针都为1，
//这时无法判断中间的数字是位于前面的子数组中还是后面的子数组中，也无法移动指针缩小范围，因此需要顺序查找

int minInRotateArray3(int data[], int length)
{
	if(data == NULL || length <= 0)
		throw new exception("Invalid parameters.");
	int start = 0;
	int end = length - 1;
	int mid = start;
	while(data[start] >= data[end])
	{
		if(end - start == 1)
		{
			mid = end;
			break;
		}
		mid = (start + end) / 2;
		if(data[start] == data[end] && data[mid] == data[end])
			return minInOrder(data, start, end);

		if(data[mid] >= data[start])
			start = mid;
		else if(data[mid] <= data[end])
			end = mid;
	}
	return data[mid];
}

int minInOrder(int data[], int start, int end)
{
	int ret = data[start];
	for(int i = start + 1; i <= end; ++i)
		if(data[i] < ret)
			ret = data[i];

	return ret;
}

//归并排序
//void merge(int*arr, int p, int q, int r)
//{
//	int n1 = q - p + 1;
//	int n2 = r - q;
//
//	int* L = new int[n1];
//	int* R = new int[n2];
//
//	for(int i = 0; i < n1; i++)
//		L[i] = arr[p + i];
//	for(int j = 0; j < n2; j++)
//		R[j] = arr[q + j + 1];
//
//	int i = j = 0; //新数组中左右两部分索引
//	int k = p;     //原数组中索引
//
//	while(i < n1 && j < n2)
//	{
//		if(L[i] <= R[j])
//			arr[k++] = L[i++];
//		else
//			arr[k++] = R[j++];
//	}
//
//	for(; i < n1; i++)
//		arr[k++] = L[i];
//	for(; j < n2; j++)
//		arr[k++] = R[j];
//}
//
//void mergesort(int* arr, int p, int r)
//{
//	int q;
//	if(p < r)
//	{
//		q = (p + r) / 2;
//		mergesort(arr, p, q);
//		mergesort(arr, q + 1, r);
//		merge(arr, p, q, r);
//	}
//}

