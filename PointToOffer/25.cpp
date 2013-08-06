struct BinaryTreeNode
{
	int m_nValue;
	BinaryTreeNode *m_pLeft;
	BinaryTreeNode *m_pRight;
};

void findPath(BinaryTreeNode *pNode, int curSum, int expectedSum, vector<int>& path)
{
	path.push_back(pNode->m_nValue); //��Ϊ�ڿ����������ӽ�㣬Ҳ����Ĭ�ϸ��ڵ��Ѿ�����·����
	curSum += pNode->m_nValue;
	if(pNode->m_pLeft == NULL && pNode->m_pRight == NULL && curSum == expectedSum)
	{
			for(int i = 0; i < path.size(); ++i)
				printf("%d ", path[i]);
			return;
	}
	if(!pNode->m_pLeft)
		findPath(pNode->m_pLeft, curSum, expectedSum, path);
	if(!pNode->m_pRight)
		findPath(pNode->m_pRight, curSum, expectedSum, path);

	path.pop_back(); //��ǰ�����ʽ����󣬵ݹ麯�����Զ��ص����ĸ���㣬����·����ɾ����ǰ���


}

void findPathInBinaryTree(BinaryTreeNode *root, int expectedSum)
{
	if(root == NULL)
		return;
	vector<int> path;
	findPath(root, 0, expectedSum, path);
}

