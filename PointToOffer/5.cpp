
struct ListNode
{
	int m_nKey;
	ListNode* m_pNext;
};

//如何在不改变链表结构的情况下完成从尾到头打印链表
void printListReversingly(ListNode *pHead)
{
	stack<ListNode*> nodes;
	if(pHead == NULL)
		return;
	ListNode* p = pHead;
	while(p)
	{
		nodes.push(p);
		p = p->m_pNext;
	}
	while(!nodes.empty())
	{
		p = nodes.top();
		printf("%d\n",p->m_nKey);
		nodes.pop();
	}
}