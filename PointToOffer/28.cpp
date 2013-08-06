//ȫ���о��Ǵӵ�һ��������ÿ�����ֱ�������������ֽ������ݹ�ʵ��
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

//ȥ�ص�ȫ���У��ӵ�һ��������ÿ�����ֱ�����������ظ����ֵ����ֽ���
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
			if(uniqueNum(pBegin, pch))  //��pBegin��ʼ�������ж���û�и�pch�ظ�������
			{
				swap(*pBegin, *pch);
				permutationUnique(str, pBegin + 1);
				swap(*pBegin, *pch);
			}
		}
	}
}