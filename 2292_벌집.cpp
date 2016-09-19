/*
2292 - 벌집(https://www.acmicpc.net/problem/2292)

정의 : 벌집의 층이 증가하는 규칙을 찾는 문제
풀이 
  - 1, 7, 19, 37, 61, ... 이후 층이 증가
  - 즉, 6, 12, 18, 24, ... 를 더하면서 증가
  - 규칙은 6 * 층순으로 이전의 수에 더함.
  - 1 ~ N 까지의 최소 거리는 층수와 동일
*/

#include <cstdio>
#include <string>

using namespace std;

int main()
{
	// Init
	const int RULE_NUM = 6;
	int room = 1;
	int stair = 0;

	// Input
	int n;
	scanf("%d", &n);

	// Find a stair
	while (n > room)
	{
		stair++;
		room += RULE_NUM * stair;
	}

	// Output
	printf("%d", stair + 1);

	return 0;
}