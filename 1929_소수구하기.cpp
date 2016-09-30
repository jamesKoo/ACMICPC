/*
1929 - 소수 구하기(https://www.acmicpc.net/problem/1929)

정의 : 최대 1,000,000까지의 모든 소수 출력
풀이 
  - 에라토스테네스의 체 이용.

*/

#include<cstdio>
#include<vector>
#include<cmath>

using namespace std;

int main()
{
	// Input
	int m, n;
	scanf("%d %d", &m, &n);

	// Calculate primes
	vector<bool> bPrimes(n + 1, true);
	bPrimes[0] = bPrimes[1] = false;

	int sqrtN = sqrt(n);
	for (int i = 2; i <= sqrtN; i++)
	{
		if (bPrimes[i])
		{
			for (int j = i * 2; j <= n; j += i)
				bPrimes[j] = false;
		}
	}

	// Output
	for (int i = m; i <= n; i++)
	{
		if (bPrimes[i])
			printf("%d\n", i);
	}
	return 0;
}
