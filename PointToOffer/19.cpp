struct BinaryTreeNode
{
	int m_nValue;
	BinaryTreeNode *m_pLeft;
	BinaryTreeNode *m_pRight;
};

//����Ĺ��̣�ǰ������������ÿ����㣬����������Ľ�����ӽ�㣬�ͽ������������ӽ�㣬�����������з�Ҷ�ӽ��������ӽ��󣬾͵õ������ľ���
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