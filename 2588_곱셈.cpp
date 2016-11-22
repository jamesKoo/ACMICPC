/*
2588 - 곱셈(https://www.acmicpc.net/problem/2588)

정의 - 간단한 계산 문제
   
*/

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	
	
	int num1, num2;
	cin >> num1 >> num2;

	
	for (int pos = 0; pos < 3; pos++)
		cout << num1 * ((num2 / (int)pow(10.0, pos)) % 10) << '\n';
	
	cout << num1 * num2;
		
	return 0;
}