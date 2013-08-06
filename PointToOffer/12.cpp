//#include <iostream>
//using namespace std;
//
//bool increment(char *number)
//{
//	bool isOverflow = false;
//	int carry = 0;
//	int length = strlen(number);
//	for(int i = length - 1; i >= 0; --i)
//	{
//		int t = number[i] - '0' + carry;
//		if(i == length - 1)
//			t++;
//		carry = t / 10;
//		number[i] = t %10 + '0';
//		if(carry == 0)
//			break;
//	}
//	if(carry == 1)
//	{
//		isOverflow = true;
//	}
//	return isOverflow;
//}
//
//void printNumber(char *number)
//{
//	//��ӡ��С����������ַ���Ϊ��098�������ӡΪ��98��
//	int beginValid = 0;
//	while(number[beginValid] == '0')
//	{
//		beginValid++;
//	}
//	for(int i = beginValid; i < strlen(number); ++i)
//	{
//		printf("%c",number[i]);
//	}
//	printf("\t");
//}
//
//
////Ҫ���Ǵ������⣬�����Ҫ���ַ���ģ��
//void print1ToMaxOfNDigits(int n)
//{
//	if(n <= 0)
//		return;
//	char *number = new char[n+1];
//	memset(number, '0', n);
//	number[n] = '\0';
//
//	while(!increment(number))
//	{
//		printNumber(number);
//	}
//	delete []number;
//}
//
//
//int main()
//{
//	print1ToMaxOfNDigits(39);
//	return 0;
//}



//˼·����ת��Ϊȫ�������⣬nλ����ʮ������ʵ����n����0~9��ȫ���С�ֻ����Ҫע���ڴ�ӡʱ����������ǰ���0���ǲ���ӡ����
void print1ToMaxOfNDigits(int n)
{
	if(n <= 0)
		return;
	char *number = new char[n + 1];
	number[n] = '\0';
	for(int i = 0; i < 10; ++i)
	{
		number[0] = i + '0';
		print1ToMaxOfNDigits_aux(number, n, 0);
	}
	delete []number;
}

void print1ToMaxOfNDigits_aux(char *number, int length, int index)
{
	if(index == length - 1)
	{
		printNumber(number);
		return;
	}
	for(int i = 0; i < 10; ++i)
	{
		number[index + 1] = i + '0';
		print1ToMaxOfNDigits_aux(number, length, index + 1);
	}
}