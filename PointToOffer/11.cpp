//要注意base为0且exponet为负时，没有意义，因为这时0被作为底数了；exponet为负数时，是原值的倒数；判断double值是不是为0，不是直接用“==”
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

double powerWithUnsignedExponent(double base, unsigned int absExponent) //可以对指数二分递归来求，提高效率
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