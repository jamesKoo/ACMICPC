/*
11401 - 이항 계수 3(https://www.acmicpc.net/problem/11401)

정의
- N <= 4,000,000인 큰 크기의 이항 계수 계산.

풀이
- 나머지 연산의 곱셈의 역원 이용
- 페르마의 소정리 : a^m-1 % m = 1
- (a*b)%m = (a%m * b%m) % m
- (a/b)%m = (a%m * b^-1 % m) % m
- b^-1 % m = b^(m-2) % m
- nCr = n!/(r!(n-r)!)
- nCr % m = (n! % m * (r!(n-r)!)^-1 % m) % m
= (n! % m * (r!(n-r)!)^m-2 % m) % m
- Ref Site : http://zetacode.com/math/2016/04/22/modular-multiplicative-inverse.html
https://www.acmicpc.net/blog/view/29
*/

#include<iostream>

using namespace std;

unsigned long long M = 1000000007LL;

unsigned long long f(unsigned long long n)
{
	unsigned long long rst = 1;
	for (int i = 1; i <= n; i++)
	{
		rst *= i;
		rst %= M;
	}

	return rst;
}

unsigned long long pow(unsigned long long base, unsigned long long exp)
{
	unsigned long long rst = 1;
	while (exp > 0) {
		if (exp % 2 != 0) {
			rst *= base;
			rst %= M;
		}
		base *= base;
		base %= M;
		exp /= 2;
	}

	return rst;
}

int main()
{
	ios::sync_with_stdio(false);

	int n, r;
	cin >> n >> r;

	unsigned long long f_n = f(n);
	unsigned long long f_r = f(r);
	unsigned long long f_nr = f(n - r);
	unsigned long long f_rnr = (f_r * f_nr) % M;

	cout << (f_n * (pow(f_rnr, M - 2) % M)) % M;

	return 0;
}
