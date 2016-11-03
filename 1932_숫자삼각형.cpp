/*
1932 - 숫자삼각형(https://www.acmicpc.net/problem/1932)

정의
   - 다이나믹 프로그래밍을 이용하여 최적해(최대값) 계산.

풀이
   - 이미 최대값을 가지는 상태에서 추가적으로 행이 추가 될때 각각 경우의 최대값을 계산.
   - maxCostTbl[n][i] = cost[n][i] + max(maxCostTbl[n-1][i-1], maxCostTbl[n-1][i])
   
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	
	// Input
	int N;
	cin >> N;

	vector<int> cost(N);
	vector<vector<int> > maxCostTbl(N);

	// Initialize zero of max cost table.
	cin >> cost[0];
	maxCostTbl[0].push_back(cost[0]);

	// Input cost and calculate max cost table.
	for (int n = 1; n < N; n++)
	{
		for (int idx = 0; idx <= n; idx++)
			cin >> cost[idx];

		maxCostTbl[n].resize(n + 1);

		maxCostTbl[n][0] = cost[0] + maxCostTbl[n - 1][0];
		maxCostTbl[n][n] = cost[n] + maxCostTbl[n - 1][n - 1];

		for (int idx = 1; idx < n; idx++)
			maxCostTbl[n][idx] = cost[idx] + max(maxCostTbl[n - 1][idx - 1], maxCostTbl[n - 1][idx]);
	}

	// Output
	cout << *max_element(maxCostTbl[N - 1].begin(), maxCostTbl[N - 1].end());

	return 0;
}