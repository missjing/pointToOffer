//两个链表的第一个公共结点，由于单链表每个结点只有一个next指针，所以拓扑结构看起来像Y
//思路一：考虑从后往前，最后一个公共结点就是我们要找的，但是因为单链表的性质，这种后进先出可以借助栈来实现，相当于用空间换时间
//思路二：先遍历两条单链表的长度，然后让长链表先走几步然后保证跟短链表同步
struct ListNode
{
	int m_nKey;
	ListNode* m_pNext;
};

int getListLength(ListNode *head)
{
	int l = 0;
	ListNode *pNode = head;
	while(pNode!= NULL)
	{
		pNode = pNode->m_pNext;
		l++;
	}
	return l;
}
ListNode* findFirstCommonNode(ListNode *head1, ListNode *head2)
{
	if(head1 == NULL || head2 == NULL)
		return 0;
	int length1 = getListLength(head1);
	int length2 = getListLength(head2);
	int lengthDiff = length1 - length2;

	ListNode *pLongList = head1;
	ListNode *pShortList = head2;
	if(lengthDiff < 0)
	{
		pLongList = head2;
		pShortList = head1;
		lengthDiff = head2 - head1;
	}
	for(int i = 0; i < lengthDiff; ++i)
	{
		pLongList = pLongList->m_pNext;
	}
	while(pLongList != NULL && pShortList != NULL && pLongList != pShortList)
	{
		pLongList = pLongList->m_pNext;
		pShortList = pShortList->m_pNext;
	}
	ListNode *commonNode = pLongList;
	return commonNode;

}