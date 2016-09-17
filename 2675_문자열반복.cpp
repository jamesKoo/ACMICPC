/*
2675 - 문자열 반복(https://www.acmicpc.net/problem/2675)

정의 : 단순히 입력 문자열을 입력 횟수 만큼 반복하여 출력
  
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	int n;
	cin >> n;

	while (n--)
	{
		int r;
		string str;
		cin >> r >> str;

		for (auto ch : str)
		{
			for (int idx = 0; idx < r; idx++)
				cout << ch;
		}

		cout << endl;
	}

	return 0;
}