const int g_maxNumberLength = 10;
char* g_combine1 = new char[g_maxNumberLength * 2 + 1];
char* g_combine2 = new char[g_maxNumberLength * 2 + 1];

bool compare(const string& s1, const string& s2)
{
	string str1 = s1 + s2;
	string str2 = s2 + s1;
	return str1 < str2;
}
void printMinNumber(int* number, int n)
{
	if(number == NULL || length <= 0)
		return;
	string *pStrArray = new string[n];
	for(int i = 0; i < n; ++i)
	{
		stringstream stream;
		stream << number[i];   //写数据到流
		stream >> pStrArray[i]; //从流中读数据
	}
	sort(pStrArray, pStrArray + n, compare());

	for(int i = 0; i < n; ++i)
		cout << pStrArray[i];
	cout << endl;

	delete[] pStrArray;
}