
struct BinaryTreeNode
{
	int m_nValue;
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode* m_pRight;
	BinaryTreeNode(int v):m_nValue(v), m_pLeft(NULL), m_pRight(NULL){}
};

BinaryTreeNode* constructTree(int* preOrder, int* inOrder, int length)
{
	if(preOrder == NULL || inOrder == NULL || length <= 0)
		return NULL;
	return constructTree_aux(preOrder, preOrder + length - 1, inOrder, inOrder + length - 1);
}

BinaryTreeNode* constructTree_aux(int* startPreOrder, int* endPreOrder, int* startInOrder, int* endInOrder)
{
	BinaryTreeNode* root = new BinaryTreeNode(0);
	root->m_nValue = startInOrder[0];
	if(startPreOrder == endPreOrder)  //只剩一个元素时
	{
		if(startInOrder == endInOrder && *startPreOrder ==*startInOrder)
			return root;
		else
			throw std::exception("Invalid input.");
	}
	int* p = startInOrder;
	while(p != endInOrder && *p != startInOrder[0])
		++p;
	if(p == endInOrder && *p != startInOrder[0])
		throw std::exception("Invalid input.");

	int leftLengh = p - startInOrder;
	if(leftLengh > 0)
	{
		root->m_pLeft = constructTree_aux(startPreOrder + 1, startPreOrder + leftLengh, startInOrder, p - 1);
	}
	if(leftLengh < endPreOrder - startPreOrder)
	{
		root->m_pRight = constructTree_aux(startPreOrder + leftLengh + 1, endPreOrder, p + 1, endInOrder);
	}
	return root;
}