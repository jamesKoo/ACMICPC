/*
2475 - 검증수(https://www.acmicpc.net/problem/2475)

정의
   - 단순 계산 문제

*/

#include <iostream>

using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	
	const int CNT = 5;
	const int DIV = 10;
	int n;
	int vn = 0;

	for (int idx = 0; idx < CNT; idx++)
	{
		cin >> n;
		vn += n*n;
	}

	vn %= DIV;
	cout << vn;


	return 0;
}