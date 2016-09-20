/*
1193 - 분수찾기(https://www.acmicpc.net/problem/1193)

정의 : 분수가 증가하는 규칙을 찾는 문제
풀이 
  - [1/1], [1/2, 2/1], [3/1, 2/2, 1/3], [1/4, 2/3, 3/2, 4/1]           
  - 1, 2, 3, 4, ...의 묶음으로 증가
  - 각 묶음에서 분자와 분모는 1씩 증가하거나 감소.
  - 입력 X는 몇 번째 묶음에서 몇 번째 인지를 계산.
*/

#include <cstdio>
#include <string>

using namespace std;

int main()
{
	// Input
	int x;
	scanf("%d", &x);

	// Find a step(group)
	int step = 0;
	while (x -= step++, x > step);
	
	// Find a fraction
	int numerator = x;
	int denominator = step - x + 1;

	if (step % 2 != 0)
		swap(numerator, denominator);

	// Output
	printf("%d/%d", numerator, denominator);

	return 0;
}