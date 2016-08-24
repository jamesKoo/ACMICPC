/*
1065 - 한수(https://www.acmicpc.net/problem/1065)
*/

#include <cstdio>

int dist(int n)
{
	return ((n / 10) % 10) - (n % 10);
}

int main()
{
	int N;
	scanf("%d", &N);

	int cnt = 0;
	for (int n = 1; n <= N; n++)
	{
		bool bArithProg = true;
		int d = dist(n);
		
		for (int m = n / 10; m >= 10; m /= 10)
		{
			if (dist(m) != d)
			{
				bArithProg = false;
				break;
			}
		}

		if(bArithProg)
			cnt++;
	}

	printf("%d", cnt);
}