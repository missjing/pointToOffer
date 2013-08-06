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

//�ж����ǲ���ƽ�������
//ֱ�Ӷ�ÿ�������������������1����⣬���������ظ������ܶࡣ�����Զ����¼��㡣
//˼·�����ú��������ʽ���ڱ�����һ�����֮ǰ���Ǿ��Ѿ���������������������ֻҪ�ڱ���ÿ������ʱ���¼������ȣ��Ϳ���һ�߱���һ���ж�ÿ������ǲ���ƽ��
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