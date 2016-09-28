/*
2518 - 소수(https://www.acmicpc.net/problem/2581)

정의 : 최대 10,000까지의 소수를 찾아 합과 최소값을 계산.
풀이 
  - 2부터 sqrt(N)까지 나눠보고 안 나눠지면 소수로 판단.
  - n = a*b라고 할 때, min(a, b) <= sqrt(n) 식을 이용.
  
*/

#include<cstdio>
#include<cmath>
#include<limits>
#include<algorithm>

using namespace std;

bool IsPrime(int num)
{
	if (num < 2)
		return false;

	bool bPrime = true;
	int sqrtNum = sqrt(num);

	for (int i = 2; i <= sqrtNum; i++)
	{
		if (num % i == 0)
		{
			bPrime = false;
			break;
		}
	}
	
	return bPrime;
}

int main()
{
	// Input
	int m, n;
	scanf("%d %d", &m, &n);
	
	// Calculate primes
	int sum = 0;
	int min = numeric_limits<int>::max();
	for (int num = m; num <= n; num++)
	{
		if(IsPrime(num))
		{
			sum += num;
			min = std::min(min, num);
		}		
	}	

	// Output
	if (sum)
		printf("%d\n%d", sum, min);
	else
		printf("-1");
	
	return 0;
}