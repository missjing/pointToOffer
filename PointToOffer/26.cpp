struct ComplexListNode
{
	int m_nValue;
	ComplexListNode* m_pNext;
	ComplexListNode* m_pSibling;
};

//思路一、直接复制next指针好办，sibling指针则每次需要定位查找，时间复杂度O(n2)
//思路二、首先根据原始链表的每个结点N创建对应的N‘;设置复制出来的结点的sibling;把长链拆成两条得到复制后的链表
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
		pClonedNode->m_pNext = pNode->m_pNext; //连接下一个结点
		pClonedNode = pClonedHead->m_pNext; //更新复制链表
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