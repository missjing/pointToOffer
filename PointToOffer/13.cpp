struct ListNode
{
	int m_nValue;
	ListNode* m_pNext;
};

//O(1)删除结点：先复制后一个结点的值，再删除，无需遍历
//注意点：在单链表中删除某一个结点包括两个步骤，（1）删除这个结点对应的数据，用delete（2）将指向这个结点的指针置为NULL
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
	else if(*pListHead == pToBeDeleted) //链表只有一个结点
	{
		delete pToBeDeleted;
		pToBeDeleted = NULL;
		*pListHead = NULL;
	}
	else //删除结点为尾结点
	{
		ListNode* pPre = *pListHead;
		while(pPre->m_pNext != pToBeDeleted)
			pPre = pPre->m_pNext;
		pPre->m_pNext = NULL;

		delete pToBeDeleted;
		pToBeDeleted = NULL;

	}
}