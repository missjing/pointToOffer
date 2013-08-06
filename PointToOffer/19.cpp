struct BinaryTreeNode
{
	int m_nValue;
	BinaryTreeNode *m_pLeft;
	BinaryTreeNode *m_pRight;
};

//镜像的过程：前序遍历这棵树的每个结点，如果遍历到的结点有子结点，就交换它的两个子结点，当交换完所有非叶子结点的左右子结点后，就得到了树的镜像
void MirrorRecursively(BinaryTreeNode *pNode)
{
	if(pNode == NULL)
		return;
	if(pNode->m_pLeft == NULL && pNode->m_pRight == NULL)
		return;
	ListNode *pTmp = pNode->m_pLeft;
	pNode->m_pLeft = pNode->m_pRight;
	pNode->m_pRight = pTmp;

	if(pNode->m_pLeft)
		MirrorRecursively(pNode->m_pLeft);
	if(pNode->m_pRight)
		MirrorRecursively(pNode->m_pRight);

}