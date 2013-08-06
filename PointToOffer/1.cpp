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

//ǰ��ĺ����ڷ����ڴ�֮ǰ����delete�ͷ���ʵ��m_pData���ڴ�
//�����ʱ�ڴ治�㵼��new char�׳��쳣��m_pData���Ǹ���ָ�룬�����ǳ����׵��³������
//һ���÷�����copy-and-swap
CMyString& CMyString::operator =(const CMyString& str)
{
	if(this != &str)
	{
		CMyString strTemp(str);  //����һ������������if��䣬���Զ�����������strTemp.m_pData���ڴ��ͷŵ�
		char* pTemp = strTemp.m_pData; //swap
		strTemp.m_pData = m_pData;
		m_pData = pTemp;
	}
	return *this;
}