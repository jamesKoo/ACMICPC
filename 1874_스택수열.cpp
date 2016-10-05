/*
1874 - 스택 수열(https://www.acmicpc.net/problem/1874)

정의 : 스택 자료 구조 특성을 이용하여 수열 만들기.
풀이 : 두 가지 경우로 분리
       - 현재 수가 스택에 넣은 마지막 수와 같거나 큰 경우 -> 현재 수만틈 push하고 pop 수행.
	   - 현재 수가 스택에 넣은 마지막 수보다 작은 경우 -> 수열 만들기 불가능.
*/

#include<cstdio>
#include<stack>
#include<vector>

using namespace std;

class Stack
{
public:
	Stack()
	{
		m_log.reserve(100000);
	}
	void push(int value)
	{
		m_stack.push(value);
		m_log.push_back('+');
	}
	int top()
	{
		return m_stack.empty() ? 0 : m_stack.top();
	}
	void pop()
	{
		m_stack.pop();
		m_log.push_back('-');
	}
	void printLog()
	{
		for (auto &log : m_log)
			printf("%c\n", log);
	}

private:
	stack<int> m_stack;
	vector<char> m_log;
};


int main()
{
	// Input
	int n;
	scanf("%d", &n);

	vector<int> inputs(n);
	for(int idx = 0; idx < n; idx++)
		scanf("%d", &inputs[idx]);
	
	// Operate
	int last = 0;
	Stack stack;

	for (auto& num : inputs)
	{
		if (stack.top() > num)
		{
			printf("NO\n");
			return 0;
		}

		while (last < num)
			stack.push(++last);

		stack.pop();
	}

	// Output
	stack.printLog();
	
	return 0;
}