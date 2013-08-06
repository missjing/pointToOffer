struct BinaryTreeNode
{
	int m_nValue;
	BinaryTreeNode *m_pLeft;
	BinaryTreeNode *m_pRight;
};
//不管是广度优先遍历一个有向图还是一棵树，都要用到队列。第一步我们把起始结点（对树而言是根结点）放到队列中。
//接下来每一次从队列的头部取出一个结点，遍历这个结点之后把从它能到达的结点（对树而言是子结点）都依次放入队列。
//我们重复这个遍历过程，直到队列中的结点全部都遍历为止。
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