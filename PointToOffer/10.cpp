//首先想法是判断最右一位是否为1，再移位继续判断。
//出现的问题，如果输入是负数，就不能是简单移位这么简单，因为要依旧保证是负数
//解决方案：通过把n与1做与运算，判断n的最低位是不是为1，接着把1左移再判断，即不修改n而是修改mask的思想
int numberOf1(int n)
{
	int count = 0;
	unsigned int flag = 1;
	while(flag)  //循环次数等于整数二进制的位数
	{
		if(n & flag)
			count++;
		flag = flag << 1;
	}
	return count;
}

//解决方案二：把一个整数减去1，再和原整数做与运算，会把该整数最右边的一个1变成0.
//那么一个整数的二进制表示中有多少个1，就可以进行多少次这样的操作
int numberOf1(int n)
{
	int count = 0;
	while(n)
	{
		n = n & (n - 1);
		count++;
	}
	return count;
}