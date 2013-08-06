bool g_InvalidInput = false;
int findGreatestSumOfSubArray(int *pData, int length)
{
	if(pData == NULL || length <= 0)
	{
		g_InvalidInput  = true;
		return 0;
	}
	int curSum = 0;
	int greatestSum = 0x80000000;
	for(int i = 0; i < length; ++i)
	{
		if(curSum < 0)
			curSum = pData[i];
		else
			curSum += pData[i];
		if(curSum > greatestSum)
			greatestSum = curSum;
	}
	return greatestSum;
}