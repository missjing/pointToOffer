struct BinaryTreeNode
{
	int m_nValue;
	BinaryTreeNode *m_pLeft;
	BinaryTreeNode *m_pRight;
};
//�����ǹ�����ȱ���һ������ͼ����һ��������Ҫ�õ����С���һ�����ǰ���ʼ��㣨���������Ǹ���㣩�ŵ������С�
//������ÿһ�δӶ��е�ͷ��ȡ��һ����㣬����������֮��Ѵ����ܵ���Ľ�㣨�����������ӽ�㣩�����η�����С�
//�����ظ�����������̣�ֱ�������еĽ��ȫ��������Ϊֹ��
void printBinaryTree(BinaryTreeNode *root)
{
	if(root == NULL)
		return;
	queue<BinaryTreeNode *> queueTreeNode;
	queueTreeNode.push(root);
	while(!queueTreeNode.empty())
	{
		BinaryTreeNode *pNode = queueTreeNode.front();
		queueTreeNode.pop();
		printf("%d ", pNode->m_nValue);

		if(pNode->m_pLeft)
			queueTreeNode.push(pNode->m_pLeft);
		if(pNode->m_pRight)
			queueTreeNode.push(pNode->m_pRight);
	}
};