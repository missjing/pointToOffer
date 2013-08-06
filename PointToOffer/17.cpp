struct ListNode
{
	int m_nValue;
	ListNode* m_pNext;
};
//用递归实现方便简单，在思考的时候要开阔点
ListNode *merge(ListNode *head1, ListNode *head2)
{
	if(head1 == NULL)
		return head2;
	if(head2 == NULL)
		return head1;
	ListNode *pNewHead = NULL;
	if(head1->m_nValue < head2->m_nValue)
	{
		pNewHead = head1;
		pNewHead->m_pNext = merge(head1->m_pNext, head2);
	}
	else
	{
		pNewHead = head2;
		pNewHead->m_pNext = merge(head1, head2->m_pNext);
	}
	return pNewHead;
}