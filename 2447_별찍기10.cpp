/*
2447 - 별찍기 10(https://www.acmicpc.net/problem/2447)

정의 : 프랙탈 모양의 별찍기
방법 : 기본 모양을 반복할 때마다 확장.
*/


#include <cstdio>
#include <string>

using namespace std;

#define MAX_N 6561

char output[MAX_N][MAX_N];
char base[MAX_N / 3][MAX_N / 3];

int main()
{
	base[0][0] = '*'; base[0][1] = '*'; base[0][2] = '*';
	base[1][0] = '*'; base[1][1] = ' '; base[1][2] = '*';
	base[2][0] = '*'; base[2][1] = '*'; base[2][2] = '*';

	// Input
	int n;
	scanf("%d", &n);
	

	// Draw shape to output array.
	if (n <= 3)
	{
		for (int r = 0; r < n; r++)
		{
			for (int c = 0; c < n; c++)
			{
				output[r][c] = base[r][c];
			}
		}
	}
	else
	{
		int outputSize = 3;
		int baseSize = 3;
		while (1)
		{
			outputSize *= 3;
			for (int r = 0; r < outputSize; r += baseSize)
			{
				for (int c = 0; c < outputSize; c += baseSize)
				{
					for (int br = 0; br < baseSize; br++)
					{
						for (int bc = 0; bc < baseSize; bc++)
						{
							if (r == baseSize && c == baseSize)
								output[r + br][c + bc] = ' ';
							else
								output[r + br][c + bc] = base[br][bc];
						}
					}
				}
			}

			if (outputSize == n)
				break;

			for (int br = 0; br < outputSize; br++)
			{
				for (int bc = 0; bc < outputSize; bc++)
				{
					base[br][bc] = output[br][bc];
				}
			}

			baseSize = outputSize;
		}
	}

	// Output
	for (int r = 0; r < n; r++)
	{
		for (int c = 0; c < n; c++)
		{
			printf("%c", output[r][c]);
		}
		printf("\n");
	}


	return 0;
}