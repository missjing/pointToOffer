//��������ĵ�һ��������㣬���ڵ�����ÿ�����ֻ��һ��nextָ�룬�������˽ṹ��������Y
//˼·һ�����ǴӺ���ǰ�����һ����������������Ҫ�ҵģ�������Ϊ����������ʣ����ֺ���ȳ����Խ���ջ��ʵ�֣��൱���ÿռ任ʱ��
//˼·�����ȱ�������������ĳ��ȣ�Ȼ���ó��������߼���Ȼ��֤��������ͬ��
struct ListNode
{
	int m_nKey;
	ListNode* m_pNext;
};

int getListLength(ListNode *head)
{
	int l = 0;
	ListNode *pNode = head;
	while(pNode!= NULL)
	{
		pNode = pNode->m_pNext;
		l++;
	}
	return l;
}
ListNode* findFirstCommonNode(ListNode *head1, ListNode *head2)
{
	if(head1 == NULL || head2 == NULL)
		return 0;
	int length1 = getListLength(head1);
	int length2 = getListLength(head2);
	int lengthDiff = length1 - length2;

	ListNode *pLongList = head1;
	ListNode *pShortList = head2;
	if(lengthDiff < 0)
	{
		pLongList = head2;
		pShortList = head1;
		lengthDiff = head2 - head1;
	}
	for(int i = 0; i < lengthDiff; ++i)
	{
		pLongList = pLongList->m_pNext;
	}
	while(pLongList != NULL && pShortList != NULL && pLongList != pShortList)
	{
		pLongList = pLongList->m_pNext;
		pShortList = pShortList->m_pNext;
	}
	ListNode *commonNode = pLongList;
	return commonNode;

}