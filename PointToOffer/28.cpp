//全排列就是从第一个数字起每个数分别与它后面的数字交换，递归实现
void permutation(char* str, char* pBegin)
{
	if(str == NULL || pBegin == NULL)
		return;
	if(*pBegin == '\0')
		printf("%s\n", str);
	else
	{
		for(char* pch = pBegin; *pch != '\0'; pch++)
		{
			swap(*pBegin, *pch);
			permutation(str, pBegin + 1);
			swap(*pBegin, *pch);
		}
	}
}

//去重的全排列：从第一个数字起每个数分别与它后面非重复出现的数字交换
bool uniqueNum(char* pBegin, char* pch)
{
	for(char* c = pBegin; c < pch; c++)
		if(*c == *pch)
			return false;
	return true;
}

void permutationUnique(char* str, char* pBegin)
{
	if(str == NULL || pBegin == NULL)
		return;
	if(*pBegin == '\0')
		printf("%s\n", str);
	else
	{
		for(char *pch = pBegin; *pch != '\0'; pch++)
		{
			if(uniqueNum(pBegin, pch))  //从pBegin开始到结束判断有没有跟pch重复的数字
			{
				swap(*pBegin, *pch);
				permutationUnique(str, pBegin + 1);
				swap(*pBegin, *pch);
			}
		}
	}
}