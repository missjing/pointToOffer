struct BinaryTreeNode
{
	int m_nValue;
	BinaryTreeNode *m_pLeft;
	BinaryTreeNode *m_pRight;
};

void findPath(BinaryTreeNode *pNode, int curSum, int expectedSum, vector<int>& path)
{
	path.push_back(pNode->m_nValue); //因为在考察其左右子结点，也就是默认根节点已经算入路径中
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

	path.pop_back(); //当前结点访问结束后，递归函数将自动回到它的父结点，即在路径上删除当前结点


}

void findPathInBinaryTree(BinaryTreeNode *root, int expectedSum)
{
	if(root == NULL)
		return;
	vector<int> path;
	findPath(root, 0, expectedSum, path);
}

