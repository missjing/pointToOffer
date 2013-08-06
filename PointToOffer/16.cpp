struct ListNode
{
	int m_nValue;
	ListNode* m_pNext;
};

ListNode* reverseList(ListNode* pHead)
{
	if(pHead == NULL)
		return NULL;
	ListNode *reverseHead = NULL;
	ListNode *pPre = NULL, *pCur = pHead;
	while(pCur != NULL)
	{
		ListNode *pNext = pCur->m_pNext;
		if(pNext == NULL)
			reverseHead = pCur;
		pCur->m_pNext = pPre;

		pPre = pCur;
		pCur = pNext;
	}
	return reverseHead;
}