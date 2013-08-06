template<typename T> class CQueue
{
public:
	CQueue(void);
	~CQueue(void);

	void appendTail(const T& node);
	T deleteHead();

private:
	stack<T> stack1;
	stack<T> stack2;
};


template<typename T> void CQueue::appendTail(const T& node)
{
	stack1.push(node);
}

template<typename T> T CQueue::deleteHead()
{
	if(stack2.empty())
	{
		while(!stack1.empty())
		{
			stack2.push(stack1.top());
			stack1.pop();
		}
	}
 if(stack2.empty())
	 throw new exception("queue is empty");

 T head = stack2.top();
 stack2.pop();
 return head;

}