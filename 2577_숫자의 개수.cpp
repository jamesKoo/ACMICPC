/*
2577 - 숫자의 개수(https://www.acmicpc.net/problem/2577)

최대 입력값  1000 x 1000 x 1000 = 1,000,000,000
    numeric_limits<int>::max() = 2,147,483,647
*/

#include<cstdio>

int main()
{
	// Input
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);

	// Counting
	int abc = a * b * c;
	int cnts[10] = { 0 };

	while (abc != 0)
	{
		cnts[abc % 10]++;
		abc /= 10;
	}

	// Output
	for (auto cnt : cnts)
		printf("%d\n", cnt);
	
	return 0;
}