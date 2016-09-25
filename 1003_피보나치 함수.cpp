/*
1003 - 피보나치 함수(https://www.acmicpc.net/problem/1003)

정의 : 피보나치 함수에서 0, 1 호출 카운팅.
풀이 
  - 재귀함수로 되어 있는 피보나치 함수에서 기저 함수가 몇 번 호출되는지 카운팅하는 문제.
  - 하지만, 주어진 피보나치 함수를 그대로 사용하면 가끔 시간초과가 발생함.
  - 다이나믹 프로그래밍으로 구현.

*/

#include <cstdio>

using namespace std;

int main()
{
	// Init & Counting
	int count[42] = { 1, 0, 1 };
	for (int idx = 3; idx < 42; idx++)
		count[idx] = count[idx - 2] + count[idx - 1];

	// Input
	int t;
	scanf("%d", &t);

	// Output
	int n;
	while (t--)
	{
		scanf("%d", &n);
		printf("%d %d\n", count[n], count[n + 1]);
	}

	return 0;
}