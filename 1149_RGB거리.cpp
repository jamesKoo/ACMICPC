/*
1149 - RGB거리(https://www.acmicpc.net/problem/1149)

정의
   - 다이나믹 프로그래밍을 이용하여 최적해 계산.

풀이
   - 이미 최소값을 가지는 상태에서 추가적으로 R, G, B를 각각 선택했을 경우의 최소값을 계산.
   - min_cost[i][R] = cost[i][R] + min(min_cost[i-1][G], min_cost[i-1][B])
     min_cost[i][G] = cost[i][G] + min(min_cost[i-1][R], min_cost[i-1][B])
	 min_cost[i][B] = cost[i][B] + min(min_cost[i-1][R], min_cost[i-1][G])
   
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	enum { R, G, B };

	// Input
	int n;
	cin >> n;

	vector<vector<int> > costTbl(n, vector<int>(3));
	vector<vector<int> > minCostTbl(n, vector<int>(3));

	for (int idx = 0; idx < n; idx++)
	{
		cin >> costTbl[idx][R];
		cin >> costTbl[idx][G];
		cin >> costTbl[idx][B];
	}

	// Initialize min cost table.
	minCostTbl[0][R] = costTbl[0][R];
	minCostTbl[0][G] = costTbl[0][G];
	minCostTbl[0][B] = costTbl[0][B];

	// Calculate min cost table.
	for (int idx = 1; idx < n; idx++)
	{
		minCostTbl[idx][R] = costTbl[idx][R] + min(minCostTbl[idx - 1][G], minCostTbl[idx - 1][B]);
		minCostTbl[idx][G] = costTbl[idx][G] + min(minCostTbl[idx - 1][R], minCostTbl[idx - 1][B]);
		minCostTbl[idx][B] = costTbl[idx][B] + min(minCostTbl[idx - 1][R], minCostTbl[idx - 1][G]);
	}

	// Output
	int minimumCost = min(minCostTbl[n - 1][R], min(minCostTbl[n - 1][G], minCostTbl[n - 1][B]));
	cout << minimumCost;

	return 0;
}