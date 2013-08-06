
struct ListNode
{
	int m_nKey;
	ListNode* m_pNext;
};

//����ڲ��ı�����ṹ���������ɴ�β��ͷ��ӡ����
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