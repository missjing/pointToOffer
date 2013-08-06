struct ListNode
{
	int m_nValue;
	ListNode* m_pNext;
};

ListNode* findKthToTail(ListNode *pListHead, int k)
{
	if(pListHead == NULL || k <= 0)
		return NULL;
	ListNode *pSlow, *pFast;
	pSlow = pFast = pListHead;
	for(int i = 0; i < k - 1; i++)
	{
		if(pFast->m_pNext != NULL)
			pFast = pFast->m_pNext;
		else
			return NULL;
	}
	while(pFast->m_pNext)
	{
		pSlow = pSlow->m_pNext;
		pFast = pFast->m_pNext;
	}
	return pSlow;
}