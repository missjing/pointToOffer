//ע����������������ָ����÷���while���÷���ֱ���ҵ�������Ϊֹ��
//��չ��Ҳ�ɰ��Ƿ�Ϊ��ż����ж϶�������������չΪ�κ���������
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