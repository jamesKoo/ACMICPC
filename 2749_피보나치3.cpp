/*
2749 - 피보나치 3(https://www.acmicpc.net/problem/2749)

정의
- N이 매우 크고, 10^n으로 나눈 나머지로 결과를 출력.

풀이
- 나머지 연산자 특징 : (A + B) % C = (A%C + B%C) % C
- 피사노 주기(Pisano Period) : N % M에서, M > 2 && M == 10^k이면 결과는 15*10^(k-1)의 주기로 반복된다.

*/


#include<iostream>
#include<vector>

using namespace std;

int main()
{
	// Input
	unsigned long long n;
	cin >> n;

	// Calculate a fibonacci
	int M = 1E6;
	int P = 15 * (M / 10);
	
	vector<unsigned long long> f(P + 2);
	f[0] = 0;
	f[1] = 1;

	for (int idx = 2; idx < P; idx++)
	{
		f[idx] = f[idx - 1] + f[idx - 2];
		f[idx] %= M;
	}

	// Output
	cout << f[n % P];

	return 0;
}
