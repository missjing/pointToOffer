#include <iostream>
void replaceBlank(char str[], int maxLength) //ע��ӿں����Ķ��壬���鳤��û�й̶������Ǹ���һ�����̶ȷ�Χ����ô����Ϊ�˷�����ԭ�����滻
{
	if(str == NULL || maxLength <= 0)
		return;
	int blank_num = 0;
	int len = 0;
	int i = 0;
	while(str[i] != '\0')
	{
		len++;
		if(str[i] == ' ')
			blank_num++;
		i++;
	}
	int new_len = len + blank_num * 2;
	if(new_len > maxLength)
		return;
	while(len >= 0)
	{
		if(str[len] != ' ')
		{
			str[new_len] = str[len];
			new_len--;
		}
		else
		{
			str[new_len--] = '0';
			str[new_len--] = '2';
			str[new_len--] = '%';
		}
		len--;
	}
}

int main()
{
	char str[] = "We are happy.";
	int maxLength = 100;
	replaceBlank(str, maxLength);
	return 0;
}