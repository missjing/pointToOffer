struct ComplexListNode
{
	int m_nValue;
	ComplexListNode* m_pNext;
	ComplexListNode* m_pSibling;
};

//˼·һ��ֱ�Ӹ���nextָ��ð죬siblingָ����ÿ����Ҫ��λ���ң�ʱ�临�Ӷ�O(n2)
//˼·�������ȸ���ԭʼ�����ÿ�����N������Ӧ��N��;���ø��Ƴ����Ľ���sibling;�ѳ�����������õ����ƺ������
void cloneNode(ComplexListNode* pHead)
{
	ComplexListNode* pNode = pHead;
	while(pNode != NULL)
	{
		ComplexListNode* pCloned = new ComplexListNode();
		pCloned->m_nValue = pNode->m_nValue;
		pCloned->m_pNext = pNode->m_pNext;
		pCloned->m_pSibling = NULL;

		pNode->m_pNext = pCloned;
		pNode = pNode->m_pNext;
	}
}

void connectSiblingNode(ComplexListNode* pHead)
{
	ComplexListNode* pNode = pHead;
	while(pNode != NULL)
	{
		ComplexListNode* pCloned = pNode->m_pNext;
		if(pCloned->m_pSibling != NULL)
			pCloned->m_pSibling = pNode->m_pSibling->m_pNext;
		pNode = pCloned->m_pNext;
	}
}

ComplexListNode* reconnectNode(ComplexListNode* pHead)
{
	ComplexListNode* pClonedHead = NULL;
	ComplexListNode* pNode = pHead;
	ComplexListNode* pClonedNode = NULL;

	if(pNode != NULL)
	{
		pClonedHead = pClonedNode = pHead->m_pNext;
		pNode->m_pNext = pClonedNode->m_pNext;
		pNode = pNode->m_pNext;
	}
	while(pNode != NULL)
	{
		pClonedNode->m_pNext = pNode->m_pNext; //������һ�����
		pClonedNode = pClonedHead->m_pNext; //���¸�������
		pNode->m_pNext = pClonedNode->m_pNext;
		pNode = pNode->m_pNext;
	}
	return pClonedHead;
}
ComplexListNode* Clone(ComplexListNode* head)
{
	cloneNode(head);
	connectSiblingNode(head);
	return reconnectNode(head);
}