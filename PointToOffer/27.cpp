struct BinaryTreeNode
{
	int m_nValue;
	BinaryTreeNode *m_pLeft;
	BinaryTreeNode *m_pRight;
};
//˫������Ͷ����������Ľṹ���ƣ�ÿ�����������ָ�룬�ֱ�ָ����Լ�С��һ�����ͱ��Լ����һ����
//Ҫʹ���ǵȼ۵Ĺ����ǣ������ڵ������������Ľ�㡢��������С�Ľ����������
BinaryTreeNode* convert(BinaryTreeNode* pRootOfTree, BinaryTreeNode* pLastNodeInList)
{
	BinaryTreeNode* head;
	if(pRootOfTree == NULL)
	{
		pLastNodeInList = NULL;
		return NULL;
	}
	if(pRootOfTree->m_pLeft == NULL)
		head = pRootOfTree;
	else
	{
		head = convert(pRootOfTree->m_pLeft, pLastNodeInList);
		pRootOfTree->m_pLeft = pLastNodeInList;
		pLastNodeInList->m_pRight = pRootOfTree;
	}
	if(pRootOfTree->m_pRight == NULL)
		pLastNodeInList = pRootOfTree;
	else
	{
		pRootOfTree->m_pRight = convert(pRootOfTree->m_pRight, pLastNodeInList);
		pRootOfTree->m_pRight->m_pLeft = pRootOfTree;
	}
	return head;

}