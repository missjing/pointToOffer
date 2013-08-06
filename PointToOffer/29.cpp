//����һ������partition
//��������ͳ�Ƽ����ļ���
int findMoreThanHalfNum(int *num, int length)
{
	if(num == NULL || length <= 0)
		return 0;
	int ret = num[0];
	int count = 1;
	for(int i = 1; i < length; ++i)
	{
		if(count == 0)
		{
			ret = num[i];
			count = 1;
		}
		else if(num[i] == ret)
			count++;
		else
		{
			count--;
		}
	}
	return ret;
}