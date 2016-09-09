/*
8958 - OX 퀴즈(https://www.acmicpc.net/problem/8958)

정의 : 1차원 배열 연습
방법 : 배열 안을 돌면서 연속된 O의 개수를 셈.
  
*/

#include <iostream>
#include <string>

using namespace std;

int score(string& answer)
{
	int count = 0, total = 0;

	for (auto ch : answer)
	{
		if (ch == 'O')
		{
			count++;
			total += count;
		}
		else 
		{
			count = 0;
		}
	}

	return total;
}

int main()
{
	string answer;
	int N = 0;

	scanf("%d", &N);

	for (int n = 0; n < N; n++)
	{
		cin >> answer;
		cout << score(answer) << endl;
	}

	return 0;
}