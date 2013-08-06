//二叉搜索树：Binary Search Tree，或者是一棵空树，或者是具有下列性质的二叉树： 
//若它的左子树不空，则左子树上所有结点的值均小于它的根结点的值； 
//若它的右子树不空，则右子树上所有结点的值均大于它的根结点的值； 它的左、右子树也分别为二叉排序树。
struct BinaryTreeNode
{
	int m_nValue;
	BinaryTreeNode *m_pLeft;
	BinaryTreeNode *m_pRight;
};

bool verifySequenceOfBST(int sequence[], int length)
{
	if(sequence == NULL || length <= 0)
		return false;
	int root = sequence[length - 1];
	int i;
	for(i = 0;i < length - 1 ;++i)
	{
		if(sequence[i] > root)
			break;
	}
	int j = i;
	for( ; j < length - 1; ++j)
	{
		if(sequence[j] < root)
			return false;
	}
	bool left = true;
	if(i > 0)
		left = verifySequenceOfBST(sequence, i);
	bool right = true;
	if(i < length - 1)
		right = verifySequenceOfBST(sequence + i, length - i - 1);
	return (left&&right);

}

//如果面试题是要求处理一颗二叉树的遍历序列，我们可以先找到二叉树的根结点，再基于根节点把整棵树的遍历序列
//拆成左子树对应的子序列和右子树对应的子序列，接下来再递归地处理这两个子序列。