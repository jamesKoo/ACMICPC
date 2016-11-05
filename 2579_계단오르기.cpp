/*
2579 - 계단 오르기(https://www.acmicpc.net/problem/2579)

정의
   - 다이나믹 프로그래밍을 이용하여 최적해(최대값) 계산.

풀이
   - 이미 최대값을 가지는 상태에서 추가적으로 데이터가 추가 될때 각각 경우의 최대값을 계산.
   - Case1 : 두 계단으로 올라온 경우
             maxScoreTbl[n][0] = score[n] + max(maxCostTbl[n-2][0], maxCostTbl[n-2][1])
   - Case2 : 한 계단으로 올라온 경우
             maxScoreTbl[n][1] = score[n] + score[n-1] + max(maxCostTbl[n-3][0], maxCostTbl[n-3][1])
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	
	// Input
	int n;
	cin >> n;

	vector<int> score(n + 1, 0);
	vector<vector<int> > maxScoreTbl(n + 1, vector<int>(2, 0));
	
	// Initialize max score table.
	for (int idx = 1; idx <= min(n, 2); idx++)
	{
		cin >> score[idx];
		maxScoreTbl[idx][0] = score[idx];
		maxScoreTbl[idx][1] = score[idx] + maxScoreTbl[idx-1][1];
	}
		
	// Input cost and calculate max score table.
	for (int idx = 3; idx <= n; idx++)
	{
		cin >> score[idx];

		maxScoreTbl[idx][0] = score[idx] + max(maxScoreTbl[idx-2][0], maxScoreTbl[idx-2][1]);
		maxScoreTbl[idx][1] = score[idx] + score[idx-1] + max(maxScoreTbl[idx-3][0], maxScoreTbl[idx-3][1]);
	}

	// Output
	cout << max(maxScoreTbl[n][0], maxScoreTbl[n][1]);

	return 0;
}