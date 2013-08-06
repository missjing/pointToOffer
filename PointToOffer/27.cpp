struct BinaryTreeNode
{
	int m_nValue;
	BinaryTreeNode *m_pLeft;
	BinaryTreeNode *m_pRight;
};
//双向链表和二叉搜索树的结构相似：每个结点有两个指针，分别指向比自己小的一个数和比自己大的一个数
//要使他们等价的工作是：将根节点与左子树最大的结点、右子树最小的结点连接起来
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