//包含min函数的栈：调用min，push，pop都是O(1)
//分析：若仅仅添加一个成员变量存放最小元素是不够的，因为当这个最小元素被弹出栈的时候，我们需要次小的元素
//因此考虑使用一个辅助栈，每次都压入当前元素下的最小值
template <typename T> void StackWithMin<T>::push(const T& value)
{
	m_data.push(value);
	if(m_min.size() == 0 || value < m_min.top())
		m_min.push(value);
	else
		m_min.push(m_min.top());
}