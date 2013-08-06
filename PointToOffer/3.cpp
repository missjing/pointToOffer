#include <iostream>
bool findInMatrix(int* matrix, int row, int column, int num) //需要注意的是二维数组的传参
{
	if(matrix == NULL || row <= 0 || column <= 0)
		return false;
	int i = 0;
	int j = column - 1;
	while(i < row && j >= 0)
		{
			int t = matrix[column * i + j];
			if(num == t)
				return true;
			else if(num > t)
				i++;
			else
				j--;
		}
	return false;
}

int main()
{
	int matrix[] = {1, 2, 8, 9,
							2, 4, 9, 12,
							4, 7, 10, 13,
							6, 8, 11, 15};
	int column = 4;
	int row = 4;
	bool f = findInMatrix(matrix, row, column, 7);
	return 0;
}