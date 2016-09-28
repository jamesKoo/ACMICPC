/*
1978 - 소수 찾기(https://www.acmicpc.net/problem/1978)

정의 : 최대 100개의 수(최대값 1,000)에서 소수의 개수를 출력.
풀이 
  - 가장 간단한 방법으로 2부터 N-1까지 나눠보고 안 나눠지면 소수로 판단.
  
*/

#include<cstdio>

int main()
{
	// Input
	int n;
	scanf("%d", &n);
	int cnt = 0;

	// Count primes
	while (n--)
	{
		int num;
		scanf("%d", &num);
		if (num > 1)
		{
			bool bPrime = true;
			for (int i = 2; i < num; i++)
			{
				if (num % i == 0)
				{
					bPrime = false;
					break;
				}
			}
			if (bPrime)
				cnt++;
		}
	}

	// Output
	printf("%d", cnt);
	
	return 0;
}