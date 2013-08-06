//注意在数组中用两个指针的用法，while的用法（直到找到。。。为止）
//扩展：也可把是否为奇偶这个判断独立出来，可扩展为任何其他条件
void ReorderOddEven(int *pData, unsigned int length)
{
	if(pData == NULL || length <= 0)
		return;
	int *pBegin = pData;
	int *pEnd = pData + length - 1;

	while(pBegin < pEnd)
	{
		while(pBegin < pEnd && (*pBegin & 0x1) != 0)
			pBegin++;
		while(pBegin < pEnd && (*pEnd & 0x1) == 0)
			pEnd--;

		if(pBegin < pEnd)
		{
			int tmp = *pBegin;
			*pBegin = *pEnd;
			*pEnd = tmp;
		}
	}

}