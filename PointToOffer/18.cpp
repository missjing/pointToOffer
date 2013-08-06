struct BinaryTreeNode
{
	int m_nValue;
	BinaryTreeNode *m_pLeft;
	BinaryTreeNode *m_pRight;
};

//��Ȼ���������õݹ��һ�����⣬ʵ��д�����ܼ�
bool DoesTree1HaveTree2(BinaryTreeNode *node1, BinaryTreeNode *node2)
{
	if(node2 == NULL)
		return true;
	if(node1 == NULL)
		return false;
	if(node1->m_nValue != node2->m_nValue)
		return false;
	return DoesTree1HaveTree2(node1->m_pLeft, node2->m_pLeft) && DoesTree1HaveTree2(node1->m_pRight, node2->m_pRight);
}
bool HasSubtree(BinaryTreeNode *pRoot1, BinaryTreeNode *pRoot2)
{
	bool result = false;
	if(pRoot1 != NULL && pRoot2 != NULL)
	{
		if(pRoot1->m_nValue == pRoot2->m_nValue)
			result = DoesTree1HaveTree2(pRoot1, pRoot2);
		if(!result)
			result = HasSubtree(pRoot1->m_pLeft, pRoot2);
		if(!result)
			result = HasSubtree(pRoot1->m_pRight, pRoot2);
	}
	return result;
}