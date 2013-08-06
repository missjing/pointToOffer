//Ҫע��baseΪ0��exponetΪ��ʱ��û�����壬��Ϊ��ʱ0����Ϊ�����ˣ�exponetΪ����ʱ����ԭֵ�ĵ������ж�doubleֵ�ǲ���Ϊ0������ֱ���á�==��
bool g_InvalidInput = false;
double Power(double base, int exponent)
{
	if(equal(base, 0.0) && exponent < 0)
	{
		g_InvalidInput = true;
		return 0.0;
	}
	unsigned int absExponent = (unsigned int)exponent;
	if(exponent < 0)
		absExponent = (unsigned int)(-exponent);

	double result = powerWithUnsignedExponent(base, absExponent);
	if(exponent < 0)
		result = 1 / result;

	return result;

}

double powerWithUnsignedExponent(double base, unsigned int absExponent) //���Զ�ָ�����ֵݹ��������Ч��
{
	double result = 0.0;
	for(int i = 1; i <= absExponent; ++i)
		result *= base;
	return result;
}

bool equal(double base, double a)
{
	if((base - a > -0.0000001) && (base - a < 0.0000001))
		return true;
	else 
		return false;

}