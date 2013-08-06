//����min������ջ������min��push��pop����O(1)
//���������������һ����Ա���������СԪ���ǲ����ģ���Ϊ�������СԪ�ر�����ջ��ʱ��������Ҫ��С��Ԫ��
//��˿���ʹ��һ������ջ��ÿ�ζ�ѹ�뵱ǰԪ���µ���Сֵ
template <typename T> void StackWithMin<T>::push(const T& value)
{
	m_data.push(value);
	if(m_min.size() == 0 || value < m_min.top())
		m_min.push(value);
	else
		m_min.push(m_min.top());
}