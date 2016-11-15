/*
1100 - 하얀 칸(https://www.acmicpc.net/problem/1100)

정의 - 단순 계산 문제
   
*/

#include <iostream>
#include <bitset>

using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	
	
	const char chessboard[8][8] = { {1,0,1,0,1,0,1,0},
							        {0,1,0,1,0,1,0,1},
								    {1,0,1,0,1,0,1,0},
								    {0,1,0,1,0,1,0,1},
								    {1,0,1,0,1,0,1,0},
								    {0,1,0,1,0,1,0,1},
								    {1,0,1,0,1,0,1,0},
								    {0,1,0,1,0,1,0,1 } };
	// Input								
	char chess[8][8] = {0};
	char state;
	for (int r = 0; r < 8; r++)
	{
		for (int c = 0; c < 8; c++)
		{
			cin >> state;
			if (state == 'F')
				chess[r][c] = 1;
		}
	}

	// Count white chess
	int cnt = 0;
	for (int r = 0; r < 8; r++)
		for (int c = 0; c < 8; c++)
			if (chess[r][c] == 1 && chessboard[r][c] == 1)
				cnt++;

	cout << cnt;
	
	return 0;
}