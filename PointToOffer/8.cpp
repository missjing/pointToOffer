
//����
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

//����������������⣺
//����1���������鱾��Ҳ��һ���������ת���飬��ô��СֵӦ��������ĵ�һ��Ԫ�أ�����������������ʧЧ
//������������÷�������ת����ĵ�һ��Ԫ�ش��ڵ������һ��Ԫ����Ϊѭ���жϣ����Ҽ�¼һ����ʼ��Ϊstart��ȫ��midֵ���޸�Ϊ���£�
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

//����2�����������Ԫ�ؽ϶����������{1, 0, 1, 1, 1}��{1, 1, 1, 0, 1}����һ��ָ�롢�ڶ���ָ����м�ָ�붼Ϊ1��
//��ʱ�޷��ж��м��������λ��ǰ����������л��Ǻ�����������У�Ҳ�޷��ƶ�ָ����С��Χ�������Ҫ˳�����

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

//�鲢����
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
//	int i = j = 0; //����������������������
//	int k = p;     //ԭ����������
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

