/*
11699 - 점화식(https://www.acmicpc.net/problem/13699)

정의 - 점화식 구현 문제(제한시간 5초, 최대 N : 35)
   
*/

#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	
	// Input								
	int N;
	cin >> N;

	// Init
	vector<long long> t(N + 1, 0);
	t[0] = 1;

	// Calculate t(n)
	for (int n = 1; n <= N; n++)
		for (int i = 0; i < n; i++)
			t[n] += t[i] * t[n - 1 - i];


	// Output
	cout << t[N];
		
	
	return 0;
}