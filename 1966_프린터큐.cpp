/*

1966 - 프린터 큐(https://www.acmicpc.net/problem/1966)
정의 : 우선 순위 큐 이용
풀이 : 우선 순위 큐 구현

*/

#include<cstdio>
#include<algorithm>
#include<vector>

using namespace std;
class PQueue
{
public:
	int mIdx;
	int cnt = 0;
	vector<int> que;

	void push(int n)
	{
		que.push_back(n);
	}

	bool pop()
	{
		if (isMaxPriority())
		{
			que.erase(que.begin());
			cnt++;

			if (mIdx == 0)
				return false;
		}
		else
		{
			que.push_back(que.front());
			que.erase(que.begin());
		}

		if (--mIdx < 0)
			mIdx = que.size() - 1;

		return true;
	}

	bool isMaxPriority()
	{
		return que.front() == *max_element(que.begin(), que.end());
	}
};

int main()
{
	int caseNum;
	scanf("%d", &caseNum);

	while (caseNum--)
	{
		// Init & Input
		PQueue que;
		int data;
		int n, m;
		scanf("%d %d", &n, &que.mIdx);
	
		for (int idx = 0; idx < n; idx++)
		{
			scanf("%d", &data);
			que.push(data);
		}

		// Pop 'm'
		while (que.pop());
		printf("%d\n", que.cnt);
	}

	return 0;
}
