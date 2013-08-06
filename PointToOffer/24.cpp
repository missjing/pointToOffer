//������������Binary Search Tree��������һ�ÿ����������Ǿ����������ʵĶ������� 
//���������������գ��������������н���ֵ��С�����ĸ�����ֵ�� 
//���������������գ��������������н���ֵ���������ĸ�����ֵ�� ������������Ҳ�ֱ�Ϊ������������
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

//�����������Ҫ����һ�Ŷ������ı������У����ǿ������ҵ��������ĸ���㣬�ٻ��ڸ��ڵ���������ı�������
//�����������Ӧ�������к���������Ӧ�������У��������ٵݹ�ش��������������С�