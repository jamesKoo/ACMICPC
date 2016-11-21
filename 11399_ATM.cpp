/*
11399 - ATM(https://www.acmicpc.net/problem/11399)

정의 - 쉬운 그리드 알고리즘 문제
   
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

	vector<int> times(n);
	for (int idx = 0; idx < n; idx++)
		cin >> times[idx];

	sort(times.begin(), times.end());

	int min_time = 0;
	int acc_time = 0;
	for (auto& t : times)
	{
		acc_time += t;
		min_time += acc_time;
	}

	cout << min_time;
	
	return 0;
}