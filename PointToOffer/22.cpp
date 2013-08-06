bool isPopOrder(const int* pPush, const int* pPop, int nLength)
{
	if(pPush == NULL || pPop == NULL || nLength <= 0)
		return false;
	stack<int> stackData;
	const int* nextPush = pPush;
	const int* nextPop = pPop;
	while(nextPop - pPop < nLength)
	{
		while(stackData.empty() || stackData.top() != *nextPop)
		{
			if(nextPush - pPush == nLength)
				break;
			stackData(*nextPush);
			nextPush++;
		}
		if(stackData.top() != *nextPop)
			break;

		stackData.pop();
		nextPop++;
	}
	if(stackData.empty() && nextPop - pPop == nLength)
		return true;
	return false;

}