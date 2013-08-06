struct BinaryTreeNode
{
	int m_nValue;
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode* m_pRight;
};

int TreeDepth(BinaryTreeNode* pRoot)
{
	if(pRoot == NULL)
		return 0;
	int left = TreeDepth(pRoot->m_pLeft);
	int right = TreeDepth(pRoot->m_pRight);
	return left > right ? left + 1 : right + 1;
}

//判断树是不是平衡二叉树
//直接对每个结点左右子树相差不超过1做检测，但这样做重复遍历很多。属于自顶向下计算。
//思路二：用后序遍历方式，在遍历到一个结点之前我们就已经遍历了它的左右子树，只要在遍历每个结点的时候记录它的深度，就可以一边遍历一边判断每个结点是不是平衡
bool isBalanced(BinaryTreeNode* pRoot, int* pDepth)
{
	if(pRoot == NULL)
	{
		*pDepth = 0;
		return true;
	}
	int left, right;
	if(isBalanced(pRoot->m_pLeft, &left) && isBalanced(pRoot->m_pRight, &right))
	{
		int diff = left - right;
		if(diff <= 1 && diff >= -1)
		{
			*pDepth = 1 + (left > right ? left : right);
			return true;
		}
	}
	return false;
}
bool isBalanced(BinaryTreeNode* pRoot)
{
	int depth = 0;
	return isBalanced(pRoot, depth);
}