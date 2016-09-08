/*
2448 - 별찍기 11(https://www.acmicpc.net/problem/2448)

정의 : 프랙탈 모양의 별찍기
방법 : 재귀 함수 이용
       시작위치인 N-1, N-1부터 위, 왼쪽, 오른쪽으로 반씩 줄어들면서 출력.
*/
#include <stdio.h>

enum {MAX_N = 3072};
char output[MAX_N][MAX_N * 2 - 1];

void draw(int n, int r, int c)
{
	if (n == 3)
	{
		output[r - 2][c] = output[r - 1][c - 1] = output[r - 1][c + 1] = '*';
		output[r][c - 2] = output[r][c - 1] = output[r][c] = output[r][c + 1] = output[r][c + 2] = '*';
		return;
	}

	int m = n >> 1;
	draw(m, r - m, c);
	draw(m, r, c - m);
	draw(m, r, c + m);
}

int main()
{
	// Input
	int n = 0;
	scanf("%d", &n);

	// Init space char
	for (int r = 0; r < n; r++)
		for (int c = 0; c < n * 2 - 1; c++)
			output[r][c] = ' ';

	
	// Draw shape to output array.
	draw(n, n - 1, n - 1);


	// Output
	for (int r = 0; r < n; r++)
	{
		for (int c = 0; c < n * 2 - 1; c++)
		{
			putchar(output[r][c]);
		}
		putchar('\n');
	}
	
	return 0;
}