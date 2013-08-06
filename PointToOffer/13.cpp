struct ListNode
{
	int m_nValue;
	ListNode* m_pNext;
};

//O(1)ɾ����㣺�ȸ��ƺ�һ������ֵ����ɾ�����������
//ע��㣺�ڵ�������ɾ��ĳһ���������������裬��1��ɾ���������Ӧ�����ݣ���delete��2����ָ���������ָ����ΪNULL
void DeleteNode(ListNode** pListHead, ListNode* pToBeDeleted)
{
	if(pListHead == NULL || *pListHead == NULL || pToBeDeleted == NULL)
		return;
	ListNode *pDeleteNext = pToBeDeleted->m_pNext;
	if(pDeleteNext)
	{
		ListNode* pNextNext = pDeleteNext->m_pNext;
		pToBeDeleted->m_nValue = pDeleteNext->m_nValue;
		pToBeDeleted->m_pNext = pNextNext;

		delete pDeleteNext;
		pDeleteNext = NULL;
	}
	else if(*pListHead == pToBeDeleted) //����ֻ��һ�����
	{
		delete pToBeDeleted;
		pToBeDeleted = NULL;
		*pListHead = NULL;
	}
	else //ɾ�����Ϊβ���
	{
		ListNode* pPre = *pListHead;
		while(pPre->m_pNext != pToBeDeleted)
			pPre = pPre->m_pNext;
		pPre->m_pNext = NULL;

		delete pToBeDeleted;
		pToBeDeleted = NULL;

	}
}