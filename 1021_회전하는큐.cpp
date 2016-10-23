/*
1021 - 회전하는 큐(https://www.acmicpc.net/problem/1021)

정의
   - 덱 자료 구조 활용

풀이
   1. 뽑을 려는 수가 큐의 중심보다 왼쪽 또는 오른쪽에 있는지 판단.
   2. 왼쪽에 가까우면 front로 이동, 오른쪽에 가까우면 back으로 이동.

*/


#include<cstdio>
#include<vector>
#include<deque>

using namespace std;
int main()
{
	// Input
	int n, m;
	scanf("%d %d", &n, &m);
	deque<int> deq(n);

	for (int idx = 1; idx <= n; idx++)
		deq[idx - 1] = idx;

	vector<int> pickNums(m);
	for (int idx = 0; idx < m; idx++)
		scanf("%d", &pickNums[idx]);

	// Count operations
	int cnt = 0;
	for (auto pickNum : pickNums)
	{
		int curIdx = find(deq.begin(), deq.end(), pickNum) - deq.begin();
		if (curIdx < (deq.size() / 2 + 1))
		{
			while (deq.front() != pickNum)
			{
				deq.push_back(deq.front());
				deq.pop_front();
				cnt++;
			}
		}
		else
		{
			while (deq.front() != pickNum)
			{
				deq.push_front(deq.back());
				deq.pop_back();
				cnt++;
			}
		}
		deq.pop_front();
	}

	// Output
	printf("%d", cnt);

	return 0;
}
