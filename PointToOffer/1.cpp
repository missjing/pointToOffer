class CMyString
{
public:
	CMyString(char* pData = NULL);
	CMyString(const CMyString& str);
	~CMyString(void);

private:
	char* m_pData;
};

//write the assignment operator
CMyString& CMyString::operator = (const CMyString& str)
{
	if(this == &str)
		return *this;  //this is a point for the class CMyString(that is a address), str is a object
	delete[] m_pData;
	m_pData = NULL;  //delete the data and make the point NULL
	m_pData = new char[strlen(str.m_pData) + 1];
	strcpy(m_pData, str.m_pData);
	return *this;
}

//前面的函数在分配内存之前先用delete释放了实例m_pData的内存
//如果此时内存不足导致new char抛出异常，m_pData将是个空指针，这样非常容易导致程序崩溃
//一个好方法是copy-and-swap
CMyString& CMyString::operator =(const CMyString& str)
{
	if(this != &str)
	{
		CMyString strTemp(str);  //创建一个副本，出了if语句，会自动调用析构将strTemp.m_pData的内存释放掉
		char* pTemp = strTemp.m_pData; //swap
		strTemp.m_pData = m_pData;
		m_pData = pTemp;
	}
	return *this;
}